#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*thread(void *vargp);

int	main()
{
	pthread_t	tid;
	int			id = 1;

	pthread_create(&tid, NULL, thread, &id);
	// sleep(1);
	pthread_join(tid, NULL);
	exit(0);
}

void	*thread(void *vargp) /* Thread routine */
{
	int	*my_id = (int *)vargp;
	printf("Hello, world! id is : %d\n", *my_id);
	return NULL;
}
