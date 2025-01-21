/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/21 15:49:19 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// fills the philosopher struct with our parameters from input
void	init_philo(t_table	*table, t_params *params, int id)
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

	/* For debugging */
	philo->left_fork_id = id % nb_philo;
	philo->right_fork_id = (id + 1) % nb_philo;

	/* params */
	philo->philo_id = id + 1; // start philosophers at 1 instead of 0
	philo->nb_philo = nb_philo;
	philo->time_to_die = (long) params->time_to_die;
	philo->time_to_eat = (long) params->time_to_eat;
	philo->time_to_sleep = (long) params->time_to_sleep;
	philo->must_eat = params->must_eat;
	philo->last_eaten = get_time_stamp();
	philo->times_eaten = 0;
	philo->global_death_status = &table->global_death_status;
}

/* 
> Upon successful completion pthread_create() will store the
ID of the created thread in the location specified by thread.
	 
In my words: 
pthread_t *thread is a pointer that specifies a location. In that location, the ID of the created
thread will be stored to get the ID you'll have to dereference [pthread_t *thread] using [*thread] */

// initializes table:
// calls init_forks first
// then creates the philosophers thread with all the parameters
int	init_table(t_table *table, t_params *params, int nb_philo)
{
	int	i;

	table->nb_philo = nb_philo;

	/* Set death status to 0 (no philosopher is dead) */
	memset(&table->global_death_status, '0', sizeof(unsigned char));

	/* Initialize forks, mutexes and philosophers */
	i = 0;
	while (i < nb_philo)
	{
		memset(&table->forks[i], '0', sizeof(unsigned char));
		if (pthread_mutex_init(&table->fork_mutex[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		init_philo(table, params, i);
		i++;
	}

	/* Create philosopher threads */
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(table->philos[i].thread), NULL, philo_routine, &table->philos[i]))
			return (print_error(THREAD_CREATION_ERROR)); // add error handling (pthread_join)
		i++;
	}
	return (0);
}
