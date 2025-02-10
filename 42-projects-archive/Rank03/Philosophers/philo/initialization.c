/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/30 18:06:07 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/** @brief		fills the philosopher struct with our parameters from input
 * 	@details 	- mutexes: pointers to the mutexes initialized in the table
 * 				- id : table->id + 1, because philosophers start at 1
 * 
 */
int	init_philo(t_table *table, int id)
{
	t_philo	*philo;
	int		nb_philo;

	philo = &table->philos[id];
	philo->id = id + 1;
	philo->table = table;
	nb_philo = table->nb_philo;
	philo->left_fork_id = id % table->nb_philo;
	philo->right_fork_id = (id + 1) % table->nb_philo;
	philo->times_eaten = 0;
	philo->last_eaten = table->start_time;
	pthread_mutex_init(&philo->last_eaten_mutex, NULL);
	philo->left_fork = &table->forks[id % nb_philo];
	philo->right_fork = &table->forks[(id + 1) % nb_philo];
	philo->left_fork_mutex = &table->fork_mutexes[id % nb_philo];
	philo->right_fork_mutex = &table->fork_mutexes[(id + 1) % nb_philo];
	philo->done_eating_mutex = &table->done_eating_mutex;
	philo->done_eating = &table->done_eating;
	philo->simulation_stop = &table->simulation_stop;
	philo->simulation_stop_mutex = &table->simulation_stop_mutex;
	return (0);
}

/* Frees the mallocs inside table, prints the requested error, and returns -1 */
int	handle_init_error(t_table *table, t_error error)
{
	free(table->philos);
	free(table->forks);
	free(table->fork_mutexes);
	return (print_error(error));
}

/* mallocs the right space in the table for philos, forks and fork mutexes */
int	handle_table_mallocs(t_table *table)
{
	table->philos = malloc (table->nb_philo * sizeof(t_philo));
	if (!table->philos)
		return (print_error(MALLOC_FAIL));
	table->forks = malloc (table->nb_philo * sizeof(int));
	if (!table->forks)
	{
		free(table->philos);
		return (print_error(MALLOC_FAIL));
	}
	table->fork_mutexes = malloc (table->nb_philo * sizeof(pthread_mutex_t));
	if (!table->fork_mutexes)
	{
		free(table->philos);
		free(table->forks);
		return (print_error(MALLOC_FAIL));
	}
	return (0);
}

/* initializes table:
calls init_forks first
then creates the philosophers thread with all the parameters
Set death status to 0 (no philosopher is dead)
Set finished eating status to 0 (no philosopher finished eating) */
int	init_table(t_table *table)
{
	int	i;

	memset(&table->done_eating, 0, sizeof(unsigned char));
	memset(&table->simulation_stop, 0, sizeof(unsigned char));
	if (pthread_mutex_init(&table->done_eating_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (pthread_mutex_init(&table->simulation_stop_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (handle_table_mallocs(table) == -1)
		return (-1);
	i = 0;
	table->start_time = get_time_stamp();
	while (i < table->nb_philo)
	{
		memset(&table->forks[i], FREE, sizeof(int));
		if (pthread_mutex_init(&table->fork_mutexes[i], NULL))
			return (handle_init_error(table, MUTEX_INIT_ERROR));
		if (init_philo(table, i))
			return (handle_init_error(table, GET_TIME_OF_DAY_ERROR));
		i++;
	}
	return (0);
}
