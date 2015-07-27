//output.hpp

#pragma once

#ifndef USE_OS_STANDARD
#define USE_OS_STANDARD
#endif

#include "stdafx.hpp"
#include "stdafxGL.hpp"

class Output{
public:
	static void show(void);
	static void hide(void);
	static void end(void);
	static void header(char* text);
	static void log(char* text, char* file_name);
	static void log(const char* text, char* file_name);
	static void log(std::string text, char* file_name);
	static void clear(char* file_name);
	static void criticalError(char* text, int error);
	static void expectedError(char* text, int error);
	static void endNoMessage(void);
	static void systemCommand(int command);
	static char** ExePath(void /*char* relpath*/);
	static std::string Output::readFile(char* filename);
	static std::string Output::readFile(std::string filename);
	//static char* fileStringFix(char* string);
	static std::string fileStringFix(std::string string);
private:
	static int charToInt(char letter);
	static char intToChar(unsigned int number);
};

//This class is incomplete
class SPML{ //SimPlistic Markup Language
public:
	static std::string* readStringToArray(std::string inString);
private:
	static char intToChar(unsigned int number);
};