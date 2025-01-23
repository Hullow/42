/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/23 17:21:37 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/**
 * @brief	writes the appropriate error code (given as input) to stderr
 * @return	1
 */
int	print_error(int error)
{
	if (error == INVALID_INPUT)
		write(2, "Philosophers: Invalid input\n", 29);
	else if (error == THREAD_CREATION_ERROR)
		write(2, "Philosophers: Thread creation error", 36);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "Philosophers: Mutex init error", 31);
	else if (error == MUTEX_LOCK_ERROR)
		write(2, "Philosophers: Mutex lock error", 31);
	else if (error == MUTEX_UNLOCK_ERROR)
		write(2, "Philosophers: Mutex unlock error", 33);
	return (-1);
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

	if (start == -1)
		return (-1);
	desired_sleep = 0;
	leg_time = 0;
	if (activity == SLEEPING)
	{
		desired_sleep = philo->time_to_sleep;
		printf("%ld ms: Philosopher %d is sleeping\n", start, philo->philo_id);
	}
	else if (activity == EATING)
	{
		desired_sleep = philo->time_to_eat;
		printf("%ld ms: Philosopher %d is eating   (left fork %d, right fork %d)\n", get_time_stamp(), philo->philo_id, philo->left_fork_id, philo->right_fork_id);
	}
	while (desired_sleep > get_time_stamp() - start)
		usleep(100);
	if (activity == SLEEPING)
	{
		leg_time = get_time_stamp();
		printf("%ld ms: Philosopher %d is thinking\n", leg_time, philo->philo_id);
	}
	else if (activity == EATING)
		philo->last_eaten = get_time_stamp();
	return (0);
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

// checks if the philosopher is still alive
int	check_if_alive(t_philo *philo)
{
	long	timestamp;
	long	time_without_eating;

	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (-1);

	// printf("checking if alive: Philosopher %d\n", philo->philo_id);
	// printf("time to die	: %ld ms\n", philo->time_to_die / 1000);
	// printf("timestamp  	: %ld ms\n", timestamp / 1000);
	// printf("last_eaten 	: %ld ms\n", philo->last_eaten / 1000);

	time_without_eating = timestamp - philo->last_eaten;
	if (philo->time_to_die <= time_without_eating)
	{
		printf("\n******************************************\n \
Philosopher %d died after spending %ld ms without eating !\n******************************************\n", 
		philo->philo_id, time_without_eating);
		return (0);
	}
	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (-1);
	// printf("=> Philosopher %d is still alive, having last eaten %ld ms ago\n\n", 
		// philo->philo_id, time_without_eating);
	return (1);
}
