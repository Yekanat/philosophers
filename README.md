📌 README for philosophers
# 🍝 philosophers - Dining Philosophers Problem

## 📖 Overview
`philosophers` is a multi-threaded simulation of the Dining Philosophers problem, developed as part of the 42 curriculum.  
It explores the basics of concurrency, thread synchronization, and resource management using mutexes.

## 🎯 Objective
Simulate a group of philosophers who alternate between thinking and eating.  
Each needs two forks (shared resources) to eat, and the program must avoid deadlocks, starvation, and race conditions.

## 🛠️ Technologies
- **Language**: C  
- **Library**: `pthread` (POSIX threads)  
- **Synchronization**: Mutexes  

## 📦 Installation
```bash
git clone https://github.com/Yekanat/philosophers.git
cd philosophers
make
🏗️ Usage
bash
Copy
Edit
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
Example:
bash
Copy
Edit
./philo 5 800 200 200
📂 Project Structure
bash
Copy
Edit
philosophers/
├── src/           # Core logic and thread management
├── includes/      # Header files
├── Makefile
└── README.md
🔐 Key Concepts
Threads: Each philosopher runs in its own thread.

Mutexes: Used to protect shared resources (forks).

Timing: Managed with usleep() and time comparisons.

Deadlock prevention: Implemented with ordered fork grabbing or mutex strategies.

🧠 Bonus Version (if implemented)
Uses semaphores instead of mutexes.

Includes a monitor thread/process.

May use fork() and process control instead of threads.

📜 License
This project is licensed under the MIT License – free to use and modify.

👤 Author
Angelo Thekkanath – GitHub
