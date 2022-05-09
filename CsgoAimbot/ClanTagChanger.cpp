#include "Offsets.h"
#include "data.h"
#include "Memory.h"


void setClanTag(char* name) {
	char firstChar = name[0];
	WPM<char>(moduledata.moduleBase + dwRadarBase + dwSetClanTag + dwLocalPlayer, firstChar);
}