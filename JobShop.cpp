/*
 * JobShop.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#include "JobShop.h"

JobShop::JobShop(std::vector<std::vector<unsigned short>> aJobShop,
		unsigned short anAmountOfJobs, unsigned short anAmountOfMachines) :
		amountOfJobs(anAmountOfJobs), amountOfMachines(anAmountOfMachines), currentTime(
				0)
{
	for (unsigned short i = 0; i < anAmountOfJobs; ++i)
	{
		jobList.push_back(Job(i, aJobShop[i], amountOfMachines));
		jobsDone.insert(std::make_pair(i, false));
	}

	for (unsigned short i = 0; i < amountOfMachines; ++i)
	{
		machines.insert(std::make_pair(i, 0));
	}

}

JobShop::~JobShop()
{
}

void JobShop::run()
{
	while (!done())
	{
		std::cout << "HIER1" << std::endl;
		for (unsigned short i = 0; i < amountOfJobs; ++i)
		{
			std::cout << "HIER2" << std::endl;
			jobList[i].calculateTotalDuration();
		}

		std::cout << "HIER3" << std::endl;
		std::sort(jobList.begin(), jobList.end(), [](Job& lhs, Job& rhs)
		{
			if(lhs.getCurrentSlack() == rhs.getCurrentSlack())
			{
				return lhs.getId() < rhs.getId();
			}
			return lhs.getCurrentSlack() > rhs.getCurrentSlack();
		});

		std::cout << "HIER4" << std::endl;
		for (unsigned short i = 0; i < amountOfJobs; ++i)
		{
			if (!jobList[i].isDone())
			{
				if (!jobList[i].isBusy())
				{
					if (machines[jobList[i].getMachineId()] == false)
					{
						machines[jobList[i].getMachineId()] = true;
						times.insert(std::make_pair(currentTime + jobList[i].getJobDuration(), jobList[i].getId()));
						jobList[i].setBusy(true);
						jobList[i].setStartTime(currentTime);
					}
				}
			}
			else
			{
				jobList[i].setEndTime(currentTime);
				jobsDone[jobList[i].getId()] = true;
			}
		}

		std::cout << "HIER5" << std::endl;
		std::vector<unsigned long> timesToRemove;
		if (currentTime == getLowestTime())
		{
			if (jobList[times[currentTime]].isBusy())
			{
				machines[jobList[times[currentTime]].getMachineId()] = false;
				jobList[times[currentTime]].setBusy(false);
			}

			//Verwijderen van tijden uit times
			for (auto time : times)
			{
				std::cout << time.first << std::endl;
				if (time.first == currentTime)
				{
					timesToRemove.push_back(time.first);
				}
			}
		}

		std::cout << "HIER6" << std::endl;
		currentTime = getLowestTime();
		for (unsigned long time : timesToRemove)
		{
			times.erase(time);
		}

		std::cout << "HIER7" << std::endl;
	}

	std::sort(jobList.begin(), jobList.end(), [](const Job& lhs, const Job& rhs)
	{
		return lhs.getId() < rhs.getId();
	});

	for (unsigned short i = 0; i < amountOfJobs; ++i)
	{
		std::cout << jobList[i].getId() << " " << jobList[i].getStartTime()
				<< " " << jobList[i].getEndTime() << std::endl;
	}
}

unsigned long JobShop::getLowestTime()
{
	unsigned long lowest = 0;
	if (times.size() == 0)
	{
		return currentTime;
	}
	for (auto time : times)
	{
		if (lowest == 0)
			lowest = time.first;
		if (time.first < lowest)
			lowest = time.first;
	}
	return lowest;
}

bool JobShop::done()
{
	for (unsigned short i = 0; i < amountOfJobs; ++i)
	{
		if (!jobsDone[i])
		{
			return false;
		}
	}
	return true;
}
