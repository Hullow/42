/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:55:48 by fallan            #+#    #+#             */
/*   Updated: 2025/01/16 18:58:50 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	print_error(int error)
{
	if (error == THREAD_CREATION_ERROR)
		write(2, "Philosophers: Thread creation error", 22);
	else if (error == MUTEX_INIT_ERROR)
		write(2, "Philosophers: Mutex init error", 17);
	return (1);
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
	return (((current_time.tv_sec * 1000) + current_time.tv_usec / 1000) % 1736887000000);
}

int	check_if_alive(t_philo *philo)
{
	long	timestamp;
	long	time_without_eating;

	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (-1);

	printf("\ncheck_if_alive:\n");
	printf("time to die	: %ld\n", philo->time_to_die);
	printf("timestamp  	: %ld\n", timestamp);
	printf("last_eaten 	: %ld\n", philo->last_eaten);

	time_without_eating = timestamp - philo->last_eaten;
	if (philo->time_to_die <= time_without_eating)
	{
		printf("%ld Philosopher %d died after spending %ld ms without eating\n", 
			timestamp, philo->philo_id, time_without_eating);
		return (0);
	}
	timestamp = get_time_stamp();
	if (timestamp == -1)
		return (-1);
	printf("%ld Philosopher %d is still alive, having last eaten %ld ms ago\n", 
		timestamp, philo->philo_id, time_without_eating);
	return (1);
}
