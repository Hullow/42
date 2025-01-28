/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:45:43 by francis           #+#    #+#             */
/*   Updated: 2025/01/28 21:27:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* locks a fork mutex
	returns 1 in case of error and 0 otherwise */
int	lock_single_fork_mutex(pthread_mutex_t *fork_mutex)
{
	if (pthread_mutex_lock(fork_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
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

/* 	- Attempts to mark a specific fork (left or right) as taken
	by the calling philo/thread
	- If fork is available (*(fork) == 0), marks it as taken 
	using memset to change the fork's value to the philo's id
	- Protects fork with mutex before reading and writing
*/
int	attempt_take_fork(t_philo *philo, t_fork fork_to_pick)
{
	pthread_mutex_t	*fork_mutex;
	unsigned char	*fork;

	fork_mutex = select_fork_mutex(philo, fork_to_pick);
	fork = select_fork(philo, fork_to_pick);
	pthread_mutex_lock(fork_mutex);
	if (*(fork) == 0)
	{
		memset(fork, philo->philo_id, sizeof(unsigned char));
		pthread_mutex_unlock(fork_mutex);
		print_status(philo, get_time_stamp(), MSG_FORK);
	}
	else
		pthread_mutex_unlock(fork_mutex);
	return (0);
}
