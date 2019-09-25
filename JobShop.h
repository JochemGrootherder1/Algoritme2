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
#include "Job.h"

class JobShop
{
public:
	JobShop(std::vector<std::vector<unsigned short>> aJobShop, unsigned short anAmountOfJobs, unsigned short anAmountOfMachines);
	virtual ~JobShop();
	void run();
	bool done();

private:
	unsigned short amountOfJobs;
	unsigned short amountOfMachines;
	std::vector<Job> jobList;
};

#endif /* JOBSHOP_H_ */
