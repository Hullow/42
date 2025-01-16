/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2025/01/16 19:51:40 by francis          ###   ########.fr       */
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
	MUTEX_INIT_ERROR,
	THREAD_CREATION_ERROR
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
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	unsigned char	*left_fork;
	unsigned char	*right_fork;
	int				nb_philo;
	int				philo_id;
	long			last_eaten;
	int				times_eaten;
	int				must_eat;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	unsigned char	*global_death_status;
}	t_philo;

typedef struct s_table
{
	int					table_id;
	int					nb_philo;
	unsigned char		forks[MAX_THREADS];
	pthread_mutex_t		fork_mutex[MAX_THREADS];
	t_philo				philos[MAX_THREADS];
	unsigned char		global_death_status;
}	t_table;

// Utils
	// Input
int		ft_atoi(char *str);
int		handle_input(t_params *params, int argc, char **argv);
	// Running
long	get_time_stamp(void);
int		check_if_alive(t_philo *philo);
int		print_error(int error);

// Simulation
	// Initialization
int		init_table(t_table *table, t_params *params, int nb_philo);
int		init_forks(t_table *table, int nb_philo);
void	init_philo(t_table	*table, t_params *params, int id);
void	fill_params(t_philo *philo, t_params *params, int id);
	// Routine
void	*philo_routine(void *table);