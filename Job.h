/*
 * Jobs.h
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include "Task.h"

class Job
{
public:
	Job(unsigned short anId, std::vector<unsigned short> aJobList,
			unsigned short anAmountOfMachines);
	Job(const Job& aJob);
	virtual ~Job();

	void calculateTotalDuration();

	unsigned short getMachineId();
	unsigned short getJobDuration();

	unsigned short getId() const;
	unsigned long getCurrentSlack() const;
	unsigned long getEndTime() const;
	void setEndTime(unsigned long endTime);
	unsigned long getStartTime() const;
	void setStartTime(unsigned long startTime);

	void setDone(bool done);
	bool isDone() const;
	bool isBusy() const;
	void setBusy(bool busy);
	unsigned short getAmountOfMachines() const;
	unsigned short getCurrentTask() const;
	bool isStartTimeSet() const;
	const std::vector<Task>& getTaskList() const;
	unsigned short getAmountOfTasks() const;
	unsigned long getTaskEndTime() const;
	void setTaskEndTime(unsigned long taskEndTime);

private:

	unsigned short id;
	unsigned short amountOfMachines;
	unsigned short amountOfTasks;
	std::vector<Task> taskList;
	unsigned long currentSlack;

	bool done;
	bool busy;
	unsigned short currentTask;
	bool startTimeSet;
	unsigned long startTime;
	unsigned long endTime;
	unsigned long taskEndTime;
};

#endif /* JOB_H_ */
