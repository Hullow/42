/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:45:04 by francis           #+#    #+#             */
/*   Updated: 2025/01/31 17:44:52 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/*	Used to:
	- increment total count of philos that have finished eating (done_eating)
	- mark the simulation as finished (simulation_stop)
	
	How it works:
	- Increments the value of a shared status variable 
	(simulation_stop or done_eating) by 1.
	- If the variable is simulation_stop, prints the death announcement
	for the corresponding philosopher (given in parameters)
*/
int	change_status(pthread_mutex_t *status_mutex, unsigned char *status_variable)
{
	unsigned char	value;

	pthread_mutex_lock(status_mutex);
	value = *status_variable + 1;
	memset(status_variable, value, sizeof(unsigned char));
	pthread_mutex_unlock(status_mutex);
	return (0);
}

void	print_finished(t_philo *philo, long timestamp)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld All %d philosophers eat %d times - simulation stopping\n",
		timestamp, philo->table->nb_philo, philo->table->must_eat);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	print_died(t_philo *philo, long timestamp)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d has died\n", timestamp, philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

/* 	Prints current status of philosopher, after checking 
	the global death status variable.
	
	Prints when:
		(...)
*/
void	print_status(t_philo *philo, long timestamp, t_message msg)
{
	const char *const	messages[] = {
	[MSG_THINKING] = "is thinking",
	[MSG_SLEEPING] = "is sleeping",
	[MSG_EATING] = "is eating",
	[MSG_FORK] = "has taken a fork"
	};

	if (msg == MSG_FINISHED)
		print_finished(philo, timestamp);
	else if (msg == MSG_DIED)
		print_died(philo, timestamp);
	else
	{
		if (check_simulation_stop(philo->table))
			return ;
		pthread_mutex_lock(&philo->table->simulation_stop_mutex);
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp, philo->id, messages[msg]);
		pthread_mutex_unlock(&philo->table->print_mutex);
		pthread_mutex_unlock(&philo->table->simulation_stop_mutex);
	}
}
