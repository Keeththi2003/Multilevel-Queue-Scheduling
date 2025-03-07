# Multilevel Queue Scheduling Simulation

This repository contains a C++ implementation of a **Multilevel Queue Scheduling (MLQ)** algorithm simulation. The simulation demonstrates how different scheduling algorithms manage processes with varying burst times across multiple queues.

## Overview

The simulation divides processes into **four queues**, each implementing a different scheduling algorithm:

- **Queue 0**: Round Robin (**RR**)
- **Queue 1**: Shortest Job First (**SJF**)
- **Queue 2**: Shortest Job First (**SJF**)
- **Queue 3**: First In First Out (**FIFO**)

The program calculates the **average waiting time** and **turnaround time** for each queue and evaluates the performance of each scheduling algorithm.

---

## Files in the Repository

- **`process.h`**: Defines the `Process` class, which represents each process with attributes like `id`, `burstTime`, `remainingTime`, `waitingTime`, `turnaroundTime`, and `priority`.
- **`mlq.h`**: Defines the `MultilevelQueueScheduling` class, which manages the scheduling of processes across the four queues.
- **`mlq.cpp`**: Implements the methods of the `MultilevelQueueScheduling` class, including the scheduling algorithms (**RR, SJF, FIFO**) and the main simulation logic.
- **`main.cpp`**: The main program that initializes the simulation, takes user input for the number of processes, and runs the scheduling simulation.
- **`mlq.pdf`**: A report detailing the implementation, example input/output, and results of the simulation.

---

## How to Run the Simulation

### Prerequisites

Ensure you have the following installed:

- A C++ compiler (e.g., `g++`)
- **CMake** (optional, for building the project)

### Steps to Run

#### 1. Clone the Repository:

```bash
git clone https://github.com/your-username/multilevel-queue-scheduling.git
cd multilevel-queue-scheduling
```
### 2. Compile the  Code

```bash
make all
```
### 3.Run the Code

```bash
make run
```

### 4.Input the Number of Processes

- The program will prompt you to enter the number of processes.
- For each process, you need to specify the queue level (0-3) and the burst time

### 5. View the Results

After running the simulation, the program will output:

- The average waiting time and turnaround time for each queue.
- A performance evaluation of the scheduling algorithms.


### 6. Clean object file after excution

```bash
make clean 
```

## License

This project is open-source under the MIT License.

## Author

- K.Keeththigan
- GitHub: Keeththi2003
- keeththi2003@gmail.com