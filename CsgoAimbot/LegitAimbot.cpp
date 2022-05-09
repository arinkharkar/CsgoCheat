#include "Player.h"
#include "Aimbot.h"
#include "data.h"
#include "Offsets.h"
#include "Memory.h"
#include "const.h"
#include <math.h>

bool _cheatRunning = false;


struct view_matrix_t {
	float matrix[16];
} __vm;

uintptr_t GetClosestVisiblePlayer(bool teamCheck) {
	uintptr_t Closest = MAXUINT32;
	float closestDist = 10000000000000000.f;
	for (int i = 0; i < 64; i++) {
		uintptr_t player = GetPlayer(i);
		if (teamCheck) {
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
				if (sqrtf(powf(playerPos.x - localPlayerPos.x, 2) + powf(playerPos.y - localPlayerPos.y, 2) + powf(playerPos.z - localPlayerPos.z, 2)) < closestDist && IsVisible(player)) {
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
				if (sqrtf(powf(playerPos.x - localPlayerPos.x, 2) + powf(playerPos.y - localPlayerPos.y, 2) + powf(playerPos.z - localPlayerPos.z, 2)) < closestDist && IsVisible(player)) {
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


void LegitAimbot() {
	uintptr_t _closestEnm = GetClosestVisiblePlayer(true);
	if (GetAsyncKeyState(VK_INSERT) || _cheatRunning || GetAsyncKeyState(VK_XBUTTON1)) {
		if (GetAsyncKeyState(VK_INSERT))
			_cheatRunning = true;
		//RPM<DWORD> (pClient.modBaseAddr + dwLocalPlayer)

		if (_closestEnm != MAXUINT32 && _closestEnm != 0) {

			__vm = RPM<view_matrix_t>(moduledata.moduleBase + dwViewMatrix);

			Vector3 pos = GetPlayerLocation(_closestEnm);

			Vector3 headPos = GetBonePosition(_closestEnm, 8);
			Vector3 mousePos = WorldToScreen(headPos, __vm);
			if (mousePos.z >= 0.0001f && pos.x != 0 && pos.y != 0) {

				SetCursorPos((int)mousePos.x, (int)mousePos.y);
			}
		}

	}
	if (GetAsyncKeyState(VK_END)) {
		_cheatRunning = false;
	}
}