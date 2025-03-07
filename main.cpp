#include <iostream>
#include "mlq.h"

int main() {
    srand(time(0));

    int numProcesses;
    std::cout << "Enter the number of processes: ";
    std::cin >> numProcesses;

    MultilevelQueueScheduling program1;
    program1.initializeProcesses(numProcesses);
    program1.runProcess();
    program1.printDetails();

    return 0;
}
