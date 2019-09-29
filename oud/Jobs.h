#ifndef JOBS_H_
#define JOBS_H_

#include <algorithm>
#include <vector>
#include <iostream>


#include "Task.h"

class Job
{
public:
	Job(std::vector<unsigned short> job, unsigned short id);
	virtual ~Job();
	Task getCurrentTask();
	void calculateTotalTime();
	unsigned long getTotalTime() const;
	void setTaskRunning(unsigned short task, bool running);
	void setTaskStartTime(unsigned short task, unsigned long long currentTime);
	void setTaskDone(unsigned short task);
	bool isDone() const;
	unsigned long long getTimeDone() const;
	void setTimeDone(unsigned long long timeDone);
	unsigned long long getTimeStarted() const;
	void setTimeStarted(unsigned long long timeStarted);
	unsigned short getId() const;
	unsigned short getCallbackTime() const;
	void setCallbackTime(unsigned short callbackTime);

private:
	unsigned short id;
	unsigned long totalTime = 0;
	unsigned short currentTask = 0;
	bool done;
	unsigned long long timeDone;
	unsigned long long timeStarted;
	bool timeStartedSet;
	unsigned short callbackTime;

	std::vector<Task> tasks;
};

#endif /* JOBS_H_ */
