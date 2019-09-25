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
	virtual ~Job();

	unsigned short getMachineId();
	unsigned short getJobDuration();

	unsigned short getId() const;
	unsigned long getCurrentSlack();
	unsigned long getEndTime() const;
	void setEndTime(unsigned long endTime);
	unsigned long getStartTime() const;
	void setStartTime(unsigned long startTime);
	bool isDone() const;
	bool isBusy() const;
	void setBusy(bool busy);
	unsigned short getCurrentTask() const;
	void setCurrentTask(unsigned short currentTask);
	const std::vector<Task>& getTaskList() const;

private:
	void calculateTotalDuration();

	unsigned short id;
	unsigned short amountOfMachines;
	std::vector<Task> taskList;
	unsigned long currentSlack;

	bool done;
	bool busy;
	unsigned short currentTask;
	unsigned long startTime;
	unsigned long endTime;
};

#endif /* JOB_H_ */
