#ifndef TASK_H_
#define TASK_H_

#include <iostream>

class Task
{
public:
	Task(unsigned short id, unsigned short duration, unsigned short machine);
	virtual ~Task();
	unsigned short getId() const;
	unsigned short getDuration() const;
	unsigned short getMachine() const;
	bool isDone() const;
	void setDone(bool done = false);
	bool isRunning() const;
	void setRunning(bool running = false);
	unsigned short getStartTime() const;
	void setStartTime(unsigned short startTime = 0);

private:
	unsigned short id;
	unsigned short duration;
	unsigned short machine;
	bool done;
	bool running;
	unsigned short startTime;
};

#endif /* TASK_H_ */
