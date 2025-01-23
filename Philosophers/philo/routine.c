/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:23 by francis           #+#    #+#             */
/*   Updated: 2025/01/23 16:52:27 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

// sets the global death status to 1
// returns NULL
void	*handle_philo_death(t_philo *philo)
{
	// lock global death mutex
	memset(philo->global_death_status, '1', sizeof(unsigned char));
	// unlock global death mutex
	printf("marked a philo as dead\n");
	return (NULL);
}

/* locks a philosopher's left and right fork 
	returns 1 in case of error and 0 otherwise */
int	lock_fork_mutexes(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork_mutex))
	{
		print_error(MUTEX_LOCK_ERROR);
		printf("lock_fork_mutexes: error locking left fork\n");
		return (1);
	}
	else if (pthread_mutex_lock(philo->right_fork_mutex))
	{
		print_error(MUTEX_LOCK_ERROR);
		pthread_mutex_unlock(philo->left_fork_mutex); // add error handling
		printf("lock_fork_mutexes: error locking right fork\n");
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

/* philosopher thread routine */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;

	/* Initialization */
	philo = (t_philo *)vargp;
	id = philo->philo_id; /* Set ids */
	printf("%ld ms: Philosopher %d is thinking\n", get_time_stamp(), id);

	/* Staggered start:*/
	if (philo->nb_philo % 2 == 0) /* if even number of philosophers */
	{
		if (id % 2 == 0) // even numbered philos wait 2.5ms before trying to eat
			usleep(1000);
	}
	else /* Uneven number of philosopher */
	{
		if (id % 2 == 0 || id == 1) // even numbered philos wait 1ms before trying to eat
			usleep(1000);
	}

	/* Loop */
	while (1)
	{
		if (check_if_alive(philo) == 0)
			return (handle_philo_death(philo));
		if (lock_fork_mutexes(philo))
			break ; // add error handling

		/* Eating routine */
		if (*(philo->left_fork) == '0' && *(philo->right_fork) == '0') /* if left and right forks are available */
		{
			/* set forks to taken, unlock mutexes, eat */
			set_forks_status(philo, '1');
			unlock_fork_mutexes(philo);
			perform_activity(philo, get_time_stamp(), EATING);

			/* Reset forks to available */
			if (lock_fork_mutexes(philo))
				break ; // add error handling
			set_forks_status(philo, '0');
			if (unlock_fork_mutexes(philo))
				break ; // add error handling

			/* Sleeping */
			perform_activity(philo, get_time_stamp(), SLEEPING);
		}
		else
		{
			unlock_fork_mutexes(philo);
			usleep(50);
		}
	}
	return (NULL);
}
