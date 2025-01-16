/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:38:23 by francis           #+#    #+#             */
/*   Updated: 2025/01/16 19:52:37 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* philosopher thread routine */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		id;
	int		left_fork_id;
	int		right_fork_id;

	/* Initialization */
	philo = (t_philo *)vargp;

	if (check_if_alive(philo) == 0); /* => should be done every 2.5 ms */
	{
		// lock global death mutex
		memset(philo->global_death_status, '1', sizeof(unsigned char));
		// unlock global death mutex
		return (NULL);
	}

	/* Lock mutexes */
	pthread_mutex_lock(philo->left_fork_mutex);
	if (pthread_mutex_lock(philo->right_fork_mutex))
		pthread_mutex_unlock(philo->left_fork_mutex); // add error handling

	/* Set ids and print current state*/
	id = philo->philo_id;
	printf("philo_routine – id: %d\n", id);

	/* Set forks to unavailable */
	if (*(philo->left_fork) == '0' && *(philo->right_fork) == '0') /* if left and right forks are available */
	{
		memset(philo->left_fork, '1', sizeof(unsigned char)); /* set it as locked */
		memset(philo->right_fork, '1', sizeof(unsigned char)); /* set it as locked */

		/* Eating */
		philo->last_eaten = get_time_stamp();
		printf("%ld Philosopher %d is eating\n", get_time_stamp(), id);
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		usleep(philo->time_to_eat * 1000); /* eat for time_to_eat ms */
		
		/* Reset forks to available */
		pthread_mutex_lock(philo->left_fork_mutex);
		if (pthread_mutex_lock(philo->right_fork_mutex))
			pthread_mutex_unlock(philo->left_fork_mutex); // add error handling
		memset(&table->forks[left_fork_id], '0', sizeof(unsigned char)); /* set it as locked */
		memset(&table->forks[right_fork_id], '0', sizeof(unsigned char)); /* set it as locked */
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);

		/* Sleeping */
		printf("%ld Philosopher %d is sleeping\n", get_time_stamp(), id);
		usleep(philo->time_to_sleep * 1000);
	}
	else /* unlock mutexes, wait 0.5 ms */
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		usleep(500);
	}
	printf("%ld Philosopher %d is thinking\n", get_time_stamp(), id);

	/* Even number of philosophers */
	if (philo->nb_philo % 2 == 0)
	{
		// if (philo->philo_id % 2 == 0) // if uneven
		// 	usleep(1000); // sleep 1 ms

		printf("%ld Philosopher %d is eating\n", get_time_stamp(), philo->philo_id);
		usleep(philo->time_to_eat); // take time to eat

		printf("%ld Philosopher %d is sleeping\n", get_time_stamp(), philo->philo_id);
		usleep(philo->time_to_sleep); // take time to sleep
		
		printf("%ld Philosopher %d is thinking\n", get_time_stamp(), philo->philo_id);
	}
	return (NULL);
}
