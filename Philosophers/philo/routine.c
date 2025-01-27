/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:17:24 by francis           #+#    #+#             */
/*   Updated: 2025/01/27 20:57:25 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	check_done_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->done_eating_mutex);
	if (*(philo->done_eating) == philo->nb_philo)
	{
		pthread_mutex_unlock(philo->done_eating_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->done_eating_mutex);
	return (0);
}

/* checks if any philosopher is dead */
void	*checker_routine(void *vargp)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)vargp;
	i = -1;
	while (1)
	{
		while (++i < philos[0].nb_philo)
		{
			if (check_done_eating(&philos[i]))
				return (NULL);
			pthread_mutex_lock(&philos[i].last_eaten_mutex);
			if (get_time_stamp() - philos[i].last_eaten >= \
			philos[i].time_to_die)
			{
				change_status(&philos[i], philos[i].death_status_mutex, \
				philos[i].death_status);
				pthread_mutex_unlock(&philos[i].last_eaten_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].last_eaten_mutex);
			usleep(300);
		}
		i = 0;
	}
}

/* philosopher thread routine
Loop : eating, then sleeping
eat_return: if -1, means mutex error, if 1, means eat enough times */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	print_status(philo, get_time_stamp(), MSG_THINKING);
	stagger_start(philo->nb_philo, philo->philo_id);
	while (1)
	{
		pthread_mutex_lock(philo->death_status_mutex);
		if (*(philo->death_status) != 0)
		{
			pthread_mutex_unlock(philo->death_status_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->death_status_mutex);
		if (attempt_take_fork(philo, LEFT) == -1)
			break ;
		if (attempt_take_fork(philo, RIGHT) == -1)
			break ;
		if (attempt_to_eat(philo, philo->philo_id, philo->time_to_eat))
		{
			change_status(philo, philo->done_eating_mutex, philo->done_eating);
			break ;
		}
	}
	return (NULL);
}

/* Checks the death status variable to see if a philosopher died
	then sleep 0.5ms */
int	grim_reaper(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->death_status_mutex);
		if (table->death_status != 0)
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
