#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void	init_philos(int nb_philos);
void	*init_philos_routine(void *thread_id);
long	get_time_stamp(void);

char *messages[6];

int	main()
{
	int	nb_philos = 6;
	init_philos(nb_philos);
	exit (0);
}

void	*init_philos_routine(void *thread_id, long initial_time)
{
	long	taskid;
	
	taskid = (long) thread_id;

	printf("%ld Creating philo #%ld: %s\n", current_time, taskid, messages[taskid]);
	return NULL;
	// pthread_exit(NULL);
}

void	init_philos(int nb_philos)
{
	pthread_t	philos[nb_philos];
	long		id[nb_philos];
	long		current_time;
	int			ret_code;
	int			i;

	messages[0] = "this is the first philosopher !";
	messages[1] = "this is the second philosopher !";
	messages[2] = "this is the third philosopher !";
	messages[3] = "this is the fourth philosopher !";
	messages[4] = "this is the fifth philosopher !";
	messages[5] = "this is the sixth philosopher !";

	i = 0;
	while (i < nb_philos)
	{
		id[i] = i;
		printf("creating thread %d – thread ID: %ld\n", i, (long) philos[i]);
		current_time = get_time_stamp();
		ret_code = pthread_create(&philos[i], NULL, init_philos_routine, (void *) id[i]);
		if (ret_code)
		{
			printf("ERROR: return code from pthread_create() is %d\n", ret_code);
			exit (-1);
		}
		pthread_join(philos[i], NULL);
		i++;
	}
	// exit(0); this stops the prints for some reason
	pthread_exit(NULL);
}


long	get_time_stamp(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	return ((current_time.tv_sec * 1000) + current_time.tv_usec / 1000);
}