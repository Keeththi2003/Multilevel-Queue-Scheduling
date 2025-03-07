#include "mlq.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

MultilevelQueueScheduling::MultilevelQueueScheduling() {
    queueAvgWaitingTime.resize(4, 0);
    queueAvgTurnaroundTime.resize(4, 0);
    queueProcessCount.resize(4, 0);
    queues.resize(4);
    currentTime = 0;
    quantumRR = 10;
    queueSwitchTime = 20;
}

int MultilevelQueueScheduling::generateBurstTime() {
    return rand() % 25 + 1;
}

void MultilevelQueueScheduling::roundRobin(std::queue<Process>& q) {
    if (!q.empty()) {
        Process p = q.front();
        q.pop();
        int executionTime = std::min(p.remainingTime, quantumRR);
        p.remainingTime -= executionTime;
        currentTime += executionTime;

        if (p.remainingTime > 0) {
            q.push(p);
        } else {
            p.turnaroundTime = currentTime;
            p.waitingTime = p.turnaroundTime - p.burstTime;
            queueAvgWaitingTime[p.priority] += p.waitingTime;
            queueAvgTurnaroundTime[p.priority] += p.turnaroundTime;
            queueProcessCount[p.priority]++;
        }
    }
}

void MultilevelQueueScheduling::shortestJobFirst(std::queue<Process>& q) {
    if (!q.empty()) {
        std::vector<Process> temp;
        while (!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }
        std::sort(temp.begin(), temp.end(), [](Process a, Process b) {
            return a.remainingTime < b.remainingTime;
        });

        Process p = temp[0];
        currentTime += p.remainingTime;
        p.remainingTime = 0;
        p.turnaroundTime = currentTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        queueAvgWaitingTime[p.priority] += p.waitingTime;
        queueAvgTurnaroundTime[p.priority] += p.turnaroundTime;
        queueProcessCount[p.priority]++;

        for (size_t i = 1; i < temp.size(); i++) {
            q.push(temp[i]);
        }
    }
}

void MultilevelQueueScheduling::firstInFirstOut(std::queue<Process>& q) {
    if (!q.empty()) {
        Process p = q.front();
        q.pop();
        currentTime += p.remainingTime;
        p.remainingTime = 0;
        p.turnaroundTime = currentTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        queueAvgWaitingTime[p.priority] += p.waitingTime;
        queueAvgTurnaroundTime[p.priority] += p.turnaroundTime;
        queueProcessCount[p.priority]++;
    }
}

void MultilevelQueueScheduling::runProcess() {
    while (true) {
        bool allQueuesEmpty = true;

        for (int i = 0; i < 4; i++) {
            if (!queues[i].empty()) {
                allQueuesEmpty = false;
                int startTime = currentTime;

                while (currentTime - startTime < queueSwitchTime && !queues[i].empty()) {
                    if (i == 0) {
                        roundRobin(queues[i]);
                    } else if (i == 1 || i == 2) {
                        shortestJobFirst(queues[i]);
                    } else if (i == 3) {
                        firstInFirstOut(queues[i]);
                    }
                }
            }
        }

        if (allQueuesEmpty) {
            break;
        }
    }
}

void MultilevelQueueScheduling::printDetails() {
    for (int i = 0; i < 4; i++) {
        if (queueProcessCount[i] > 0) {
            double avgWaitingTime = queueAvgWaitingTime[i] / queueProcessCount[i];
            double avgTurnaroundTime = queueAvgTurnaroundTime[i] / queueProcessCount[i];
            std::cout << "Queue " << i << " - Average Waiting Time: " << avgWaitingTime
                      << ", Average Turnaround Time: " << avgTurnaroundTime << std::endl;
        }
    }
}

void MultilevelQueueScheduling::initializeProcesses(int numProcesses) {
    std::vector<Process> processes(numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        int burstTime = generateBurstTime();
        int priority;
        std::cout << "Enter queue level (0-3) for process " << i + 1 << ": ";
        std::cin >> priority;

        processes[i] = Process(i + 1, burstTime, priority);
        queues[priority].push(processes[i]);

        std::cout << "Process " << i + 1 << " - Burst Time: " << burstTime << ", Queue Level: " << priority << std::endl;
    }
}
