/*
 * Task.cpp
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#include "Task.h"

Task::Task(unsigned short anId, unsigned short aMachineId,
		unsigned short aDuration) :
		id(anId), machineId(aMachineId), duration(aDuration), done(0)
{
	// TODO Auto-generated constructor stub

}

Task::Task(const Task& aTask) :
		id(aTask.getId()), machineId(aTask.getMachineId()), duration(
				aTask.getDuration()), done(aTask.isDone())
{

}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

unsigned short Task::getId() const
{
	return id;
}

unsigned short Task::getDuration() const
{
	return duration;
}

unsigned short Task::getMachineId() const
{
	return machineId;
}

bool Task::isDone() const
{
	return done;
}

void Task::setDone(bool done)
{
	this->done = done;
}
