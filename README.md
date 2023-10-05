# philosophers-42
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

- The project is inspired by the Dining Philosophers problem, which is a classic synchronization and concurrency problem in computer science.

- In the project, you typically have a certain number of "philosophers" (usually represented as threads) sitting around a dining table.

- There are "forks" (or chopsticks) placed between each pair of adjacent philosophers.

- Philosophers alternate between thinking and eating. To eat, a philosopher needs to pick up both forks on their sides simultaneously. Once done eating, they put down the forks.

The challenge is to ensure that philosophers can eat without causing deadlocks, which occurs when they all pick up one fork and are unable to pick up the second fork because it's already in use by another philosopher.
