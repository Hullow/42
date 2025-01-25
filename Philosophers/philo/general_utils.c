/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/25 17:13:42 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* 	Prints current status of philosopher, after checking 
	the global death status variable.
	
	Prints when:
		- death_status == 0 => no philosopher died yet
		- death_status == philo->philo_id => this philosopher died, print
		- otherwise, doesn't print
*/
int	print_status(t_philo *philo, long timestamp, enum message msg)
{
	static const char *const	messages[] = {
	[MSG_THINKING] = "is thinking",
	[MSG_SLEEPING] = "is sleeping",
	[MSG_EATING] = "is eating",
	[MSG_FORK] = "has taken a fork",
	[MSG_DIED] = "has died"
	};

	if (pthread_mutex_lock(philo->death_status_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
	if (*(philo->death_status) == 0 || msg == MSG_DIED)
	{
		printf("%ld %d %s\n", timestamp, philo->philo_id, messages[msg]);
		if (pthread_mutex_unlock(philo->death_status_mutex))
			return (print_error(MUTEX_UNLOCK_ERROR));
		return (0);
	}
	else
	{
		if (pthread_mutex_unlock(philo->death_status_mutex))
			return (print_error(MUTEX_UNLOCK_ERROR));
		return (0);
	}
}

/**
 * @brief	writes the appropriate error code (given as input) to stderr
 * @return	1
 */
int	print_error(int error)
{
	if (error == MALLOC_FAIL)
		write(2, "\nPhilosophers: Malloc fail\n", 28);
	else if (error == INVALID_INPUT)
		write(2, "\nPhilosophers: Invalid input\n", 30);
	else if (error == ZERO_AS_INPUT)
		write(2, "Philosophers: simulation doesn't take 0 as parameter\n", 54);
	else if (error == GET_TIME_OF_DAY_ERROR)
		write(2, "\nPhilosophers: get_time_of_day() failed\n", 41);
	else if (error == THREAD_CREATION_ERROR)
		write(2, "\nPhilosophers: Thread creation error\n", 38);
	else if (error == THREAD_DETACH_ERROR)
		write(2, "\nPhilosophers: Thread detach error\n", 36);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "\nPhilosophers: Mutex init error\n", 33);
	else if (error == MUTEX_LOCK_ERROR)
		write(2, "\nPhilosophers: Mutex lock error\n", 33);
	else if (error == MUTEX_UNLOCK_ERROR)
		write(2, "\nPhilosophers: Mutex unlock error\n", 36);
	else if (error == MUTEX_DESTROY_ERROR)
		write(2, "\nPhilosophers: Mutex destroy error\n", 36);
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
	return (((long) current_time.tv_sec * 1000) + ((long) current_time.tv_usec / 1000));
}
