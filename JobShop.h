/*
 * JobShop.h
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <iostream>
#include <algorithm>
#include <map>
#include "Job.h"

class JobShop
{
public:
	JobShop(std::vector<std::vector<unsigned short>> aJobShop, unsigned short anAmountOfJobs, unsigned short anAmountOfMachines);
	virtual ~JobShop();
	void run();
	bool done();
	unsigned long getLowestTime();

private:
	unsigned short amountOfJobs;
	unsigned short amountOfMachines;
	unsigned long currentTime;
	std::vector<Job> jobList;
	std::map<unsigned long, unsigned short> times;
	std::map<unsigned short, bool> machines;
	std::map<unsigned short, bool> jobsDone;
};

#endif /* JOBSHOP_H_ */
