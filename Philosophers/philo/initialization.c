/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/28 21:40:55 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* helper function for init_philo */
void	fill_philo_params(t_philo *philo, t_table **table, int id)
{
	int	nb_philo;

	nb_philo = (*table)->nb_philo;
	philo->philo_id = id + 1;
	philo->nb_philo = nb_philo;
	philo->left_fork_id = id % nb_philo;
	philo->right_fork_id = (id + 1) % nb_philo;
	philo->time_to_die = (long)(*table)->time_to_die;
	philo->time_to_eat = (long)(*table)->time_to_eat;
	philo->time_to_sleep = (long)(*table)->time_to_sleep;
	philo->must_eat = (*table)->must_eat;
	philo->times_eaten = 0;
}

/** @brief		fills the philosopher struct with our parameters from input
 * 	@details 	- mutexes: pointers to the mutexes initialized in the table
 * 				- philo_id : table->id + 1, because philosophers start at 1
 * 
 */
int	init_philo(t_table *table, int id)
{
	t_philo	*philo;
	int		nb_philo;

	philo = &table->philos[id];
	fill_philo_params(philo, &table, id);
	nb_philo = table->nb_philo;
	philo->start_time = table->start_time;
	philo->last_eaten = table->start_time;
	philo->left_fork = &table->forks[id % nb_philo];
	philo->right_fork = &table->forks[(id + 1) % nb_philo];
	philo->left_fork_mutex = &table->fork_mutex[id % nb_philo];
	philo->right_fork_mutex = &table->fork_mutex[(id + 1) % nb_philo];
	pthread_mutex_init(&philo->last_eaten_mutex, NULL);
	philo->death_status = &table->death_status;
	philo->death_status_mutex = &table->death_status_mutex;
	philo->done_eating_mutex = &table->done_eating_mutex;
	philo->done_eating = &table->done_eating;
	return (0);
}

/* Frees the mallocs inside table, prints the requested error, and returns -1 */
int	handle_init_error(t_table *table, t_error error)
{
	free(table->philos);
	free(table->forks);
	free(table->fork_mutex);
	return (print_error(error));
}

/* mallocs the right space in the table for philos, forks and fork mutexes */
int	handle_table_mallocs(t_table *table)
{
	table->philos = malloc (table->nb_philo * sizeof(t_philo));
	if (!table->philos)
		return (print_error(MALLOC_FAIL));
	table->forks = malloc (table->nb_philo * sizeof(unsigned char));
	if (!table->forks)
	{
		free(table->philos);
		return (print_error(MALLOC_FAIL));
	}
	table->fork_mutex = malloc (table->nb_philo * sizeof(pthread_mutex_t));
	if (!table->fork_mutex)
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

	table->start_time = get_time_stamp();
	memset(&table->death_status, NO_DEATHS, sizeof(unsigned char));
	memset(&table->done_eating, NO_DEATHS, sizeof(unsigned char));
	if (pthread_mutex_init(&table->death_status_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (pthread_mutex_init(&table->done_eating_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (handle_table_mallocs(table) == -1)
		return (-1);
	i = 0;
	while (i < table->nb_philo)
	{
		memset(&table->forks[i], FREE, sizeof(unsigned char));
		if (pthread_mutex_init(&table->fork_mutex[i], NULL))
			return (handle_init_error(table, MUTEX_INIT_ERROR));
		if (init_philo(table, i))
			return (handle_init_error(table, GET_TIME_OF_DAY_ERROR));
		i++;
	}
	return (0);
}
