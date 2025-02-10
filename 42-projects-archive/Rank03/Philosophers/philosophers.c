#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

ft_destroy_mutexes()
{
	pthread_mutex_destroy(forks);
	pthread_mutex_destroy(currently_eating);
	pthread_mutex_destroy(currently_sleeping);
}

void	ft_init(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("\n%s\n", argv[1]);
	if (argc == 6)
		printf("\n%s\n", argv[5]);
}

int	main(int argc, char **argv)
{
	suseconds_t	timer; // in microsec
	suseconds_t start_time;

	// pthread_create();
	if (!argv[4] && !argv[5]) // to check
		printf("input error\n");
	ft_init(argc, argv);
	return (0);
}


typedef struct s_philosopher	{
	int	id;
	int	right_fork_id;
	int	left_fork_id;

}	t_philosopher;