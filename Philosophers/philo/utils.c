/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/14 17:11:13 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	print_error(int error)
{
	if (error == THREAD_CREATION_ERROR)
		write(2, "Philosophers: Thread creation error", 22);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "Philosophers: Mutex init error", 17);
	return (-1);
}

// returns timestamp in ms
// printf("time in seconds: %ld\n", current_time.tv_sec);
// printf("+ ms: %d\n", current_time.tv_usec);
// printf("time in ms: %ld\n", timestamp);
long	get_time_stamp(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	return ((current_time.tv_sec * 1000) + current_time.tv_usec / 1000);
}

int	check_if_alive(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (-1);
	if ((timestamp - philo->last_eaten) >= philo->tt_die)
	{
		printf("%ld Philosopher %d died after spending %ld ms without eating\n", 
			timestamp, philo->id, timestamp - philo->last_eaten);
		return (0);
	}
	printf("%ld Philosopher %d is still alive, having last eaten %ld ms ago\n", 
		timestamp, philo->id, timestamp - philo->last_eaten);
	return (1);
}
