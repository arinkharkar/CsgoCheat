#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include "data.h"
Config config;

std::vector<std::string> split(const std::string& text, char sep) {
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

void SetData() {
	while (true) {
		const char* FilePath = "data.cfg";
		std::ifstream file(FilePath, _SH_DENYNO);
		std::stringstream strStream;
		//read the file and copy it into the strStream
		strStream << file.rdbuf();
		file.clear();
		//conver the strStream into a string
		std::string data = strStream.str();
		std::vector<std::string> lines = split(data, '\n');

		config.Antiflash = (UINT8)stoi(lines[0]);
		if (lines[1] == "True")
			config.deathmatch = true;
		else
			config.deathmatch = false;
		if (lines[2] == "True")
			config.isAimbot = true;
		else
			config.isAimbot = false;
		if (lines[3] == "True")
			config.isBhop = true;
		else
			config.isBhop = false;
		if (lines[4] == "True")
			config.isLegitAimbot = true;
		else
			config.isLegitAimbot = false;
		if (lines[5] == "True")
			config.isSkinChange = true;
		else
			config.isSkinChange = false;
		if (lines[6] == "True")
			config.isTrigger = true;
		else
			config.isTrigger = false;
		if (lines[7] == "True")
			config.isWallhack = true;
		else
			config.isWallhack = false;
		Sleep(1500);
	}
	
	
}