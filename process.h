#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int priority;

    Process() {
        id = 0;
        burstTime = 0;
        remainingTime = 0;
        waitingTime = 0;
        turnaroundTime = 0;
        priority = 0;
    }

     Process(int id, int burstTime, int priority) {
        this->id = id;
        this->burstTime = burstTime;
        this->remainingTime = burstTime;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
        this->priority = priority;
    }
};

#endif
