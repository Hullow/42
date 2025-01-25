/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/25 11:27:23 by francis          ###   ########.fr       */
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
int	print_status(t_philo *philo, long timestamp, char *activity)
{
	if (pthread_mutex_lock(philo->global_death_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
	if (*(philo->death_status) == 0 || *(philo->death_status) == philo->philo_id)
	{
		printf("%ld %d %s\n", timestamp, philo->philo_id, activity);
		if (pthread_mutex_unlock(philo->global_death_mutex))
			return (print_error(MUTEX_UNLOCK_ERROR));
		return (0);
	}
	else
	{
		if (pthread_mutex_unlock(philo->global_death_mutex))
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
long	get_time_stamp(long start_time)
{
	struct timeval	current_time;
	long			return_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	return_time = ((((long) current_time.tv_sec) * 1000) + ((long) current_time.tv_usec) / 1000) - start_time;
	return (return_time);
}

/**
 * @brief	Sleeps the precise number of ms
 * @details Checks the current time since desired start, 
 * 			taking as input the desired_sleep_time (in ms),
 * 			and the activity (eating or sleeping)
 * @returns	-1 in case of error, 0 otherwise
 */
int	perform_activity(t_philo *philo, long activity_start, int activity)
{
	long	desired_sleep;

	if (activity_start == -1)
		return (-1);
	desired_sleep = 0;
	if (activity == SLEEPING)
	{
		print_status(philo, activity_start, "is sleeping");
		desired_sleep = philo->time_to_sleep;
	}
	else if (activity == EATING)
	{
		philo->last_eaten = activity_start;
		print_status(philo, philo->last_eaten, "is eating");
		desired_sleep = philo->time_to_eat;
	}
	while (desired_sleep > get_time_stamp(0) - activity_start)
		usleep(300);
	if (activity == SLEEPING)
		print_status(philo, get_time_stamp(0), "is thinking");
	return (0);
}
