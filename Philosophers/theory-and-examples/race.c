#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

# define NB_THREADS 4

void	*thread_routine(void *vargp);

int	main()
{
	pthread_t	thread[NB_THREADS];
	int			i;
	int			*ptr;

	i = -1;
	while (++i < NB_THREADS)
	{
		ptr = malloc(sizeof(int));
		*ptr = i;
		pthread_create(&(thread[i]), NULL, thread_routine, (void *)ptr);
	}
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(thread[i], NULL);
	exit(0);
}

/* Thread routine*/
void	*thread_routine(void *vargp)
{
	int myid = *((int *)vargp);
	write(1, "Hello, this is thread",22);

	write(1, &myid, 1); // needs putnbr
	// printf("Hello, this is thread %d\n", myid);
	write(1, "\n", 1);
	free(vargp);
	// printf("Hello, this is thread %d\n", myid);
	return (NULL);
}


/*
- practice problem 12.13:

It would be a bad idea to free the allocated memory block in the main thread 
instead of in the peer thread because we might have a race between the
free of the pointer and the indirection of the pointer in the peer thread;
and the indirection must happen before the free.

=> correct, but better formulated:
it introduces a new race, between the call to free 
in the main thread and the assignment statement in the thread routine

- practice problem 12.14:

A. a different approach that does not malloc or free function is to
reap each peer thread in the main thread
right after its creation and routine execution,
before creating a new peer thread.

advantages:
- we don't have to handle memory:
	- lowers risk of memory issues due to forgetting to fre
	- makes the program faster (due to no syscalls?)

disadvantages:
- we can't have more than one peer thread in existence at a time

=> not the answer suggested (n.b.: making tests, it works properly so likely correct)
Suggestion: pass the integer i directly, rather than passing a pointer to i:
	pthread_create(&(thread[i]), NULL, thread_routine, (void *)i);
	(..)
	int myid = (int) vargp;



 */