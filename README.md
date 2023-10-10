# philosophers-42
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

- The project is inspired by the Dining Philosophers problem, which is a classic synchronization and concurrency problem in computer science.

- In the project, you typically have a certain number of "philosophers" (usually represented as threads) sitting around a dining table.

- There are "forks" (or chopsticks) placed between each pair of adjacent philosophers.

- Philosophers alternate between thinking and eating. To eat, a philosopher needs to pick up both forks on their sides simultaneously. Once done eating, they put down the forks.

The challenge is to ensure that philosophers can eat without causing deadlocks, which occurs when they all pick up one fork and are unable to pick up the second fork because it's already in use by another philosopher.

Project Objectives:

- Implement a program that simulates the philosophers and their dining process.

- Ensure that philosophers can safely pick up and release forks without causing deadlocks or resource conflicts.

- Implement proper synchronization mechanisms (e.g., mutex locks, semaphores, or other synchronization primitives) to coordinate access to forks and prevent race conditions.

- Explore different solutions to the Dining Philosophers problem, such as avoiding deadlock, starvation, and achieving fairness.


What are threads?
	Threads in the context of APIs (Application Programming Interfaces) typically refer to threads of execution within a program. Threads are a fundamental concept in multithreading, which is a way to achieve concurrent execution of code in a single process. APIs that deal with threads provide functions and mechanisms for managing and controlling these threads.
