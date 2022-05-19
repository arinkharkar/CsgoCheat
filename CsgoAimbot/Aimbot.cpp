#pragma warning( disable : 0xC4806)
#include <iostream>
#include <windows.h>
#include <string>
#include <TlHelp32.h>
#include "Draw.h"
#include "Player.h"
#include "Offsets.h"
#include "const.h"
#include "Memory.h"
#include "Aimbot.h"
#include "data.h"
#include "Vector2.h"

const int SCREEN_WIDTH = 1920; const int xhairx = SCREEN_WIDTH / 2;
const int SCREEN_HEIGHT = 1080; const int xhairy = SCREEN_HEIGHT / 2;

float PI = 3.1415f;

cheatData cheatdata = { 0 };
moduleData moduledata = { 0 };
uintptr_t closestEnemy;
struct view_matrix_t {
	float matrix[16];
} vm;

/* Returns any module in csgos base address */
uintptr_t GetModuleBaseAddress(const char* modName)
{
	uintptr_t modBaseAddr = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, moduledata.procId);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				if (!strcmp(modEntry.szModule, modName))
				{
					modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	else {
		std::cout << "invalid handle";
	}
	CloseHandle(hSnap);
	return modBaseAddr;
}

struct mat3x4
{
	float c[3][4];
};

mat3x4 GetBoneMatrix(DWORD EntityPtr, int boneIndex)
{
	DWORD BoneMatrixPtr = RPM<DWORD>(EntityPtr + m_dwBoneMatrix);
	return RPM<mat3x4>(BoneMatrixPtr + (0x30 * boneIndex));
}

Vector3 GetBonePosition(DWORD EntityPtr, int BoneIndex)
{
	DWORD BoneMatrixPtr = RPM<DWORD>(EntityPtr + m_dwBoneMatrix);
	Vector3 bonePos;
	bonePos.x = RPM<float>((BoneMatrixPtr + 0x30) * (BoneIndex + 0x0C));
	bonePos.y = RPM<float>((BoneMatrixPtr + 0x30) * (BoneIndex + 0x1C));
	bonePos.z = RPM<float>((BoneMatrixPtr + 0x30) * (BoneIndex + 0x2C));
	return bonePos;
}


/* Converts a 3d position to a 2d mouse position */
class Vector3 WorldToScreen(const class Vector3 pos, struct view_matrix_t matrix) { //This turns 3D coordinates (ex: XYZ) int 2D coordinates (ex: XY).
	class Vector3 out;
	float _x = matrix.matrix[0] * pos.x + matrix.matrix[1] * pos.y + matrix.matrix[2] * pos.z + matrix.matrix[3];
	float _y = matrix.matrix[4] * pos.x + matrix.matrix[5] * pos.y + matrix.matrix[6] * pos.z + matrix.matrix[7];
	out.z = matrix.matrix[12] * pos.x + matrix.matrix[13] * pos.y + matrix.matrix[14] * pos.z + matrix.matrix[15];

	_x *= 1.f / out.z;
	_y *= 1.f / out.z;

	out.x = SCREEN_WIDTH * .5f;
	out.y = SCREEN_HEIGHT * .5f;

	out.x += 0.5f * _x * SCREEN_WIDTH + 0.5f;
	out.y -= 0.5f * _y * SCREEN_HEIGHT + 0.5f;

	return out;
}


void FindClosestEnemyThread() {
	while (1) {
		closestEnemy = GetClosestPlayer();
	}
}
bool cheatRunning; 


bool isPlayerVisible(uintptr_t player) {
	return true;
}


void RecoilControlThread() {
	while (true) {
		
	}
	
}

void triggerBot() {
	if (GetAsyncKeyState(VK_XBUTTON2)) {  
		int crosshairId = RPM<int>(cheatdata.localPlayer + m_iCrosshairId);
		int crosshairTeam = GetPlayerTeam(GetPlayer(crosshairId - 1));
		int localTeam = GetPlayerTeam(cheatdata.localPlayer);
		Vector3 speed = RPM<Vector3>(m_vecVelocity + cheatdata.localPlayer);

		if (crosshairId > 0 && crosshairId < 32 && localTeam != crosshairTeam && speed.x <= 117.00 && speed.y <= 117.00 && speed.z <= 117.00) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, 0, 0);
			Sleep(150);
		}
	}
}



void startAimbot() {

	/* Starts The Main Aimbot Loop */
	
	uintptr_t _closestEnm = closestEnemy;
	if (GetAsyncKeyState(VK_INSERT) || cheatRunning || GetAsyncKeyState(VK_XBUTTON1)) {
		if (GetAsyncKeyState(VK_INSERT))
		cheatRunning = true;
		//RPM<DWORD> (pClient.modBaseAddr + dwLocalPlayer)

		if (_closestEnm != MAXUINT32 && _closestEnm != 0) {
			
			Vector3 headPos = GetBonePosition(_closestEnm, 8);
			
			std::cout << (headPos - GetPlayerLocation(_closestEnm)).x << '\n';
			std::cout << (headPos - GetPlayerLocation(_closestEnm)).y << '\n';
			std::cout << (headPos - GetPlayerLocation(_closestEnm)).z << '\n';
			Vector3 deltaVec = GetPlayerLocation(_closestEnm) - GetPlayerLocation(cheatdata.localPlayer);

			float dist = deltaVec.GetLength();

			float pitch = -asin(deltaVec.z / dist) * (180/PI);
			float yaw = atan2(deltaVec.y, deltaVec.x) * (180/PI);


			uintptr_t clientState = RPM<DWORD>(moduledata.engineBase + dwClientState);

			if (pitch < -89 || pitch > 89) {
				return;
			}
			if (yaw < -179 || yaw > 179) {
				return;
			}

			WPM<float>(clientState + dwClientState_ViewAngles, pitch);
			WPM<float>(clientState + dwClientState_ViewAngles + sizeof(float), yaw);
			/*vm = RPM<view_matrix_t>(moduledata.moduleBase + dwViewMatrix);

			Vector3 pos = GetPlayerLocation(_closestEnm);

			Vector3 headPos = GetBonePosition(_closestEnm, 8);

			headPos.z -= 64;
			
			Vector3 mousePos = WorldToScreen(headPos, vm);
			if (mousePos.z >= 0.0001f && pos.x != 0 && pos.y != 0) {
				DrawBonePos(ALL_BONES, _closestEnm);

				SetCursorPos((int)mousePos.x, (int)mousePos.y);
			}*/
		}
			
	}
	if (GetAsyncKeyState(VK_END)) {
		cheatRunning = false;
	}
}

void DrawBonePos(uint16_t bone, DWORD entityPtr) {
	if (bone == ALL_BONES) {
		for (int i = 0; i < 100; i++) {
			Vector3 pos = GetBonePosition(entityPtr, i);
			Vector3 mousePos = WorldToScreen(pos, vm);
			DrawChars((int)mousePos.x, (int)mousePos.y, "asdfsdfasd");
		}
	}
}