#include "Offsets.h"
#include "Aimbot.h"
#include "data.h"
#include "Memory.h"

void BunnyHop() {

	BYTE flag = RPM<BYTE>(cheatdata.localPlayer + m_fFlags);
	if (GetAsyncKeyState(VK_SPACE) && flag & (1 << 0)) {
		WPM<DWORD>(moduledata.moduleBase + dwForceJump, 6);
	}
}