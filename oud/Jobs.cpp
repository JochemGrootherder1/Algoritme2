#include "Jobs.h"

Job::Job(std::vector<unsigned short> job, unsigned short id):
	id(id), done(0), timeDone(0), timeStarted(0), timeStartedSet(0), callbackTime(0)
{
	unsigned short taskId = 0;
	for(std::vector<unsigned short>::iterator i = job.begin(); i != job.end(); i++)
	{
		unsigned short machine = *i;
		unsigned short duration = *(++i);

		Task task(taskId, duration, machine);
		tasks.push_back(task);
		++taskId;
	}
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

Task Job::getCurrentTask()
{
	if(tasks[currentTask].isDone())
	{
		++currentTask;
	}
	if(currentTask >= tasks.size()){
		done = true;
		return tasks[--currentTask];
	}
	return tasks[currentTask];
}



void Job::calculateTotalTime()
{
	totalTime = 0;
	for(const Task& task: tasks)
	{
		if(!task.isDone()) totalTime += task.getDuration();
	}
	std::cout <<totalTime << std::endl;
	if(done){
		totalTime = 0;
	}

}

unsigned long Job::getTotalTime() const
{
	return totalTime;
}
void Job::setTaskRunning(unsigned short task, bool running) {
	tasks[task].setRunning(running);
}

void Job::setTaskStartTime(unsigned short task, unsigned long long currentTime) {
	tasks[task].setStartTime(currentTime);
}

void Job::setTaskDone(unsigned short task) {
	tasks[task].setDone(true);
}

bool Job::isDone() const {
	return done;
}

unsigned long long Job::getTimeDone() const {
	return timeDone;
}

void Job::setTimeDone(unsigned long long timeDone) {
	if(this->timeDone == 0){
		this->timeDone = timeDone;
	}
}

unsigned long long Job::getTimeStarted() const {
	return timeStarted;
}

void Job::setTimeStarted(unsigned long long timeStarted) {
	if(!timeStartedSet){
		timeStartedSet = true;
		this->timeStarted = timeStarted;
	}
}

unsigned short Job::getId() const {
	return id;
}

unsigned short Job::getCallbackTime() const {
	return callbackTime;
}

void Job::setCallbackTime(unsigned short callbackTime) {
	this->callbackTime = callbackTime;
}
