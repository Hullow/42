/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:45:43 by francis           #+#    #+#             */
/*   Updated: 2025/01/30 16:19:01 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

unsigned char	*select_fork(t_philo *philo, enum e_fork fork_to_pick)
{
	if (fork_to_pick == LEFT)
		return (philo->left_fork);
	else if (fork_to_pick == RIGHT)
		return (philo->right_fork);
	else
		return (NULL);
}

pthread_mutex_t	*select_fork_mutex(t_philo *philo, enum e_fork fork_to_pick)
{
	if (fork_to_pick == LEFT)
		return (philo->left_fork_mutex);
	else if (fork_to_pick == RIGHT)
		return (philo->right_fork_mutex);
	else
		return (NULL);
}

/* locks a philosopher's left and right fork 
	to avoid deadlocks, starts with the lowest-numbered fork
	returns -1 in case of error and 0 otherwise */
int	lock_fork_mutexes(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork_id == philo->right_fork_id)
		return (pthread_mutex_lock(philo->left_fork_mutex));
	else if (philo->left_fork_id < philo->right_fork_id)
	{
		first_fork = philo->left_fork_mutex;
		second_fork = philo->right_fork_mutex;
	}
	else
	{
		first_fork = philo->right_fork_mutex;
		second_fork = philo->left_fork_mutex;
	}
	if (pthread_mutex_lock(first_fork))
		return (-1);
	else if (pthread_mutex_lock(second_fork))
	{
		pthread_mutex_unlock(first_fork);
		return (-1);
	}
	return (0);
}

/* unlocks a fork mutex 
	returns -1 in case of error and 0 otherwise */
int	unlock_single_fork_mutex(pthread_mutex_t *fork_mutex)
{
	if (pthread_mutex_unlock(fork_mutex))
		return (print_error(MUTEX_UNLOCK_ERROR));
	return (0);
}

/* unlocks a philosopher's left and right fork 
	to avoid delays that can cause deadlocks, starts with the lowest numbered
	 returns -1 in case of error and returns 0 otherwise */
int	unlock_fork_mutexes(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork_id == philo->right_fork_id)
		return (unlock_single_fork_mutex(philo->left_fork_mutex));
	if (philo->left_fork_id < philo->right_fork_id)
	{
		first_fork = philo->left_fork_mutex;
		second_fork = philo->right_fork_mutex;
	}
	else
	{
		first_fork = philo->right_fork_mutex;
		second_fork = philo->left_fork_mutex;
	}
	if (pthread_mutex_unlock(first_fork) || \
	pthread_mutex_unlock(second_fork))
		return (print_error(MUTEX_UNLOCK_ERROR));
	return (0);
}
