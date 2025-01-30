/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:17:24 by francis           #+#    #+#             */
/*   Updated: 2025/01/30 17:00:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* Checks whether all the philosophers are done eating

	How it works: 
		- check if done_eating == nb_philo
		- If true, mark the simulation as finished,
		by calling change_status to change the value of simulation_stop
*/
int	check_done_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->done_eating_mutex);
	if (*(philo->done_eating) == philo->table->nb_philo)
	{
		pthread_mutex_unlock(philo->done_eating_mutex);
		change_status(philo->simulation_stop_mutex, philo->simulation_stop);
		print_status(philo, get_time_stamp(), MSG_FINISHED);
		return (1);
	}
	pthread_mutex_unlock(philo->done_eating_mutex);
	return (0);
}

/* Checks if a given philosopher has died, using time_to_die, last_eaten,
and the current time */
int	check_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eaten_mutex);
	if (get_time_stamp() - philo->last_eaten
		>= (long) philo->table->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_eaten_mutex);
		change_status(philo->simulation_stop_mutex, philo->simulation_stop);
		print_status(philo, get_time_stamp(), MSG_DIED);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->last_eaten_mutex);
	return (0);
}

/* Check if the simulation has been marked as finished by the checker thread */
int	check_simulation_stop(t_table *table)
{
	pthread_mutex_lock(&table->simulation_stop_mutex);
	if (table->simulation_stop != 0)
	{
		pthread_mutex_unlock(&table->simulation_stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->simulation_stop_mutex);
	return (0);
}

/* checks if philosophers are done eating and if any philosopher is dead */
void	*checker_routine(void *vargp)
{
	t_philo	*philos;
	int		i;
	int		nb_philo;

	philos = (t_philo *)vargp;
	nb_philo = philos[0].table->nb_philo;
	i = 0;
	while (1)
	{
		while (i < nb_philo)
		{
			if (check_done_eating(&philos[i]))
				return (NULL);
			if (check_philo_died(&philos[i]))
				return (NULL);
			i++;
		}
		i = 0;
	}
}
