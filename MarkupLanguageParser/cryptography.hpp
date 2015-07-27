//cryptography.hpp

#pragma once

#include "stdafx.hpp"

class Crypto{
public:
	static int charToInt(char letter);
	static char intToChar(unsigned int number);
	static char binToChar(bool b128, bool b64, bool b32, bool b16, bool b8, bool b4, bool b2, bool b1);
	static char rBinToChar(bool b1, bool b2, bool b4, bool b8, bool b16, bool b32, bool b64, bool b128);
};