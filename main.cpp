#include <iostream>
#include <string>
#include "ReadFile.h"


int main(int argc, char **argv) {
	unsigned short argumentCount = 2;
	std::string inputFile = "";
	if (argc < argumentCount)
	{
		std::cout << "please give a name of an input file: " << std::endl;
		std::cin >> inputFile;
	}else{
		inputFile = argv[1];
	}
	ReadFile file(inputFile);
return 0;
}



