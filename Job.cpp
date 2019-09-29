/*
 * Jobs.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#include "Job.h"
#include <iostream>

Job::Job(unsigned short anId, std::vector<unsigned short> aJobList,
		unsigned short anAmountOfMachines) :
		id(anId), amountOfMachines(anAmountOfMachines), amountOfTasks(
				anAmountOfMachines), done(0), busy(0), currentTask(0), startTimeSet(
				0), startTime(0), endTime(0)
{
	for (unsigned short i = 0; i < amountOfTasks * 2; ++i)
	{
		unsigned short machineId = aJobList[i];
		unsigned short id = i/2;
		++i;
		unsigned short duration = aJobList[i];
		taskList.push_back(Task(id, machineId, duration));
	}
	calculateTotalDuration();
}

Job::Job(const Job& aJob) :
		id(aJob.getId()), amountOfMachines(aJob.getAmountOfMachines()), amountOfTasks(
				aJob.getAmountOfTasks()), taskList(aJob.getTaskList()), currentSlack(
				aJob.getCurrentSlack()), done(aJob.isDone()), busy(
				aJob.isBusy()), currentTask(aJob.getCurrentTask()), startTimeSet(
				aJob.isStartTimeSet()), startTime(aJob.getStartTime()), endTime(
				aJob.getEndTime())
{
//	std::cout << __PRETTY_FUNCTION__ << std::endl;
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
	for (unsigned short i = currentTask; i < amountOfTasks; ++i)
	{
		totalDuration += taskList[i].getDuration();
	}
	currentSlack = totalDuration;
//	std::cout << "totalDuration " << totalDuration << "job id " << id <<std::endl;
}

unsigned short Job::getId() const
{
	return id;
}

unsigned long Job::getCurrentSlack() const
{
	return currentSlack;
}

unsigned long Job::getEndTime() const
{
	return endTime;
}

void Job::setEndTime(unsigned long endTime)
{
	if (this->endTime == 0)
	{
		this->endTime = endTime;
	}
	done = true;
}

unsigned long Job::getStartTime() const
{
	return startTime;
}

void Job::setStartTime(unsigned long startTime)
{
	if (!startTimeSet)
	{
		startTimeSet = true;
		this->startTime = startTime;
	}
}

void Job::setDone(bool done)
{
	this->done = done;
}

bool Job::isDone() const
{
	for (unsigned short i = 0; i < amountOfMachines; ++i)
	{
		if (!taskList[i].isDone())
		{
			return false;
		}
	}
//	std::cout << "done" << id << std::endl;
	return true;
}

bool Job::isBusy() const
{
	return busy;
}

void Job::setBusy(bool busy)
{
	this->busy = busy;
	if (!busy)
	{
		taskList[currentTask].setDone();

		if (currentTask < amountOfTasks - 1)
		{
			++currentTask;
		}
	}
}

unsigned short Job::getAmountOfMachines() const
{
	return amountOfMachines;
}

unsigned short Job::getCurrentTask() const
{
	return currentTask;
}

bool Job::isStartTimeSet() const
{
	return startTimeSet;
}

const std::vector<Task>& Job::getTaskList() const
{
	return taskList;
}

unsigned short Job::getAmountOfTasks() const
{
	return amountOfTasks;
}

