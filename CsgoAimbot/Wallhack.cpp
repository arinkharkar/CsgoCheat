#include <Windows.h>
#include <iostream>
#include "Offsets.h"
#include "data.h"
#include "Player.h"
#include "Memory.h"
#include "Aimbot.h"
#include "Draw.h"

struct view_matrix_t {
	float matrix[16];
} _vm;

void startWallhack() {
	
	for (int i = 0; i < 32; i++) {
		/* Gets The ith entity in the entity list */
		uintptr_t Entity = GetPlayer(i);
		

		if (Entity != cheatdata.localPlayer && DormantCheck(Entity) == false && GetPlayerHealth(Entity) > 0 && GetPlayerHealth(Entity) < 101 && GetPlayerTeam(Entity) != GetPlayerTeam(cheatdata.localPlayer)) {
			_vm = RPM<view_matrix_t>(moduledata.moduleBase + dwViewMatrix);
			Vector3 entityPosCenter = GetPlayerLocation(Entity);
			entityPosCenter.z += 32;
			Vector3 screenPos = WorldToScreen(entityPosCenter, _vm);
			Vector3 entityPosCenterHeight = entityPosCenter;
			/* 72 is the height of a player, we already added 32 so subtracting that will give the remaining value */
			entityPosCenterHeight.z += 72 - 32;
			Vector3 screenPosHeightOffset = WorldToScreen(entityPosCenterHeight, _vm);

			Vector3 entityPosCenterWidth = entityPosCenter;
			/* Players width in csgo is 32, but we only need half that since the x is starting at the center, not the very left */
			entityPosCenterWidth.x += 16;
			Vector3 screenPosWidthOffset = WorldToScreen(entityPosCenterWidth, _vm);
			/* Box around enemy */
			DrawBox((int)screenPos.x, (int)screenPos.y, (int)screenPosHeightOffset.y - (int)screenPos.y, (int)screenPosWidthOffset.x - (int)screenPos.x);


			/* The line should be going to the enemies legs, not the center */
			entityPosCenter.z -= 32;
			screenPos = WorldToScreen(entityPosCenter, _vm);
			Vector3 localPlayerScreenPos = WorldToScreen(GetPlayerLocation(cheatdata.localPlayer), _vm);
			/* Line towards enemy */
			//DrawLine(screenPos.x, screenPos.y, localPlayerScreenPos.x, localPlayerScreenPos.y);
		}
	}
}