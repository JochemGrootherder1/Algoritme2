/*
 * JobShop.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#include "JobShop.h"

JobShop::JobShop(std::vector<std::vector<unsigned short>> aJobShop,
		unsigned short anAmountOfJobs, unsigned short anAmountOfMachines) :
		amountOfJobs(anAmountOfJobs), amountOfMachines(anAmountOfMachines)
{
	for (unsigned short i = 0; i < anAmountOfJobs; ++i)
	{
		jobList.push_back(Job(i, aJobShop[i], amountOfMachines));
	}

}

JobShop::~JobShop()
{
// TODO Auto-generated destructor stub
}

void JobShop::run()
{
	std::sort(jobList.begin(), jobList.end(), [](Job& lhs, Job& rhs)
	{
		if(lhs.getCurrentSlack() == rhs.getCurrentSlack())
			{
				return lhs.getId() < rhs.getId();
			}
		return lhs.getCurrentSlack() > rhs.getCurrentSlack();
	});

	if (done())
	{
		std::sort(jobList.begin(), jobList.end(),
				[](const Job& lhs, const Job& rhs)
				{
					return lhs.getId() < rhs.getId();
				});
	}
	for (unsigned short i = 0; i < amountOfMachines; ++i)
	{
		std::cout << jobList[i].getId() << " " << jobList[i].getStartTime()
				<< " " << jobList[i].getEndTime() << std::endl;
	}
}

bool JobShop::done()
{
	for (unsigned short i = 0; i < amountOfMachines; ++i)
	{
		if (!jobList[i].isDone())
		{
			return false;
		}
	}
	return true;
}
