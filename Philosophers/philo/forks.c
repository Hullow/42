/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:06:32 by francis           #+#    #+#             */
/*   Updated: 2025/01/31 17:38:54 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* check if the two forks for a given philosopher (id) are available */
int	check_forks_reserved(t_philo *philo, int id)
{
	if (*(philo->left_fork) == id && *(philo->right_fork) == id && \
	philo->left_fork_id != philo->right_fork_id)
		return (1);
	else
		return (0);
}

/* sets the fork state using memset:
	FREE (0), or philo->ID for lokced for locked */
void	set_forks_status(t_philo *philo, char c)
{
	lock_fork_mutexes(philo);
	memset(philo->left_fork, c, sizeof(unsigned char));
	memset(philo->right_fork, c, sizeof(unsigned char));
	unlock_fork_mutexes(philo);
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
		memset(fork, philo->id, sizeof(unsigned char));
		pthread_mutex_unlock(fork_mutex);
		if (check_simulation_stop(philo->table))
			return (STOP);
		print_status(philo, get_time_stamp(), MSG_FORK);
	}
	else
	{
		pthread_mutex_unlock(fork_mutex);
		if (check_simulation_stop(philo->table))
			return (STOP);
	}
	return (0);
}

/* first attempts to take left, then right fork */
int	attempt_to_take_forks(t_philo *philo)
{
	if (attempt_take_fork(philo, LEFT) == STOP)
		return (STOP);
	if (check_simulation_stop(philo->table))
		return (STOP);
	if (attempt_take_fork(philo, RIGHT) == STOP)
		return (STOP);
	if (check_simulation_stop(philo->table))
		return (STOP);
	return (0);
}
