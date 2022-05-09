#include <math.h>
#include <Windows.h>
#include <iostream>
#include "Memory.h"
#include "Offsets.h"
#include "data.h"
#include "Aimbot.h"
#include "Vector3.h"
#include "const.h"

uintptr_t GetPlayer(int index) {
	return RPM<uintptr_t>(moduledata.moduleBase + dwEntityList + index * 0x10);
}

int GetPlayerHealth(uintptr_t player) {
	return RPM<int>(player + m_iHealth);
}

/* Returns the player location given as a vector3 */
Vector3 GetPlayerLocation(uintptr_t player) {
	return RPM<Vector3>(player + m_vecOrigin);
}

bool DormantCheck(uintptr_t player) {
	return RPM<int>(player + m_bDormant);
}

int GetPlayerTeam(uintptr_t player) {
	return RPM<int>(player + m_iTeamNum);
}
 
bool IsVisible(uintptr_t player) {
	int crosshairId = RPM<int>(cheatdata.localPlayer + m_iCrosshairId);
	int crosshairTeam = GetPlayerTeam(GetPlayer(crosshairId - 1));

	if (crosshairId > 0 && crosshairId < 32) {
		return true;
	}
	return false;
}

class player_info {
private:
	char __pad[0x10];
public:
	char name[32];
};


uintptr_t GetClosestPlayer() {
	uintptr_t Closest = MAXUINT32;
	float closestDist = 10000000000000000.f;
	for (int i = 0; i < 64; i++) {
		uintptr_t player = GetPlayer(i);
		if (config.deathmatch == false) {
			if (GetPlayerTeam(player) != GetPlayerTeam(cheatdata.localPlayer) && DormantCheck(player) == false && player != cheatdata.localPlayer && GetPlayerHealth(player) > 0 && GetPlayerHealth(player) < 101) {
				Vector3 localPlayerPos = GetPlayerLocation(cheatdata.localPlayer);
				Vector3 playerPos = GetPlayerLocation(player);

				int crouchCheck = RPM<bool>(player + m_fFlags) & FL_DUCKING;
				/* If the player is ducked, move the position to aim 45 units up instead of 64 */
				if (crouchCheck == 2) {
					playerPos.z += 45;
				}
				else {
					playerPos.z += 64;
				}
				/* Calclulating the distance between 2 points, https://www.calculatorsoup.com/calculators/geometry-solids/distance-two-points.php */
				if (sqrtf(powf(playerPos.x - localPlayerPos.x, 2) + powf(playerPos.y - localPlayerPos.y, 2) + powf(playerPos.z - localPlayerPos.z, 2)) < closestDist) {
					Closest = player;
					closestDist = sqrtf(powf(playerPos.x - localPlayerPos.x, 2) + powf(playerPos.y - localPlayerPos.y, 2) + powf(playerPos.z - localPlayerPos.z, 2));
				}

			}
		}
		else {
			if (DormantCheck(player) == false && player != cheatdata.localPlayer && GetPlayerHealth(player) > 0 && GetPlayerHealth(player) < 101) {
				Vector3 localPlayerPos = GetPlayerLocation(cheatdata.localPlayer);
				Vector3 playerPos = GetPlayerLocation(player);

				int crouchCheck = RPM<bool>(player + m_fFlags) & FL_DUCKING;
				/* If the player is ducked, move the position to aim 45 units up instead of 64 */
				if (crouchCheck == 2) {
					playerPos.z += 45;
				}
				else {
					playerPos.z += 64;
				}
				/* Calclulating the distance between 2 points, https://www.calculatorsoup.com/calculators/geometry-solids/distance-two-points.php */
				if (sqrtf(powf(playerPos.x - localPlayerPos.x, 2) + powf(playerPos.y - localPlayerPos.y, 2) + powf(playerPos.z - localPlayerPos.z, 2)) < closestDist) {
					Closest = player;
					closestDist = sqrtf(powf(playerPos.x - localPlayerPos.x, 2) + powf(playerPos.y - localPlayerPos.y, 2) + powf(playerPos.z - localPlayerPos.z, 2));
				}

			}
		}
		
	}
	/* No player is found */
	if (Closest == MAXUINT32)
		return 0;
	
	return Closest;
}