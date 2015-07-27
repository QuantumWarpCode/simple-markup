//smpl.cpp

#include "stdafx.hpp"
#include <windows.h>
#include "output.hpp"
#include "spml.hpp"

std::string* SPML::readStringToArray(std::string inString) {
	char temp = intToChar(0);
	std::string* sArray = { "", "" };
	std::string space = " ";
	std::string newline = "\n";
	std::string colon = ":";

	int arrayIndex = 0;
	int stringIndex = 0;

	int i = 0;
	while (i < inString.length()) {
		temp = inString[i];
		if (temp != space[0] && temp != newline[0] && temp != colon[0]) {
			sArray[arrayIndex][stringIndex] = temp;
			stringIndex += 1;
		}
		else if(temp == colon[0]) {
			arrayIndex += 1;
		}
		else if (temp == newline[0]) {
			stringIndex = 0;
			arrayIndex += 1;
		}
	}

	return sArray;
}

char SPML::intToChar(unsigned int number) {
	int letter;
	letter = number;
	return letter;
}