/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/27 17:30:29 by francis          ###   ########.fr       */
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
int	print_status(t_philo *philo, long timestamp, enum e_message msg)
{
	static const char *const	messages[] = {
	[MSG_THINKING] = "is thinking",
	[MSG_SLEEPING] = "is sleeping",
	[MSG_EATING] = "is eating",
	[MSG_FORK] = "has taken a fork",
	[MSG_DIED] = "has died"
	};

	pthread_mutex_lock(philo->death_status_mutex);
	if (*(philo->death_status) == 0 || msg == MSG_DIED)
		printf("%ld %d %s\n", timestamp, philo->philo_id, messages[msg]);
	pthread_mutex_unlock(philo->death_status_mutex);
	return (0);
}

/**
 * @brief	writes the appropriate error code (given as input) to stderr
 * @return	-1
 */
int	print_error(int error)
{
	if (error == MALLOC_FAIL)
		write(2, "\nPhilosophers: Malloc fail\n", 28);
	else if (error == INVALID_INPUT)
		write(2, "Philosophers: Invalid input\n", 29);
	else if (error == ZERO_AS_INPUT)
		write(2, "Philosophers: simulation doesn't take 0 as parameter\n", 54);
	else if (error == GET_TIME_OF_DAY_ERROR)
		write(2, "\nPhilosophers: get_time_of_day() failed\n", 41);
	else if (error == THREAD_CREATION_ERROR)
		write(2, "\nPhilosophers: Thread creation error\n", 37);
	else if (error == THREAD_DETACH_ERROR)
		write(2, "\nPhilosophers: Thread detach error\n", 35);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "\nPhilosophers: Mutex init error\n", 33);
	else if (error == MUTEX_LOCK_ERROR)
		write(2, "\nPhilosophers: Mutex lock error\n", 33);
	else if (error == MUTEX_UNLOCK_ERROR)
		write(2, "\nPhilosophers: Mutex unlock error\n", 35);
	else if (error == MUTEX_DESTROY_ERROR)
		write(2, "\nPhilosophers: Mutex destroy error\n", 36);
	return (-1);
}

/*
Staggers the start of the simulation, so even and uneven philos eat 
at different times:
	- In all simulations, even-numbered philos wait 0.2ms before trying to eat
	- In simulations with an uneven number of philosophers, the first philo
	waits 0.5ms before trying to eat, so that there it can alternate with 
	the last philo, which is its neighbor, and also uneven-numbered
// 1st philo waiting 0.5 ms rather than 0.2 ms before trying to eat 
	=> likely no change; and yet, it seems to have changed things
*/
void	stagger_start(int nb_philo, int id)
{
	if (id == 1 && nb_philo % 2 != 0)
		usleep(500);
	else if (id % 2 == 0)
		usleep(200);
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
	return (((long) current_time.tv_sec * 1000) + \
	((long) current_time.tv_usec / 1000));
}
