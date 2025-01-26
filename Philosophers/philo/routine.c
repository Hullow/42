/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:23 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 19:44:59 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* checks if any philosopher is dead */
void	*checker_routine(void *vargp)
{
	t_philo	*philos;
	int		nb_philo;
	int		time_to_die;
	int		i;

	philos = (t_philo *)vargp;
	nb_philo = philos[0].nb_philo;
	time_to_die = philos[0].time_to_die;
	i = 0;
	while (1)
	{
		while (i < nb_philo)
		{
			pthread_mutex_lock(&philos[i].last_eaten_mutex);
			if (get_time_stamp() - philos[i].last_eaten >= time_to_die)
			{
				edit_status_var(&philos[i], philos[i].death_status_mutex, philos[i].death_status);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].last_eaten_mutex);
			i++;
			usleep(300);
		}
		i = 0;
	}
}

/* philosopher thread routine */
void	*philo_routine(void *vargp)
{
	t_philo		*philo;
	int			id;
	int			eat_return;
	long		timestamp;

	/* Initialization */
	philo = (t_philo *)vargp;
	id = philo->philo_id; /* Set ids */
	eat_return = 0;

	/* Loop : eating, then sleeping */
	timestamp = get_time_stamp();
	print_status(philo, timestamp, MSG_THINKING);
	stagger_start(philo->nb_philo, id);
	while (1)
	{
		if (attempt_take_fork(philo, LEFT) == -1)
			break ;
		if (attempt_take_fork(philo, RIGHT) == -1)
			break ;
		eat_return = attempt_to_eat(philo, id);
		if (eat_return == -1 || eat_return == 1) /* if -1, means mutex error, if 1, means eat enough times */
		{
			edit_status_var(philo, philo->finished_eating_mutex, philo->finished_eating);
			break ;
		}
	}
	// unlock_fork_mutexes(philo); /* necessary or not ??? */
	return (NULL);
}
