#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include "data.h"
/* Reads Proccess Memory of hProcess */
template<typename T> T RPM(SIZE_T address) {
	T buffer;
	ReadProcessMemory(moduledata.hProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
	return buffer;
}

/* Writes Proccess Memory of hProcess */
template<typename T> void WPM(SIZE_T address, T buffer) {
	WriteProcessMemory(moduledata.hProcess, (LPVOID)address, &buffer, sizeof(buffer), NULL);
}