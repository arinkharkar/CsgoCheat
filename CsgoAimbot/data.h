#include <Windows.h>
#pragma once


struct moduleData {
	uintptr_t moduleBase;
	uintptr_t engineBase;
	SIZE_T radarBase;
	HWND hwnd;
	DWORD procId;
	HANDLE hProcess;
	HDC hdc;
	int closest;
	int width;
	int height;
};

struct Config {
	bool deathmatch;
	bool isAimbot;
	bool isWallhack;
	bool isBhop;
	bool isLegitAimbot;
	UINT8 Antiflash;
	bool isSkinChange;
	bool isTrigger;
};


struct cheatData {
	uintptr_t localPlayer;
	int maxDist;
};

void SetData();
extern cheatData cheatdata;
extern moduleData moduledata;
extern Config config;

