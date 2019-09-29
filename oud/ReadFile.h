#ifndef READFILE_H_
#define READFILE_H_

#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

#include "JobShop.h"

class ReadFile {
public:
	ReadFile(std::string inputFile);
	virtual ~ReadFile();


private:
	unsigned short readJobs(std::string str, std::regex reg);
	unsigned short readMachines(std::string str, std::regex reg);
	std::vector<std::vector<unsigned short>> configurationToVector(std::string str,
			std::regex reg, unsigned short jobs, unsigned short machines);
	void regexConfiguration(std::string str, std::regex reg);
	std::string inputFile;
};

#endif /* READFILE_H_ */
