/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:23 by francis           #+#    #+#             */
/*   Updated: 2025/01/24 17:18:29 by francis          ###   ########.fr       */
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
	memset(philo->death_status, '1', sizeof(unsigned char));
	if (pthread_mutex_unlock(philo->global_death_mutex))
		return (print_error(MUTEX_UNLOCK_ERROR));
	if (pthread_detach(philo->thread))
		return (print_error(THREAD_DETACH_ERROR));
	printf("%ld ms: Philosopher %d  died !\n", get_time_stamp(), philo->philo_id);
	return (0);
}

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

/* philosopher thread routine */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;
	long	timestamp;

	/* Initialization */
	philo = (t_philo *)vargp;
	id = philo->philo_id; /* Set ids */
	printf("%ld ms: Philosopher %d  is thinking\n", get_time_stamp(), id);
	timestamp = 0;

	/* Staggered start:*/
	if (philo->nb_philo % 2 == 0) /* if even number of philosophers */
	{
		if (id % 2 == 0) // even numbered philos wait 0.05ms before trying to eat
			usleep(100);
	}
	else /* Uneven number of philosopher */
	{
		if (id % 2 == 0) // even numbered philos wait 0.1 ms before trying to eat
			usleep(100);
		if (id == 1) // 1st philo waits 0.2 ms before trying to eat => likely no change; and yet, it seems to have changed things
			usleep(200);
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
			timestamp = get_time_stamp();
			if (unlock_single_fork_mutex(philo->left_fork_mutex))
				break ;
			printf("%ld ms: Philosopher %d  has a taken a fork (left fork  %d)\n", timestamp, id, philo->left_fork_id);
		}
		else if (unlock_single_fork_mutex(philo->left_fork_mutex))
			break ;

		/* Take right fork if possible */
		if (lock_single_fork_mutex(philo->right_fork_mutex))
			break ;
		if (*(philo->right_fork) == 0) /* if right fork available */
		{
			memset(philo->right_fork, id, sizeof(unsigned char));
			timestamp = get_time_stamp();
			if (unlock_single_fork_mutex(philo->right_fork_mutex))
				break ;
			printf("%ld ms: Philosopher %d  has a taken a fork (right fork %d)\n", timestamp, id, philo->right_fork_id);
		}
		else if (unlock_single_fork_mutex(philo->right_fork_mutex))
			break ;
		if (lock_fork_mutexes(philo)) /* unlock both mutexes */
			break ;

		/* Eat if possible */
		if (*(philo->left_fork) == id && *(philo->right_fork) == id) /* if right fork available */
		{
			if (unlock_fork_mutexes(philo)) /* unlock both mutexes */
				break ;
			perform_activity(philo, get_time_stamp(), EATING); /* start eating */
			/* Reset forks to available */
			if (lock_fork_mutexes(philo))
				break ; // add error handling
			set_forks_status(philo, 0);
			if (unlock_fork_mutexes(philo))
				break ; // add error handling
			/* Sleeping */
			perform_activity(philo, get_time_stamp(), SLEEPING);
		}
		else
		{
			if (unlock_fork_mutexes(philo)) /* otherwise, unlock both mutexes */
				break ;
			usleep(10);
		}
	}
	return (NULL);
}
