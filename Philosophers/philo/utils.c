/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/21 18:43:11 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/**
 * @brief	writes the appropriate error code (given as input) to stderr
 * @return	1
 */
int	print_error(int error)
{
	if (error == THREAD_CREATION_ERROR)
		write(2, "Philosophers: Thread creation error", 22);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "Philosophers: Mutex init error", 31);
	else if (error == MUTEX_LOCK_ERROR)
		write(2, "Philosophers: Mutex lock error", 31);
	else if (error == MUTEX_UNLOCK_ERROR)
		write(2, "Philosophers: Mutex unlock error", 33);
	return (1);
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
