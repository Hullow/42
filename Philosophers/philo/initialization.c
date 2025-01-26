/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:53:58 by fallan            #+#    #+#             */
/*   Updated: 2025/01/26 22:19:39 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	init_philo_params(t_philo *philo, t_params **params, int id)
{
	int	nb_philo;

	nb_philo = (*params)->nb_philo;
	philo->philo_id = id + 1;
	philo->nb_philo = nb_philo;
	philo->left_fork_id = id % nb_philo;
	philo->right_fork_id = (id + 1) % nb_philo;
	philo->time_to_die = (long) (*params)->time_to_die;
	philo->time_to_eat = (long) (*params)->time_to_eat;
	philo->time_to_sleep = (long) (*params)->time_to_sleep;
	philo->must_eat = (*params)->must_eat;
	philo->times_eaten = 0;
}

/** @brief		fills the philosopher struct with our parameters from input
 * 	@details 	- mutexes: pointers to the mutexes initialized in the table
 * 				- philo_id : table->id + 1, because philosophers start at 1
 * 
 */
int	init_philo(t_table *table, t_params *params, int id)
{
	t_philo	*philo;
	int		nb_philo;

	philo = &table->philos[id];
	
	// init_philo_params(philo, &params, id);
	nb_philo = params->nb_philo;
	philo->philo_id = id + 1;
	philo->nb_philo = nb_philo;
	philo->left_fork_id = id % nb_philo;
	philo->right_fork_id = (id + 1) % nb_philo;
	philo->time_to_die = (long) params->time_to_die;
	philo->time_to_eat = (long) params->time_to_eat;
	philo->time_to_sleep = (long) params->time_to_sleep;
	philo->must_eat = params->must_eat;
	philo->times_eaten = 0;

	nb_philo = params->nb_philo;
	philo->start_time = table->start_time;
	philo->last_eaten = table->start_time;
	philo->left_fork = &table->forks[id % nb_philo];
	philo->right_fork = &table->forks[(id + 1) % nb_philo];
	philo->left_fork_mutex = &table->fork_mutex[id % nb_philo];
	philo->right_fork_mutex = &table->fork_mutex[(id + 1) % nb_philo];
	if (pthread_mutex_init(&philo->last_eaten_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	philo->death_status = &table->death_status;
	philo->death_status_mutex = &table->death_status_mutex;
	philo->finished_eating_mutex = &table->finished_eating_mutex;
	philo->finished_eating = &table->finished_eating;
	return (0);
}

/* initializes table:
calls init_forks first
then creates the philosophers thread with all the parameters
Set death status to 0 (no philosopher is dead)
Set finished eating status to 0 (no philosopher finished eating) */
int	init_table(t_table *table, t_params *params, int nb_philo)
{
	int	i;

	table->nb_philo = nb_philo;
	table->start_time = get_time_stamp();
	memset(&table->death_status, 0, sizeof(unsigned char));
	memset(&table->finished_eating, 0, sizeof(unsigned char));
	if (pthread_mutex_init(&table->death_status_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	if (pthread_mutex_init(&table->finished_eating_mutex, NULL))
		return (print_error(MUTEX_INIT_ERROR));
	i = 0;
	while (i < nb_philo)
	{
		memset(&table->forks[i], 0, sizeof(unsigned char));
		if (pthread_mutex_init(&table->fork_mutex[i], NULL))
			return (print_error(MUTEX_INIT_ERROR));
		if (init_philo(table, params, i))
			return (print_error(GET_TIME_OF_DAY_ERROR));
		i++;
	}
	return (0);
}
