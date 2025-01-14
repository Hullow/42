/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:08:31 by francis           #+#    #+#             */
/*   Updated: 2025/01/14 17:15:25 by francis          ###   ########.fr       */
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
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
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
	pthread_t	*thread;
	int			philo_id;
	long		last_eaten;
	int			must_eat;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
}	t_philo;

typedef struct s_table
{
	int					table_id;
	int					nb_philo;
	t_philo				philos[MAX_THREADS];
	int					forks[MAX_THREADS];
	pthread_mutex_t		fork_mutexes[MAX_THREADS];
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
void	*init_forks(int nb_philo);
void	fill_params(t_philo *philo, t_params *params, int id);
int		init_table(t_table *table, t_params *params);
void	*philo_routine(void *vargp);