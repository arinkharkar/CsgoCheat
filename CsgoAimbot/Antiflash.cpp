#include "Offsets.h"
#include "data.h"
#include "Memory.h"

void Antiflash(float level) {
	WPM<float>(cheatdata.localPlayer + m_flFlashMaxAlpha, level);
}