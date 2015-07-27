//spml.hpp

#pragma once

#include "stdafx.hpp"
#include <windows.h>
#include "output.hpp"

//This class is incomplete
class SPML { //SimPlistic Markup Language
public:
	static std::string* readStringToArray(std::string inString);
private:
	static char intToChar(unsigned int number);
};