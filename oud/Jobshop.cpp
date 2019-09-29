#include "JobShop.h"
#include <string>
#include <regex>
#include <algorithm>

JobShop::JobShop(std::vector<std::vector<unsigned short>> jobShop) {
	input = jobShop;
	createJobs(input[0][0]);
	createMachines(input[0][1]);
}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

void JobShop::createJobs(unsigned short aantal) {
	for (int i = 0; i < aantal; ++i) {
		Job job(input[i + 1], i);
		jobs.push_back(job);
	}
}

void JobShop::createMachines(unsigned short aantal) {
	for (int i = 0; i < aantal; ++i) {
		bool machine = false;
		machines.push_back(machine);
	}
}

void JobShop::calculateHighestTime() {
	for (auto& job : jobs) {
		job.calculateTotalTime();
	}
	std::sort(jobs.begin(), jobs.end(), [](Job& lhs, Job& rhs)
	{
		return lhs.getTotalTime() > rhs.getTotalTime();
	});
}

void JobShop::run() {
	while (!areAllJobsDone()) {
		calculateHighestTime();
		for (auto& job : jobs) {
			Task task = job.getCurrentTask();
			if (job.getTotalTime() != 0) {
				if ( !task.isRunning() && checkStatusMachine(task.getMachine())) {
					job.setCallbackTime(currentTime + 1);
				}

				else if ( task.isRunning()|| !checkStatusMachine(task.getMachine())) {
					startTask(job, task.getMachine(), task.getDuration());
					job.setTimeStarted(currentTime);
				}
			}
			if (job.isDone()) {
				job.setTimeDone(currentTime);
				job.setCallbackTime(0);
			}
		}
		currentTime = getLowestCallbackTime();
	}
	std::sort(jobs.begin(), jobs.end(), [](Job& lhs, Job& rhs)
	{
		return lhs.getId() < rhs.getId();
	});
	for (auto& job : jobs) {
		std::cout << job.getId() << " " << job.getTimeStarted() << " "
				<< job.getTimeDone() << std::endl;
	}

}

bool JobShop::checkStatusMachine(unsigned short machine) {
	return machines[machine];
}

void JobShop::startTask(Job& job, unsigned short machine, unsigned short duration) {
	if (!job.getCurrentTask().isRunning()) {
		job.setTaskStartTime(job.getCurrentTask().getId(), currentTime);
		job.setCallbackTime(currentTime + duration);
	}
	job.setTaskRunning(job.getCurrentTask().getId(), true);
	job.getCurrentTask().setRunning(true);
	machines[machine] = true;
	if (currentTime == job.getCallbackTime()) {
		machines[machine] = false;
		job.setTaskRunning(job.getCurrentTask().getId(), false);
		job.setTaskDone(job.getCurrentTask().getId());
	}
}

bool JobShop::areAllJobsDone() {
	for (Job& job : jobs) {
		if (!job.isDone()) {
			return false;
		}
	}
	return true;
}

unsigned long long JobShop::getLowestCallbackTime() {
	unsigned long long lowestotalTime = 0;
	for (Job& job : jobs) {
		if (lowestotalTime == 0) {
			lowestotalTime = job.getCallbackTime();
		}
		if (lowestotalTime > job.getCallbackTime()
				&& job.getCallbackTime() != 0) {
			lowestotalTime = job.getCallbackTime();
		}
	}
	return lowestotalTime;
}
