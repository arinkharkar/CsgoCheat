#include "Aimbot.h"
#include "data.h"
#include "Memory.h"
#include "Offsets.h"
#include <Windows.h>
#include <iostream>

void SetSkin(int skinId) {
	for (int i = 0; i < 8; i++) {

		DWORD myWeapons = RPM<DWORD>(cheatdata.localPlayer + m_hMyWeapons + i * 0x4) & 0xfff;
		DWORD weaponEntity = RPM<DWORD>(moduledata.moduleBase + dwEntityList + (myWeapons - 1) * 0x10);
		if (weaponEntity == 0) { continue; }
		short weaponID = RPM<short>(weaponEntity + m_iItemDefinitionIndex);

		/* ak */
		if (weaponID == 7) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Neon Rider */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 675);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 0);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}
		

		/* m4a4 */
		if (weaponID == 16) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Howl */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 309);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* m4a1-s */
		if (weaponID == 60) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Howl */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 1001);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* deagle */
		if (weaponID == 1) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Printstream */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 711);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* AWP */
		if (weaponID == 9) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Containment Breach */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 917);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* usp-s */
		if (weaponID == 61) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* neo noir */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 504);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* glock */
		if (weaponID == 4) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* wasteland rebel */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 38);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* cz75 auto */
		if (weaponID == 63) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* xiangliu */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 350);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}


		/* FAMAS */
		if (weaponID == 10) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Comomberation */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 604);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.00001f);
		}

		/* mp9 */
		if (weaponID == 34) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* some red thing */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 33);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* sg553 */
		if (weaponID == 39) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Dark wing */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 955);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}

		/* scout */
		if (weaponID == 40) {
			WPM<int>(weaponEntity + m_iItemIDHigh, -1);
			/* Dragonfire */
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 624);
			WPM<int>(weaponEntity + m_nFallbackStatTrak, 999999);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f);
		}
		
		/* Knife */
		if (weaponID == 41 || weaponID == 42 || weaponID == 59) {
			/*

			DWORD hViewModel = RPM<DWORD>(cheatdata.localPlayer + m_hViewModel) & 0xFFF;
			DWORD viewModelEntity = RPM<DWORD>(moduledata.moduleBase + dwEntityList + (hViewModel - 1) * 0x10);
			for (int j = 0; j < 100; j++)
			std::cout << weaponID << '\n';
			std::cout << "knife\n";
			WPM<int>(viewModelEntity + 0x258, 914);
			WPM<int>(viewModelEntity + m_nViewModelIndex, 914);
			WPM<int>(viewModelEntity + m_iItemIDHigh, -1);
			WPM<int>(m_iEntityQuality + weaponEntity, 3);
			WPM<int>(weaponEntity + m_nFallbackPaintKit, 44);
			WPM<int>(weaponEntity + m_nFallbackSeed, 1);
			WPM<float>(weaponEntity + m_flFallbackWear, 0.0001f); */
		}
	}
}

