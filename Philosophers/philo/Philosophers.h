/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2025/01/25 17:13:40 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

# define MAX_THREADS 200

enum error {
	MALLOC_FAIL,
	INVALID_INPUT,
	ZERO_AS_INPUT,
	GET_TIME_OF_DAY_ERROR,
	THREAD_CREATION_ERROR,
	THREAD_DETACH_ERROR,
	MUTEX_INIT_ERROR,
	MUTEX_LOCK_ERROR,
	MUTEX_UNLOCK_ERROR,
	MUTEX_DESTROY_ERROR,
};

enum activity {
	THINKING,
	SLEEPING,
	EATING
};

enum message {
	MSG_COUNT,
	MSG_THINKING,
	MSG_SLEEPING,
	MSG_EATING,
	MSG_FORK,
	MSG_DIED,
};

enum status {
	death_status,
	finished_eating
};

enum fork {
	LEFT,
	RIGHT
};

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
	int				philo_id;
	int				nb_philo;
	long			start_time;
	long			last_eaten;
	int				times_eaten;
	int				must_eat;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_t		thread;
	pthread_mutex_t	*death_status_mutex;
	pthread_mutex_t	*finished_eating_mutex;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	unsigned char	*left_fork;
	unsigned char	*right_fork;
	int				left_fork_id;
	int				right_fork_id;
	unsigned char	*death_status;
	unsigned char	*finished_eating;
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
	long				start_time;
	t_philo				philos[MAX_THREADS];
	unsigned char		forks[MAX_THREADS];
	pthread_mutex_t		fork_mutex[MAX_THREADS];
	pthread_mutex_t		death_status_mutex;
	pthread_mutex_t		finished_eating_mutex;
	unsigned char		death_status;
	unsigned char		finished_eating;
	pthread_t			checker;
}	t_table;

// Input

int		handle_input(t_params *params, int argc, char **argv);
int		ft_atoi_philo(char *str);
int		input_checker(t_params *params);

// Initialization

int		init_table(t_table *table, t_params *params, int nb_philo);
int		init_philo(t_table *table, t_params *params, int id);
void	fill_params(t_philo *philo, t_params *params, int id);

// Simulation control

int		run_simulation(t_table table);
int		grim_reaper(t_table *table);
int		end_simulation(t_table table);

// Routines

void	*checker_routine(void *vargp);
void	*philo_routine(void *table);

// Simulation utils

void	stagger_start(int nb_philo, int id);
int		perform_activity(t_philo *philo, long activity_start, int activity);
int		edit_status_var(t_philo *philo, pthread_mutex_t *status_mutex,\
unsigned char *variable);
int		attempt_take_fork(t_philo *philo, int fork_to_pick);
int		attempt_to_eat(t_philo *philo, int id);

	// Forks

int		lock_fork_mutexes(t_philo *philo);
int		unlock_fork_mutexes(t_philo *philo);
int		lock_single_fork_mutex(pthread_mutex_t *fork_mutex);
int		unlock_single_fork_mutex(pthread_mutex_t *fork_mutex);
void	set_forks_status(t_philo *philo, char c);

// General utils

int		print_status(t_philo *philo, long timestamp, enum message msg);
int		print_error(int error);
long	get_time_stamp(void);