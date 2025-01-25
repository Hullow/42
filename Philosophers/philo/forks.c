/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:06:32 by francis           #+#    #+#             */
/*   Updated: 2025/01/25 10:59:50 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* locks a philosopher's left and right fork 
	returns 1 in case of error and 0 otherwise */
int	lock_fork_mutexes(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork_mutex))
	{
		print_error(MUTEX_LOCK_ERROR);
		write(2, "lock_fork_mutexes: error locking left fork\n", 44);
		return (1);
	}
	else if (pthread_mutex_lock(philo->right_fork_mutex))
	{
		print_error(MUTEX_LOCK_ERROR);
		pthread_mutex_unlock(philo->left_fork_mutex); // add error handling
		write(2, "lock_fork_mutexes: error locking right fork\n", 45);
		return (1);
	}
	return (0);
}

/* locks a fork mutex
	returns 1 in case of error and 0 otherwise */
int	lock_single_fork_mutex(pthread_mutex_t *fork_mutex)
{
	if (pthread_mutex_lock(fork_mutex))
	{
		print_error(MUTEX_LOCK_ERROR);
		write(2, "lock_single_fork_mutex: error locking mutex\n", 45);
		return (1);
	}
	return (0);
}

/* unlocks a fork mutex 
	returns 1 in case of error and 0 otherwise */
int	unlock_single_fork_mutex(pthread_mutex_t *fork_mutex)
{
	if (pthread_mutex_unlock(fork_mutex))
	{
		print_error(MUTEX_UNLOCK_ERROR);
		write(2, "unlock_single_fork_mutex: error unlocking mutex\n", 49);
		return (1);
	}
	return (0);
}

/* unlocks a philosopher's left and right fork 
	in case of error, prints an error and returns 1
	returns 0 otherwise */
int	unlock_fork_mutexes(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->left_fork_mutex) || \
	pthread_mutex_unlock(philo->right_fork_mutex))
	{
		print_error(MUTEX_UNLOCK_ERROR);
		return (1);
	}
	return (0);
}

/* sets the fork state using memset:
	0 for free, 1 for locked as locked */
void	set_forks_status(t_philo *philo, char c)
{
	memset(philo->left_fork, c, sizeof(unsigned char));
	memset(philo->right_fork, c, sizeof(unsigned char));
}
