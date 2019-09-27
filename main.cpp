#include <iostream>
#include <string>
#include "ReadFile.h"


int main(int argc, char **argv) {
//	unsigned short argumentCount = 2;
//	std::string inputFile = "";
//	if (argc < argumentCount)
//	{
//		std::cout << "please give a name of an input file: " << std::endl;
//		std::cin >> inputFile;
//	}else{
//		inputFile = argv[1];
//	}
//	ReadFile file(inputFile);

	JobShop shop({{4,88,8,68,6,94,5,99,1,67,2,89},
				  {5,72,3,50,6,69,4,75,2,94,8,66},
				  {7,94,2,68,1,61,4,99,3,54,6,75}},3,6);
	shop.run();
return 0;
}



