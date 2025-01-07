# Philosophers - notes pertaining to the project

## Threads
From Computer Systems: a programmer's perspective (3rd edition, 2016 - Bryant & O'Hallaron)
Chapter: 12.3 Concurrent Programming with Threads

- A thread is a logical flow that runs in the context of a process
- It shares the entire contents of the process virtual address space, including its code, data, heap, shared libraries, and open files
- Each thread has its own *thread context* including:
	- a unique *thread ID (TID)*
	- stack
	- stack pointer
	- program counter
	- general-purpose registers
	- condition codes

### Thread execution model
#### Similarities with processes
- Multiple threads are similar to multiple processes:
	- each process begins as a single thread, the *main thread*
	- at some point, the main thread creates a *peer thread*, which runs concurrently to it
	- eventually, control passes to the peer thread via a context switch:
		- either because the main thread executes a slow system call such as `read` or `sleep`
		- or because it is interrupted by the system's interval timer
	- the peer thread executes for a while before control passes back to the main thread, and so on

#### Differences with processes
- Because a thread context is much smaller than a process context, a thread context switch is faster than a process context switch
- Threads are not organized in a rigid parent-child hierarchy: the threads associated with a process form a *pool* of peers, independent of which threads were created by which other threads
- The main thread is distinguished from other threads only in the sense that it is always the first thread to run in the process
- The main impact of this notion of pool of peers is that a thread can kill any of its peers or wait for any of its peers to terminate
- Each peer can read and write the same shared data

### Posix threads (Pthreads)
- a standard interface for manipulating threads from C programs, adopted in 1995 and available on all Linux systems
- Pthreads defines about 60 functions that allow programs to:
	- create, kill, reap threads
	- share data safely with peer threads
	- notify peers about changes in the system state
- The Pthreads "Hello, world !" program:
```c
#include <pthread.h>
#include <stdio.h>

void	*thread(void *vargp);

int	main()
{
	pthread_t	tid;
	Pthread_create(&tid, NULL, thread, NULL);
	Pthread_join(tid, NULL);
	exit(0);
}

void	*thread(void *vargp) /* Thread routine */
{
	printf("Hello, world!\n");
	return NULL;
}

```

42 Common Core Reading list:
- Minishell: Signals (I/O chapters)
- Philosophers: 12.3 Concurrent Programming with Threads (1008-1017; bonus: 1017-...)