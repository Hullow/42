/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/16 17:37:11 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// fills the philosopher struct with our parameters from input
void	init_philo(t_table	*table, t_params *params, int id)
{
	t_philo			*philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	philo = &table->philos[id];
	left_fork = &table->forks[id % params->nb_philo];
	right_fork = &table->forks[(id + 1) % params->nb_philo] ;

	philo->nb_philo = params->nb_philo;
	philo->philo_id = id + 1;
	philo->tt_die = (long) params->tt_die * 1000;
	philo->tt_eat = params->tt_eat * 1000;
	philo->tt_sleep = params->tt_sleep * 1000;
	philo->must_eat = params->must_eat;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
	philo->last_eaten = get_time_stamp();
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

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		init_philo(table, params, i);
		i++;
	}
	table->nb_philo = nb_philo;
	i = 0;
	
	/* Starting philosopher threads */
	while (i < nb_philo)
	{
		table->table_id = i; // data race ?
		if (pthread_create(&(table->philos[i].thread), NULL, philo_routine, &table->philos[i]))
			return (print_error(THREAD_CREATION_ERROR)); // need to destroy mutexes
		i++;
	}
	
	/* reaping threads */
	i = 0;
	while(i < nb_philo)
	{
		pthread_join(table->philos[i].thread, NULL); // add error handling
		i++;
	}
	
	/* destroying mutexes */
	i = 0;
	while(i < nb_philo)
	{
		pthread_mutex_destroy(&table->forks[i]); // add error handling
		i++;
	}
	/* need more error handling */
	return (0);
}

// philosopher thread initialization routine
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;

	/* Initialization */
	philo = (t_philo *)vargp;
	if (pthread_mutex_lock(philo->left_fork))
		printf("philo %d couldn't lock left fork (fork #%d)\n", philo->philo_id, philo->philo_id % philo->nb_philo); // add error handling
	if (pthread_mutex_lock(philo->right_fork))
		pthread_mutex_unlock(philo->left_fork); // add error handling

	id = philo->philo_id;

	/* Lock fork */
	
	/* Print current state*/
	printf("philo_routine – id: %d\n", id);
	printf("%ld Philosopher %d is thinking\n", get_time_stamp(), philo->philo_id);

	// check_if_alive(&table->philos[id]);	/* => should be done every 2.5 ms */

	/* Even number of philosophers */
	if (philo->nb_philo % 2 == 0)
	{
		// if (philo->philo_id % 2 == 0) // if uneven
		// 	usleep(1000); // sleep 1 ms

		printf("%ld Philosopher %d is eating\n", get_time_stamp(), philo->philo_id);
		usleep(philo->tt_eat); // take time to eat

		printf("%ld Philosopher %d is sleeping\n", get_time_stamp(), philo->philo_id);
		usleep(philo->tt_sleep); // take time to sleep
		
		printf("%ld Philosopher %d is thinking\n", get_time_stamp(), philo->philo_id);
	}

	/* Unlock fork */
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

	return (NULL);
}
