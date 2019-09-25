/*
 * ReadFIle.h
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#ifndef READFILE_H_
#define READFILE_H_

#include <vector>
#include <string>

class ReadFile
{
public:
	ReadFile(const std::string& anInputFile);
	virtual ~ReadFile();

private:
	std::string inputFile;

	unsigned short amountOfJobs;
	unsigned short amountOfMachines;
	std::vector<std::vector<unsigned short>> jobShop;
};

#endif /* READFILE_H_ */
