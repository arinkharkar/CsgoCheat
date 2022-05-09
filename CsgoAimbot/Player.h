#pragma once
#include <Windows.h>
#include "Vector3.h"
uintptr_t GetPlayer(int index);

int GetPlayerHealth(uintptr_t player);

Vector3 GetPlayerLocation(uintptr_t player);

bool DormantCheck(uintptr_t player);

int GetPlayerTeam(uintptr_t player);

uintptr_t GetClosestPlayer();

bool IsVisible(uintptr_t player);