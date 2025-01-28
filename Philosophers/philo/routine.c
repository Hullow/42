/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:17:24 by francis           #+#    #+#             */
/*   Updated: 2025/01/28 23:27:06 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

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

int	check_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eaten_mutex);
	if (get_time_stamp() - philo->last_eaten >= philo->table->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_eaten_mutex);
		// change_status(philo->death_status_mutex, philo->death_status);
		change_status(philo->simulation_stop_mutex, philo->simulation_stop);
		print_status(philo, get_time_stamp(), MSG_DIED);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->last_eaten_mutex);
	return (0);
}

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

	philos = (t_philo *)vargp;
	i = 0;
	while (1)
	{
		// if (check_done_eating(&philos[i]))
		// 	return (NULL);
		while (i < philos[0].table->nb_philo)
		{
			if (check_simulation_stop(philos[0].table))
				return (NULL);
			if (check_done_eating(&philos[i]))
				return (NULL);
			if (check_philo_died(&philos[i]))
				return (NULL);
			i++;
		}
		i = 0;
		usleep(300);
	}
}

/* philosopher thread routine
Loop : eating, then sleeping
eat_return: if -1, means mutex error, if 1, means eat enough times */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;

	philo = (t_philo *)vargp;
	id = philo->philo_id;
	print_status(philo, get_time_stamp(), MSG_THINKING);
	stagger_start(philo->table->nb_philo, id);
	while (1)
	{
		pthread_mutex_lock(philo->death_status_mutex);
		if (*(philo->death_status) != NO_DEATHS || check_done_eating(philo))
		{
			pthread_mutex_unlock(philo->death_status_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->death_status_mutex);
		pthread_mutex_lock(philo->simulation_stop_mutex);
		if (*(philo->simulation_stop) != 0)
		{
			pthread_mutex_unlock(philo->simulation_stop_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->simulation_stop_mutex);
		attempt_take_fork(philo, LEFT);
		attempt_take_fork(philo, RIGHT);
		if (attempt_to_eat(philo, id, philo->table->time_to_eat) == DONE_EATING)
		{
			change_status(philo->done_eating_mutex, philo->done_eating);
			break ;
		}
	}
	return (NULL);
}
