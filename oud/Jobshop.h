#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "Jobs.h"

class JobShop
{
public:
	JobShop(std::vector<std::vector<unsigned short>> jobShop);
	virtual ~JobShop();
	void createMachines(unsigned short aantal);
	void createJobs(unsigned short aantal);
	void calculateHighestTime();
	void run();
	bool checkStatusMachine(unsigned short machine);
	void startTask(Job& job, unsigned short machine, unsigned short duration);
	bool areAllJobsDone();
	unsigned long long getLowestCallbackTime();
private:
	std::vector<bool> machines;
	std::vector<Job> jobs;
	unsigned long long currentTime = 0;
	std::vector< std::vector<unsigned short> > input;

};

#endif /* JOBSHOP_H_ */
