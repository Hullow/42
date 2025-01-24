/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2025/01/24 16:44:42 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

enum error {
	MALLOC_FAIL,
	INVALID_INPUT,
	GET_TIME_OF_DAY_ERROR,
	THREAD_CREATION_ERROR,
	THREAD_DETACH_ERROR,
	MUTEX_INIT_ERROR,
	MUTEX_LOCK_ERROR,
	MUTEX_UNLOCK_ERROR,
	MUTEX_DESTROY_ERROR,
};

enum sleep_activity {
	SLEEPING,
	EATING
};

# define MAX_THREADS 200

// Structure to store the input parameters
typedef struct s_params
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_params;


/* structure for each philosopher:
	- thread ID pointer pthread_t *thread (X bytes)
	- the philosopher's ID (4 byte)
	- last time eaten (8 byte)
	- how many times philosopher must eat (set to -1 if variable is not used) (4 byte)
	- time to die (4 byte)
	- time to eat (4 byte)
	- time to sleep (4 byte)

	*/
typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*global_death_mutex;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	unsigned char	*left_fork;;
	unsigned char	*right_fork;
	int				left_fork_id;
	int				right_fork_id;
	int				nb_philo;
	int				philo_id;
	long			last_eaten;
	int				times_eaten;
	int				must_eat;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	unsigned char	*death_status;
	unsigned char	*round;
}	t_philo;

// Structure for the whole table
// Holds:
// - the number of philosophers
// - the forks
// - the mutexes for the forks
// - the philosophers
// - a death status marker that is pointed to from each philosopher

typedef struct s_table
{
	int					nb_philo;
	unsigned char		forks[MAX_THREADS];
	pthread_mutex_t		fork_mutex[MAX_THREADS];
	pthread_mutex_t		global_death_mutex;
	t_philo				philos[MAX_THREADS];
	pthread_t			checker;
	unsigned char		death_status;
}	t_table;

// Input

int		handle_input(t_params *params, int argc, char **argv);
int		ft_atoi_philo(char *str);
int		handle_invalid_input(t_params *params);
int		input_checker(t_params *params);

// Simulation
	// Initialization

int		init_table(t_table *table, t_params *params, int nb_philo);
int		init_forks(t_table *table, int nb_philo);
int		init_philo(t_table	*table, t_params *params, int id);
void	fill_params(t_philo *philo, t_params *params, int id);
	// Routine

void	*philo_routine(void *table);
int		handle_philo_death(t_philo *philo);
int		lock_single_fork_mutex(pthread_mutex_t *fork_mutex);
int		unlock_single_fork_mutex(pthread_mutex_t *fork_mutex);
void	set_forks_status(t_philo *philo, char c);

// Utils

long	get_time_stamp(void); 
int		check_if_alive(t_philo *philo, long timestamp);
int		print_error(int error);
int		perform_activity(t_philo *philo, long start, int activity);