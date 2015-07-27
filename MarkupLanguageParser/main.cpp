#include "main.h"

int main(int argc, char argv[]) {
	std::string temp = "";
	std::string newline = "\n";
	std::getline(std::cin, temp);

	temp = Output::fileStringFix(temp);
	
	temp = Output::readFile(temp);

	if (Crypto::charToInt(temp.back()) != Crypto::charToInt(newline[0])) {
		temp += "\n";
	}

	std::cout << Output::ExePath();

	std::string* file;
	file = SPML::readStringToArray(temp);

	std::cout << temp;
	Output::end();
	return 0;
}