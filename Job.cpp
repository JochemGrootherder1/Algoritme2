/*
 * Jobs.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#include "Job.h"

Job::Job(unsigned short anId, std::vector<unsigned short> aJobList,
		unsigned short anAmountOfMachines) :
		id(anId), amountOfMachines(anAmountOfMachines), done(0), busy(0), currentTask(0), startTime(
				0), endTime(0)
{
	for (unsigned short i = 0; i < anAmountOfMachines; ++i)
	{
		unsigned short machineId = aJobList[i];
		unsigned short id = i;
		++i;
		unsigned short duration = aJobList[i];
		taskList.push_back(Task(id, machineId, duration));
	}
	calculateTotalDuration();
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

unsigned short Job::getMachineId()
{
	return taskList[currentTask].getMachineId();
}

unsigned short Job::getJobDuration()
{
	return taskList[currentTask].getDuration();
}

void Job::calculateTotalDuration()
{
	unsigned long totalDuration = 0;
	for (unsigned short i = currentTask; i < amountOfMachines; ++i)
	{
		totalDuration += taskList[i].getDuration();
	}
	currentSlack = totalDuration;
}

unsigned short Job::getId() const
{
	return id;
}

unsigned long Job::getCurrentSlack()
{
	calculateTotalDuration();
	return currentSlack;
}

unsigned long Job::getEndTime() const
{
	return endTime;
}

void Job::setEndTime(unsigned long endTime)
{
	this->endTime = endTime;
}

unsigned long Job::getStartTime() const
{
	return startTime;
}

void Job::setStartTime(unsigned long startTime)
{
	this->startTime = startTime;
}

bool Job::isDone() const
{
	return done;
}

bool Job::isBusy() const
{
	return busy;
}

void Job::setBusy(bool busy)
{
	this->busy = busy;
	if(!busy)
	{
		if(currentTask < amountOfMachines - 1)
		{
			++currentTask;
		}
	}
}

unsigned short Job::getCurrentTask() const
{
	return currentTask;
}

void Job::setCurrentTask(unsigned short currentTask)
{
	this->currentTask = currentTask;
}

const std::vector<Task>& Job::getTaskList() const
{
	return taskList;
}
