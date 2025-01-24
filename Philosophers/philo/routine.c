/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:23 by francis           #+#    #+#             */
/*   Updated: 2025/01/25 00:10:39 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// sets the global death status to 1
// prints a death statement
// returns 0 on success, -1 in case of error
int	handle_philo_death(t_philo *philo)
{
	if (pthread_mutex_lock(philo->global_death_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
	memset(philo->death_status, philo->philo_id, sizeof(unsigned char));
	if (pthread_mutex_unlock(philo->global_death_mutex))
		return (print_error(MUTEX_UNLOCK_ERROR));
	print_status(philo, get_time_stamp(0), "died");
	return (0);
}

/* checks if a philosopher is dead */
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
			if (get_time_stamp(philos[0].start_time) - philos[i].last_eaten >= time_to_die)
			{
				handle_philo_death(&philos[i]);
				return (NULL);
			}
			i++;
			usleep(300);
		}
		i = 0;
	}
}

/* philosopher thread routine */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;
	long	timestamp;

	/* Initialization */
	philo = (t_philo *)vargp;
	id = philo->philo_id; /* Set ids */
	timestamp = get_time_stamp(0);
	print_status(philo, timestamp, "is thinking");

	/* Staggered start:*/
	if (philo->nb_philo % 2 == 0) /* if even number of philosophers */
	{
		if (id % 2 == 0) // even numbered philos wait 0.05ms before trying to eat
			usleep(200);
	}
	else /* Uneven number of philosopher */
	{
		if (id % 2 == 0) // even numbered philos wait 0.1 ms before trying to eat
			usleep(200);
		if (id == 1) // 1st philo waits 0.2 ms before trying to eat => likely no change; and yet, it seems to have changed things
			usleep(500);
	}
	/* Loop */
	while (1)
	{
		/* Eating routine */
		/* Take left fork if possible */
		if (lock_single_fork_mutex(philo->left_fork_mutex))
			break ;
		if (*(philo->left_fork) == 0) /* if left fork available */
		{
			memset(philo->left_fork, id, sizeof(unsigned char));
			timestamp = get_time_stamp(0);
			if (unlock_single_fork_mutex(philo->left_fork_mutex))
				break ;
			print_status(philo, timestamp, "has taken a fork");
		}
		else if (unlock_single_fork_mutex(philo->left_fork_mutex))
			break ;

		/* Take right fork if possible */
		if (lock_single_fork_mutex(philo->right_fork_mutex))
			break ;
		if (*(philo->right_fork) == 0) /* if right fork available */
		{
			memset(philo->right_fork, id, sizeof(unsigned char));
			timestamp = get_time_stamp(0);
			if (unlock_single_fork_mutex(philo->right_fork_mutex))
				break ;
			print_status(philo, timestamp, "has taken a fork");
		}
		else if (unlock_single_fork_mutex(philo->right_fork_mutex))
			break ;

		/* Try to eat with both forks */
		if (lock_fork_mutexes(philo))
			break ;
		if (*(philo->left_fork) == id && *(philo->right_fork) == id)
		{
			if (unlock_fork_mutexes(philo)) /* unlock both mutexes */
				break ;
			perform_activity(philo, get_time_stamp(0), EATING); /* start eating */
			if (lock_fork_mutexes(philo))
				break ; // add error handling
			set_forks_status(philo, 0);
			if (unlock_fork_mutexes(philo))
				break ; // add error handling
			perform_activity(philo, get_time_stamp(0), SLEEPING);
		}
		else
		{
			if (unlock_fork_mutexes(philo)) /* otherwise, unlock both mutexes */
				break ; // add error handling
			usleep(100);
		}
	}
	return (NULL);
}
