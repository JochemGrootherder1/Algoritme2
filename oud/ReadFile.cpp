/*
 * ReadFile.cpp
 *
 *  Created on: 13 mrt. 2019
 *      Author: Gebruiker
 */

#include "ReadFile.h"

ReadFile::ReadFile(std::string inputFile) :
		inputFile(inputFile) {
	std::string line;
	std::string string = "";
	std::ifstream myfile(inputFile);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			string += line;
			string += "\n";
		}
		myfile.close();
	} else
		std::cout
				<< "Unable to open file\n"
						"Please make sure that the path towards the file is correct\n"
						"If the file is in the same folder as the executable make sure that the name is correct,"
						" if it is elsewhere make sure the path is correct" << std::endl;

	std::regex regConfiguration(
			"\\n[0-9]+\\s+[0-9]+\\n(([0-9]+\\s+[0-9]+\\s+)+)");
	regexConfiguration(string, regConfiguration);

}

ReadFile::~ReadFile() {
	// TODO Auto-generated destructor stub
}

unsigned short ReadFile::readJobs(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	std::smatch match = *currentMatch;
	return static_cast<unsigned short>(std::stoul(match.str()));
}

unsigned short ReadFile::readMachines(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	currentMatch++;
	std::smatch match = *currentMatch;
	return static_cast<unsigned short>(std::stoul(match.str()));
}

std::vector<std::vector<unsigned short>> ReadFile::configurationToVector(
		std::string str, std::regex reg, unsigned short jobs,
		unsigned short machines) {
	std::vector<std::vector<unsigned short>> jobShop;
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	currentMatch++;
	currentMatch++;
	jobShop.push_back( { jobs, machines });
	for (unsigned short i = 1; i < jobs + 1; ++i) {
		std::vector<unsigned short> job;
		for (unsigned short j = 0; j < machines * 2; ++j) {
			std::smatch match = *currentMatch;
			job.push_back(static_cast<unsigned short>(std::stoi(match.str())));
			currentMatch++;
		}
		jobShop.push_back(job);
		job.erase(job.begin(), job.end());
	}

	return jobShop;
}

void ReadFile::regexConfiguration(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	std::sregex_iterator lastMatch;
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;

		std::regex regJobsAndMachines("\\n[0-9]+\\s+[0-9]+\\n");
		std::regex digitTemplate("[0-9]+");
		std::regex regMachinesAndDurations("");

		unsigned short jobs = readJobs(match.str(), digitTemplate);
		unsigned short machines = readMachines(match.str(), digitTemplate);

		std::vector<std::vector<unsigned short>> jobShop =
				configurationToVector(match.str(), digitTemplate, jobs,
						machines);

		JobShop shop(jobShop);
		shop.run();
		currentMatch++;
		std::cout << std::endl;
	}

}
