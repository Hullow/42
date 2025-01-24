/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/24 07:56:43 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/**
 * @brief	writes the appropriate error code (given as input) to stderr
 * @return	1
 */
int	print_error(int error)
{
	if (error == MALLOC_FAIL)
		write(2, "Philosophers: Malloc fail\n", 27);
	else if (error == INVALID_INPUT)
		write(2, "Philosophers: Invalid input\n", 29);
	else if (error == GET_TIME_OF_DAY_ERROR)
		write(2, "Philosophers: get_time_of_day() failed\n", 40);
	else if (error == THREAD_CREATION_ERROR)
		write(2, "Philosophers: Thread creation error", 36);
	else if (error == THREAD_DETACH_ERROR)
		write(2, "Philosophers: Thread detach error", 34);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "Philosophers: Mutex init error", 31);
	else if (error == MUTEX_LOCK_ERROR)
		write(2, "Philosophers: Mutex lock error", 31);
	else if (error == MUTEX_UNLOCK_ERROR)
		write(2, "Philosophers: Mutex unlock error", 33);
	else if (error == MUTEX_DESTROY_ERROR)
		write(2, "Philosophers: Mutex destroy error", 34);
	return (-1);
}

/**
 * @brief	calculates the timestamp in ms
 * @return	timestamp in milliseconds (long), or -1 on error
 * @details	uses gettimeofday() to get current time and converts it
 * 			by multiplying second by 1000 and adding microseconds divided by 1000
 */
long	get_time_stamp(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	return (((current_time.tv_sec * 1000) + current_time.tv_usec / 1000));
}

/**
 * @brief	Sleeps the precise number of ms
 * @details Checks the current time since desired start, 
 * 			taking as input the desired_sleep_time (in ms),
 * 			and the activity (eating or sleeping)
 * @returns	-1 in case of error, 0 otherwise
 */
int	perform_activity(t_philo *philo, long start, int activity)
{
	long	desired_sleep;
	long	leg_time;
	long	current_time;

	if (start == -1)
		return (-1);
	desired_sleep = 0;
	leg_time = 0;
	current_time = get_time_stamp();
	if (activity == SLEEPING)
	{
		desired_sleep = philo->time_to_sleep;
		printf("%ld ms: Philosopher %d  is sleeping\n", start, philo->philo_id);
	}
	else if (activity == EATING)
	{
		desired_sleep = philo->time_to_eat;
		printf("%ld ms: Philosopher %d  is eating   (left fork %d, right fork %d)\n", current_time, philo->philo_id, philo->left_fork_id, philo->right_fork_id);
	}
	current_time = get_time_stamp();
	while (desired_sleep > current_time - start)
	{
		if (activity == SLEEPING)
		{
			if (check_if_alive(philo, current_time) == 0)
				return (handle_philo_death(philo));
		}
		usleep(50);
		current_time = get_time_stamp();
	}
	if (activity == SLEEPING)
	{
		leg_time = get_time_stamp();
		printf("%ld ms: Philosopher %d  is thinking   (waiting for left fork %d, right fork %d)\n", leg_time, philo->philo_id, philo->left_fork_id, philo->right_fork_id);
	}
	else if (activity == EATING)
		philo->last_eaten = get_time_stamp();
	return (0);
}

// checks if the philosopher is still alive
int	check_if_alive(t_philo *philo, long timestamp)
{
	long	time_without_eating;

	if (timestamp == -1)
		return (-1);
	time_without_eating = timestamp - philo->last_eaten;
	// pthread_mutex_lock(philo->global_death_mutex);
	// if (*(philo->global_death_status) == '1')
	// {
	// 	pthread_mutex_unlock(philo->global_death_mutex);
	// 	// printf("\nPhilosopher death detected, detaching\n");
	// 	// pthread_detach(philo->thread);
	// 	return (0);
	// }
	// pthread_mutex_unlock(philo->global_death_mutex);
	if (philo->time_to_die <= time_without_eating)
	{
		printf("%ld ms: Philosopher %d  died after spending %ld ms \
without eating !\n", timestamp, philo->philo_id, time_without_eating);
		return (0);
	}
	return (1);
}
