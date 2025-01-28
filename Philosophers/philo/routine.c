/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:17:24 by francis           #+#    #+#             */
/*   Updated: 2025/01/28 20:48:02 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	check_done_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->done_eating_mutex);
	if (*(philo->done_eating) == philo->nb_philo)
	{
		pthread_mutex_unlock(philo->done_eating_mutex);
		print_status(philo, get_time_stamp(), MSG_FINISHED);
		return (1);
	}
	pthread_mutex_unlock(philo->done_eating_mutex);
	return (0);
}

int	check_if_any_philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eaten_mutex);
	if (get_time_stamp() - philo->last_eaten >= philo->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_eaten_mutex);
		change_status(philo, philo->death_status_mutex, philo->death_status);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->last_eaten_mutex);
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
		if (check_done_eating(&philos[i]))
			return (NULL);
		while (i < philos[0].nb_philo)
		{
			if (check_if_any_philo_died(&philos[i]))
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
	stagger_start(philo->nb_philo, id);
	while (1)
	{
		pthread_mutex_lock(philo->death_status_mutex);
		if (*(philo->death_status) != NO_DEATHS)
		{
			pthread_mutex_unlock(philo->death_status_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->death_status_mutex);
		attempt_take_fork(philo, LEFT);
		attempt_take_fork(philo, RIGHT);
		if (attempt_to_eat(philo, id, philo->time_to_eat) == DONE_EATING)
		{
			change_status(philo, philo->done_eating_mutex, philo->done_eating);
			break ;
		}
	}
	return (NULL);
}

/* While() loop:
	- checks:
		- the death status variable to see if a philosopher died
		- the done eating variable to see if all philos have eaten enough
	- sleeps 0.5ms */
int	grim_reaper(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->death_status_mutex);
		if (table->death_status != NO_DEATHS)
		{
			pthread_mutex_unlock(&table->death_status_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->death_status_mutex);
		pthread_mutex_lock(&table->done_eating_mutex);
		if (table->done_eating == table->nb_philo)
		{
			print_status(&table->philos[0], get_time_stamp(), MSG_FINISHED);
			pthread_mutex_unlock(&table->done_eating_mutex);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&table->done_eating_mutex);
			usleep(500);
		}
	}
	return (0);
}
