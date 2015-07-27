//cryptography.cpp

#include "stdafx.hpp"
#include "cryptography.hpp"

int Crypto::charToInt(char letter){
	int number;
	number = letter;
	return number;
}

char Crypto::intToChar(unsigned int number){
	int letter;
	letter = number;
	return letter;
}

char Crypto::binToChar(bool b128, bool b64, bool b32, bool b16, bool b8, bool b4, bool b2, bool b1){
	int result;
	char character;
	result = 0;
	if (b1 = true){
		result = result + 1;
	}
	if (b2 = true){
		result = result + 2;
	}
	if (b4 = true){
		result = result + 4;
	}
	if (b8 = true){
		result = result + 8;
	}
	if (b16 = true){
		result = result + 16;
	}
	if (b32 = true){
		result = result + 32;
	}
	if (b64 = true){
		result = result + 64;
	}
	if (b128 = true){
		result = result + 128;
	}
	character = Crypto::intToChar(result);
	return  character;
}

char Crypto::rBinToChar(bool b1, bool b2, bool b4, bool b8, bool b16, bool b32, bool b64, bool b128){
	int result;
	char character;
	result = 0;
	if (b1 = true){
		result = result + 1;
	}
	if (b2 = true){
		result = result + 2;
	}
	if (b4 = true){
		result = result + 4;
	}
	if (b8 = true){
		result = result + 8;
	}
	if (b16 = true){
		result = result + 16;
	}
	if (b32 = true){
		result = result + 32;
	}
	if (b64 = true){
		result = result + 64;
	}
	if (b128 = true){
		result = result + 128;
	}
	character = Crypto::intToChar(result);
	return  character;
}