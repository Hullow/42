/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2025/01/30 17:40:19 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# define FREE 0
# define DONE_EATING 1
# define STOP 2

typedef enum e_error
{
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
}	t_error;

typedef enum e_activity
{
	THINKING,
	SLEEPING,
	EATING
}	t_activity;

typedef enum e_message
{
	MSG_COUNT,
	MSG_THINKING,
	MSG_SLEEPING,
	MSG_EATING,
	MSG_FORK,
	MSG_DIED,
	MSG_FINISHED
}	t_message;

typedef enum e_fork
{
	LEFT,
	RIGHT
}	t_fork;

typedef struct s_table	t_table;

/* structure for each philosopher:
	- thread ID pointer pthread_t *thread (X bytes)
	- the philosopher's ID (4 byte)
	- last time eaten (8 byte)
	- how many times philosopher must eat 
	(set to -1 if variable is not used) (4 byte)
	- time to die (4 byte)
	- time to eat (4 byte)
	- time to sleep (4 byte)

	*/
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_eaten;
	pthread_mutex_t	last_eaten_mutex;
	int				times_eaten;
	int				left_fork_id;
	int				right_fork_id;
	int				*left_fork;
	pthread_mutex_t	*left_fork_mutex;
	int				*right_fork;
	pthread_mutex_t	*right_fork_mutex;
	t_table			*table;
	unsigned char	*done_eating;
	pthread_mutex_t	*done_eating_mutex;
	unsigned char	*simulation_stop;
	pthread_mutex_t	*simulation_stop_mutex;
}	t_philo;

// Structure for the whole table
// Holds:
// - the number of philosophers
// - the forks
// - the mutexes for the forks
// - the philosophers
// - a death status marker that is pointed to from each philosopher
struct s_table
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	long				start_time;
	t_philo				*philos;
	pthread_t			checker;
	int					*forks;
	pthread_mutex_t		*fork_mutexes;
	unsigned char		done_eating;
	pthread_mutex_t		done_eating_mutex;
	unsigned char		simulation_stop;
	pthread_mutex_t		simulation_stop_mutex;
	pthread_mutex_t		print_mutex;
};

// Input

int				handle_input(t_table *table, int argc, char **argv);
int				handle_must_eat_input(t_table *table, char **argv);
int				ft_atoi_philo(char *str);
// Initialization

int				init_table(t_table *table);
int				handle_init_error(t_table *table, t_error error);
int				handle_table_mallocs(t_table *table);
int				init_philo(t_table *table, int id);

// Simulation control

int				run_simulation(t_table *table);
int				end_simulation(t_table *table);

// Philosopher threads

void			*philo_routine(void *table);
int				attempt_to_eat(t_philo *philo, int id);
int				eat(t_philo *philo);
int				sleeping(t_philo *philo);
void			improved_usleep(long desired_time, long start_time);

// Checker thread

void			*checker_routine(void *vargp);
int				check_done_eating(t_philo *philo);
int				check_philo_died(t_philo *philo);
int				check_simulation_stop(t_table *table);

// Simulation utils

int				change_status(pthread_mutex_t *status_mutex,
					unsigned char *status_variable);
void			print_status(t_philo *philo, long timestamp, t_message msg);
void			print_died(t_philo *philo, long timestamp);
void			print_finished(t_philo *philo, long timestamp);

	// Forks
int				attempt_to_take_forks(t_philo *philo);
int				attempt_take_fork(t_philo *philo, t_fork fork_to_pick);
void			set_forks_status(t_philo *philo, int number);
int				forks_available(t_philo *philo, int id);

	// Forks mutexes

int				lock_fork_mutexes(t_philo *philo);
int				unlock_fork_mutexes(t_philo *philo);
int				unlock_single_fork_mutex(pthread_mutex_t *fork_mutex);
int				*select_fork(t_philo *philo, t_fork fork_to_pick);
pthread_mutex_t	*select_fork_mutex(t_philo *philo, t_fork fork_to_pick);

// General utils

void			stagger_start(int nb_philo, int id);
int				print_error(t_error error);
long			get_time_stamp(void);
void			free_all_mallocs(t_table *table);

#endif