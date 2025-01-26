/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:06:32 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 19:08:57 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* sets the fork state using memset:
	0 for free, 1 for locked as locked */
void	set_forks_status(t_philo *philo, char c)
{
	memset(philo->left_fork, c, sizeof(unsigned char));
	memset(philo->right_fork, c, sizeof(unsigned char));
}

/* locks a philosopher's left and right fork 
	to avoid deadlocks, starts with the lowest-numbered fork
	returns -1 in case of error and 0 otherwise */
int	lock_fork_mutexes(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork_id == philo->right_fork_id)
		return (lock_single_fork_mutex(philo->left_fork_mutex));
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
	if (lock_single_fork_mutex(first_fork))
		return (-1);
	else if (lock_single_fork_mutex(second_fork))
	{
		unlock_single_fork_mutex(first_fork);
		return (-1);
	}
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
	{
		if (unlock_single_fork_mutex(philo->left_fork_mutex))
			return (-1);
		return (0);
	}
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
		return(print_error(MUTEX_UNLOCK_ERROR));
	return (0);
}

/* locks a fork mutex
	returns 1 in case of error and 0 otherwise */
int	lock_single_fork_mutex(pthread_mutex_t *fork_mutex)
{
	if (pthread_mutex_lock(fork_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
	return (0);
}

/* unlocks a fork mutex 
	returns 1 in case of error and 0 otherwise */
int	unlock_single_fork_mutex(pthread_mutex_t *fork_mutex)
{
	if (pthread_mutex_unlock(fork_mutex))
		return (print_error(MUTEX_UNLOCK_ERROR));
	return (0);
}
