/*
 * Task.h
 *
 *  Created on: 25 sep. 2019
 *      Author: Gebruiker
 */

#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
	Task(unsigned short anId, unsigned short aMachineId,
			unsigned short aDuration);
	Task(const Task& aTask);
	virtual ~Task();
	unsigned short getId() const;
	unsigned short getDuration() const;
	unsigned short getMachineId() const;
	bool isDone() const;
	void setDone();

private:
	unsigned short id;
	unsigned short machineId;
	unsigned short duration;
	bool done;
};

#endif /* TASK_H_ */
