#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	*thread_routine(void *vargp);

# define MAX_THREADS 1000

int main()
{
	int			i;
	int			*ptr;
	pthread_t	thread[50000];

	i = 0;
	while(i < 50000)
	{
		ptr = malloc(sizeof(int));
		*ptr = i;
		pthread_create(&thread[i], NULL, thread_routine, (void *) ptr);
		i++;
	}
    return 0;
}

void	*thread_routine(void *vargp)
{
	int thread_id = *((int *)vargp);
	if (thread_id % 1000 == 0)
	{
		printf("creating thread %d\n(...)\n", thread_id);

	}
	return (NULL);
}