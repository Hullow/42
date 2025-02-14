#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N 2

void *thread(void *vargp);

char **ptr; /* Global variable */

int main()
{
	int 		i;
	pthread_t	tid;
	char 		*msgs[N] = { "Hello from foo",	"Hello from bar" };

	ptr = msgs;
	for (i = 0; i < N; i++)
		pthread_create(&tid, NULL, thread, (void *)(&i));
	pthread_exit(NULL);
}

void *thread(void *vargp)
{
	int myid = *((int *)vargp);
	static int count = 0;
	printf("[%d]: %s (count=%d)\n", myid, ptr[myid], ++count);
	return NULL;
}