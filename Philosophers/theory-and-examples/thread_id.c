#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	pthread_t	thread;

	printf("pthread_t value is : %ld; when dereferenced: %ld\n", (long) thread, (long) &thread);
	return (0);
}