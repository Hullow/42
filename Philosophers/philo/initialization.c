/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/14 19:34:37 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// fills the philosopher struct with our parameters from input
void	fill_params(t_philo	*philo, t_params *params, int id)
{
	philo->philo_id = id + 1;
	philo->must_eat = params->must_eat;
	philo->tt_die = (long) params->tt_die;
	philo->tt_eat = params->tt_eat;
	philo->tt_sleep = params->tt_sleep;
	philo->last_eaten = get_time_stamp();
}

/* 
> Upon successful completion pthread_create() will store the
ID of the created thread in the location specified by thread.
	 
In my words: 
pthread_t *thread is a pointer that specifies a location. In that location, the ID of the created
thread will be stored to get the ID you'll have to dereference [pthread_t *thread] using [*thread] */

/* Initializes the philosophers, setting the parameters from input */
int	init_philos(t_table *table, t_params *params, int nb_philo)
{
	t_philo	philo[nb_philo];
	int		i;

	i = 0;
	while (i < nb_philo)
	{
		fill_params(&philo[i], params, i);
		i++;
	}
	// i = 0;
	// while (i < nb_philo)
	// {
	// 	printf("philo[%d].philo_id: %d\n", i, philo[i].philo_id);
	// 	i++;
	// }

	
	table->philos = philo;
	return (0);
}

/* Initializes the forks, i.e. the mutexes */
int	init_forks(t_table *table, int nb_philo)
{
	pthread_mutex_t	forks[nb_philo];
	int				i;
	
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		i++;
	}
	table->forks = forks;
	return (0);
}

// initializes table:
// calls init_forks first
// then creates the philosophers thread with all the parameters
int	init_table(t_table *table, t_params *params, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		fill_params(&table->philos[i], params, i);
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		i++;
	}
	table->nb_philo = nb_philo;
	i = 0;
	/* Starting philosopher threads */
	while (i < nb_philo)
	{
		table->table_id = i; // data race ?
		if (pthread_create(&(table->philos[i].thread), NULL, philo_routine, table))
			return (print_error(THREAD_CREATION_ERROR)); // need to destroy mutexes
		i++;
	}
	/* error handling */
	return (0);
}

// philosopher thread initialization routine
void	*philo_routine(void *vargp)
{
	t_table	*table;
	int		id;

	/* Initialization */
	table = (t_table *)vargp;
	id = table->table_id;

	/* Lock fork */
	pthread_mutex_lock(&table->forks[id]);
	
	/* Print current state*/
	printf("philo_routine:\nid: %d\n", id);
	// printf("%ld Philosopher %d is thinking\n", get_time_stamp(), table->philos[id].philo_id);

	// printf("\n***seg check 1***\n\n");
	
	/* Check if alive => should be done ever 2.5 ms */
	// check_if_alive(&table->philos[id]);
	
	// printf("\n***seg check 2***\n\n");

	/* Even number of philosophers */
	if (table->nb_philo % 2 == 0)
	{
		printf("even number of philosophers: table->nb_philo == %d\n", table->nb_philo);
		if (table->table_id % 2) // if uneven
			usleep(2500); // sleep 2.5 ms

		// pthread_mutex_lock(&table->forks[id]);
		// printf("%ld Philosopher %d is eating\n", get_time_stamp(), table->philos[sd].philo_id);
		// pthread_mutex_unlock(&table->forks[id]);

		// printf("%ld Philosopher %d is thinking\n", get_time_stamp(), table->philos[id].philo_id);
	}
	else
		printf("uneven number of philosophers: table->nb_philo == %d\n", table->nb_philo);
	pthread_mutex_unlock(&table->forks[id]);

	return (NULL);
}

/* Print philos and forks on stack*/
/* 	while (i < nb_philo)
	{
		printf("fork[%d] address: %p\n", i, (void *) &table->forks[i]);
		i++;
	}	 */
