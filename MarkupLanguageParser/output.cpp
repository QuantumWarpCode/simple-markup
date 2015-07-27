//output.cpp

#ifndef USE_OS_STANDARD
#define USE_OS_STANDARD
#endif

#include "stdafx.hpp"
#include "stdafxGL.hpp"
#include "output.hpp"

void Output::show()
{
#ifdef _WIN32
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOW);
	return;
#else
	Output::expectedError("No linux equivalent of SW_SHOW", 502);
	return;
#endif
}

void Output::hide()
{
#ifdef _WIN32
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	return;
#else
	Output::expectedError("No linux equivalent of SW_HIDE", 503);
	return;
#endif
}

void Output::end()
{
#ifdef _WIN32
	Output::show();
#endif
#ifdef _MSC_VER
	std::cout << "Press any key to continue..." << std::endl;
	_getch();
	return;
#else
#	ifdef __MINGW32__
	std::cout << "Press any key to continue..." << std::endl;
	_getch();
	return
#	else
	std::cout << "Press the enter key to continue..." << std::endl;
	std::cin.get();
	return;
#	endif
#endif
}

void Output::header(char* text)
{
	std::cout << "=====" << text << "=====" << std::endl;
	return;
}

void Output::log(char* text, char* log)
{
	std::ofstream logfile;
	logfile.open(log + std::string(".log"), std::ios::app);
	logfile << text << std::endl;
	logfile.close();
	return;
}

void Output::log(const char* text, char* log)
{
	std::ofstream logfile;
	logfile.open(log + std::string(".log"), std::ios::app);
	logfile << text << std::endl;
	logfile.close();
	return;
}

void Output::log(std::string text, char* log)
{
	std::ofstream logfile;
	logfile.open(log + std::string(".log"), std::ios::app);
	logfile << text << std::endl;
	logfile.close();
	return;
}

void Output::clear(char* log)
{
	std::ofstream logfile;
	logfile.open(log + std::string(".log"), std::ios::trunc);
	logfile.close();
	return;
}

void Output::criticalError(char* text, int error){
	std::cerr << text << "... Exiting with error code:" << error << std::endl;
	Output::log(text, "CriticalError");
	Output::endNoMessage();
	return;
}

void Output::expectedError(char* text, int error){
	std::cerr << text << "...  Exception with error code:" << error << std::endl;
	Output::log(text, "ExpectedError");
	return;
}

void Output::endNoMessage()
{
#ifdef _WIN32
	Output::show();
#endif
#ifdef _MSC_VER
	_getch();
	return;
#else
#	ifdef __MINGW32__
	_getch();
	return
#	else
	std::cin.get();
	return;
#	endif
#endif
}

void Output::systemCommand(int command)
{
#ifdef __linux__
	if (command == 0){
		std::system("shutdown");
		return;
	}
	else if (command == 1){
		Output::expectedError("No pause command for linux", 501);
		return;
	}
#endif
#ifdef _WIN32
	if (command == 0){
		std::system("shutdown.exe");
		return;
	}
	else if (command == 1){
		std::system("pause");
		return;
	}
#endif
}

/*wchar_t* */ char** Output::ExePath(void /*char* relpath*/) {
	//wchar_t buffer[MAX_PATH];
	//GetModuleFileName(NULL, buffer, MAX_PATH);
	//_fullpath(buffer, relpath);
	/*
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
	*/
	//return buffer;
	char** buffer;
	_get_pgmptr(buffer);
	return buffer;
}

std::string Output::readFile(char* filename) {
	FILE* infile;
	int tempint;
	tempint = fopen_s(&infile, filename, "r");
	if (tempint != 0) {
		std::cout << "Error " << tempint << " when reading file " << filename << std::endl;
		return "Error reading file.";
	}

	boolean loop = true;
	int loops = 0;
	char temptext[2];
	std::string returntext;
	int index = 0;
	int length = 0;

	while (loop) {
		fgets(temptext, 2, infile);
		if (temptext != NULL && std::feof(infile) != 1) {
			if (loops == 0) {
				returntext = temptext;
			}
			else {
				returntext += temptext;
			}
			loops++;
			length++;
		}
		else {
			loop = false;
		}

	}

	fclose(infile);
	return returntext;
}

std::string Output::readFile(std::string filename) {
	FILE* infile;
	int tempint;
	tempint = fopen_s(&infile, filename.c_str(), "r");
	if (tempint != 0) {
		std::cout << "Error " << tempint << " when reading file " << filename << std::endl;
		return "Error reading file.";
	}

	boolean loop = true;
	int loops = 0;
	char temptext[2];
	std::string returntext;
	int index = 0;
	int length = 0;

	while (loop) {
		fgets(temptext, 2, infile);
		if (temptext != NULL && std::feof(infile) != 1) {
			if (loops == 0) {
				returntext = temptext;
			}
			else {
				returntext += temptext;
			}
			loops++;
			length++;
		}
		else {
			loop = false;
		}

	}

	fclose(infile);
	return returntext;
}

/*char* Output::fileStringFix(char* string) {
char* slash = "/";
char* rslash = "\\";

int i = 0;
while (i < string.length()) {
if (Output::charToInt(string[i]) == Output::charToInt(slash[0])) {
string[i] = rslash[0];
}
i++;
}
return string;
}*/

std::string Output::fileStringFix(std::string string) {
	char* slash = "/";
	char* rslash = "\\";
	int rslashI = 92;

	if (string.find_first_of(slash[0]) != 2 && string.find_first_of(rslash[0]) != 2) {
		std::cout << "Appending C:\\ as drive directory." << std::endl;
		std::string newString = "C:\\";
		newString += string;
		string = newString;
	}

	int i = 0;
	while (i < string.length()) {
		if (Output::charToInt(string[i]) == Output::charToInt(slash[0])) {
			string[i] = intToChar(rslashI);
		}
		i++;
	}
	return string;
}

int Output::charToInt(char letter) {
	int number;
	number = letter;
	return number;
}

char Output::intToChar(unsigned int number) {
	int letter;
	letter = number;
	return letter;
}

std::string* SPML::readStringToArray(std::string inString) {
	char temp = intToChar(0);
	//std::string* sArray = { "", "" };
	std::string space = " ";
	std::string newline = "\n";
	std::string colon = ":";

	int arrayIndex = 0;
	int stringIndex = 0;

	int i = 0;
	/*while (i < inString.length()) {
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

	return sArray;*/
	
	std::string* sarray;
	return sarray;
}

char SPML::intToChar(unsigned int number) {
	int letter;
	letter = number;
	return letter;
}