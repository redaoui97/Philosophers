# Philosophers (42's common core project)
### key words
Lock in multi processes system ;Dead lock ;Atomic locking mechanism; Data race;mutexes;semaphores; state variables; Time since last philo ate
## Introduction 
This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.
The dining philosphers is an example problem often used in concurrent (The ability of different parts of a program to be executed in a partial order without affecting the final outcome) algorithm design to illustrate synchronization and techniques for resolving them in a multi processor/ multi core system.
### - Multicore CPUs and multithreading
(This section is not important for the project, but I felt the need to understand how the CPU works before proceeding with working with threads; My research was based on this<a href="https://insights.sei.cmu.edu/blog/multicore-processing/"> article</a>)
#### Multicore CPU
<br>
<img src = "./learning_materials/imgs/multicore_cpu.png">
<br>
A multicore CPU is a single integrated circuit that contains multiple core processing units. CPUs differ according to these traits:
<ul>
<li>Number of cores </li>
<li>Number of core types: 
    <ul>
        <li>Homogeneous (symmectric) cores: All the cores are of the same type that run on the same single multicore OS</li>
        <li>Heterogeneous (asymmectric) cores: Cores could be of different types that run on different OS and include graphics processing units</li>
    </ul>
<li>Number and level of caches: multicore processors vary in terms of their instruction and data caches (is a hardware cache used by the cpu to reduce time to access data from the main memory; CPUs have a hierarchy of multiple cache levels (L1 to L4 with L1 being the fastest))</li>
<li>How cores are interconnected: variety of bus architectures (how data is communicated between cores </li>
<li>Isolation: includes Physical isolation (different cores cannot access the same physical hardware) and temporal isolation (insures that the execution of software on one core, does not impact the behavior of software running on another core)</li>
</ul>

### - POSIX Threads (Pthreads)
##### - Introduction
Pthreads or Posix threads are a mechanism that permits an application to perform multiple tasks concurrently. A single process can contain multiple threads.
Threads execute the program independently though they share the same global memory. (A traditional unix process is a simple case of multithreaded processes; it is a process that contains just one thread).
The threads in a process can execute concurrently, or parallelly in a multiprocessor system, 
<img src="./learning_materials/imgs/pthreads_virtual_memory.png">

##### - Thread creation

When a program is started, the resulting process consists of a single thread, called the initial or main thread. 
The pthread_crate() function creates a new thread.
<img src="./learning_materials/imgs/pthread_creation.png">

##### - Thread termination

The execution of a thread terminates in one of the following ways: 
<ul>
<li>The thread calls </li>
</ul>
##### - Threads vs processes

##### - Thread synchronization
### - Multicore systems and Multithreading? 
### - Semaphores

### - Plan of work
<a href="http://www.crockford.com/ec/dining.html"> Dijkstra's solution </a>; Resource hierarchy solution; arbitrator solution; Chandy/Misra solution
<ul>
<li>Think until the left fork is available; when it is, pick it up</li>
<li>Think until the right fork is available; when it is, pick it up</li>
<li>When both forks are held, eat for a fixed ammount of time</li>
<li>Put the left fork then the right fork down</li>
<li>Repeat the process</li>
</ul>

### Allowed functions

### Debugging threads with lsof 