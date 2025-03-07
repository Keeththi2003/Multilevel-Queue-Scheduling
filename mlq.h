#ifndef MLQ_H
#define MLQ_H

#include <iostream>
#include <vector>
#include <queue>
#include "process.h"

class MultilevelQueueScheduling {
private:
    std::vector<double> queueAvgWaitingTime;
    std::vector<double> queueAvgTurnaroundTime;
    std::vector<int> queueProcessCount;
    std::vector<std::queue<Process>> queues;
    int currentTime;
    int quantumRR;
    int queueSwitchTime;

public:
    MultilevelQueueScheduling();
    int generateBurstTime();
    void roundRobin(std::queue<Process>& q);
    void shortestJobFirst(std::queue<Process>& q);
    void firstInFirstOut(std::queue<Process>& q);
    void runProcess();
    void printDetails();
    void initializeProcesses(int numProcesses);
};

#endif
