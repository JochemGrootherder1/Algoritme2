#include "Task.h"

Task::Task(unsigned short id, unsigned short duration, unsigned short  machine) :
	id(id), duration(duration) ,machine(machine), done(false), running(false), startTime(0)
{

}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

unsigned short Task::getId() const {
	return id;
}

unsigned short Task::getDuration() const {
	return duration;
}

unsigned short Task::getMachine() const {
	return machine;
}

bool Task::isDone() const {
	return done;
}

void Task::setDone(bool done) {
	this->done = done;
}

bool Task::isRunning() const {
	return running;
}

void Task::setRunning(bool running) {
	this->running = running;
}

unsigned short Task::getStartTime() const {
	return startTime;
}

void Task::setStartTime(unsigned short startTime) {
	this->startTime = startTime;
}
