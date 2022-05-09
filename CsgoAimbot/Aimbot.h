#pragma once
#include "Vector3.h"
#include <Windows.h>
#include <stdint.h>
#define ALL_BONES -1

void startAimbot();
void FindClosestEnemyThread();
uintptr_t GetModuleBaseAddress(const char* modName);
class Vector3 WorldToScreen(const class Vector3 pos, struct view_matrix_t matrix);
void DrawLine(float StartX, float StartY, float EndX, float EndY);
Vector3 GetBonePosition(DWORD EntityPtr, int BoneIndex);
void triggerBot();
void RecoilControlThread();
void LegitAimbot();
void DrawBonePos(uint16_t bone, DWORD entityPtr);

extern uintptr_t closestEnemy;