/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/24 17:05:43 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// 
/** @brief		fills the philosopher struct with our parameters from input
 * 	@details 	- mutexes: pointers to the mutexes initialized in the table
 * 				- philo_id : table->id + 1, because philosophers start at 1
 * 
 */
int	init_philo(t_table	*table, t_params *params, int id)
{
	t_philo			*philo;
	int				nb_philo;

	nb_philo = params->nb_philo;
	
	/* the philosopher */
	philo = &table->philos[id];

	/* forks and mutexes */
	philo->left_fork = &table->forks[id % nb_philo];
	philo->right_fork = &table->forks[(id + 1) % nb_philo];
	philo->left_fork_mutex = &table->fork_mutex[id % nb_philo];
	philo->right_fork_mutex = &table->fork_mutex[(id + 1) % nb_philo];
	philo->death_status = &table->death_status;
	philo->global_death_mutex = &table->global_death_mutex;

	/* For debugging */
	philo->left_fork_id = id % nb_philo;
	philo->right_fork_id = (id + 1) % nb_philo;

	/* params */
	philo->philo_id = id + 1;
	philo->nb_philo = nb_philo;
	philo->time_to_die = (long) params->time_to_die;
	philo->time_to_eat = (long) params->time_to_eat;
	philo->time_to_sleep = (long) params->time_to_sleep;
	philo->must_eat = params->must_eat;
	philo->last_eaten = get_time_stamp();
	if (philo->last_eaten == -1)
		return (-1);
	philo->times_eaten = 0;
	return (0);
}

/* 
> Upon successful completion pthread_create() will store the
ID of the created thread in the location specified by thread.
	 
In my words: 
pthread_t *thread is a pointer that specifies a location. In that location, the ID of the created
thread will be stored to get the ID you'll have to dereference [pthread_t *thread] using [*thread] */


void	*checker_routine(void *vargp);

// initializes table:
// calls init_forks first
// then creates the philosophers thread with all the parameters
int	init_table(t_table *table, t_params *params, int nb_philo)
{
	int	i;

	table->nb_philo = nb_philo;
	memset(&table->death_status, '0', sizeof(unsigned char)); 	/* Set death status to 0 (no philosopher is dead) */
	if (pthread_mutex_init(&table->global_death_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	i = 0;
	while (i < nb_philo)	/* Inxitialize forks, mutexes and philosophers */
	{
		memset(&table->forks[i], 0, sizeof(unsigned char));
		if (pthread_mutex_init(&table->fork_mutex[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		if (init_philo(table, params, i))
			return (print_error(GET_TIME_OF_DAY_ERROR));
		i++;
	}
	pthread_create(&table->checker, NULL, checker_routine, table->philos);
	i = 0;
	while (i < nb_philo)	/* Create philosopher threads */
	{
		if (pthread_create(&(table->philos[i].thread), NULL, \
		philo_routine, &table->philos[i]))
			return (print_error(THREAD_CREATION_ERROR)); // add error handling (pthread_join)
		i++;
	}
	return (0);
}

void	*checker_routine(void *vargp)
{
	t_philo	*philos;
	int		nb_philo;
	int		time_to_die;
	int		i;

	philos = (t_philo *)vargp;
	nb_philo = philos[0].nb_philo;
	time_to_die = philos[0].time_to_die;
	i = 0;
	while (1)
	{
		while (i < nb_philo)
		{
			if (get_time_stamp() - philos[i].last_eaten >= time_to_die)
			{
				handle_philo_death(&philos[i]);
				return (NULL);
			}
			i++;
			usleep(10);
		}
		i = 0;
	}
	
}
