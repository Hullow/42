/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:45:25 by francis           #+#    #+#             */
/*   Updated: 2025/01/28 12:42:06 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/*	Used to signal the death of a philosopher or count the number of philos
	that have eaten.
	
	How it works:
	- Increments the value of a shared status variable 
	(death_status or done_eating) by 1.
	- If the variable is death_status, prints the death announcement
	for the corresponding philosopher (given in parameters)
*/
int	change_status(t_philo *philo, pthread_mutex_t *status_mutex, \
unsigned char *status_variable)
{
	unsigned char	value;

	pthread_mutex_lock(status_mutex);
	value = *status_variable + 1;
	memset(status_variable, value, sizeof(unsigned char));
	pthread_mutex_unlock(status_mutex);
	if (status_mutex == philo->death_status_mutex)
		print_status(philo, get_time_stamp(), MSG_DIED);
	return (0);
}

void	eat(t_philo *philo, long activity_start)
{
	pthread_mutex_lock(&philo->last_eaten_mutex);
	philo->last_eaten = activity_start;
	pthread_mutex_unlock(&philo->last_eaten_mutex);
	print_status(philo, activity_start, MSG_EATING);
	philo->times_eaten++;
}

/**
 * @brief	Sleeps the precise number of ms
 * @details Checks the current time since desired start, 
 * 			taking as input the desired_sleep_time (in ms),
 * 			and the activity (eating or sleeping)
 * @returns	-1 in case of error, 0 otherwise
 */
int	perform_activity(t_philo *philo, long activity_start, long desired_sleep, \
int activity)
{
	if (activity_start == -1)
		return (-1);
	if (activity == SLEEPING)
		print_status(philo, activity_start, MSG_SLEEPING);
	else if (activity == EATING)
		eat(philo, activity_start);
	while (desired_sleep > get_time_stamp() - activity_start)
		usleep(250);
	if (philo->times_eaten == philo->must_eat)
		return (1);
	if (activity == SLEEPING)
		print_status(philo, get_time_stamp(), MSG_THINKING);
	return (0);
}

/* Attempts to eat :
	- locks both forks mutexes
	- checks status of each fork: if both are set to the philo's id, go ahead
		-> if not, unlocks both forks mutexes and sleeps 0.05ms
	- unlocks both forks mutexes
	- calls function to eat
	- relocks both forks mutexes
	- sets forks statuses back to 0 to free them
	- unlocks both forks mutexes
	- calls function to sleep
*/
int	attempt_to_eat(t_philo *philo, int id, int time_to_eat)
{
	lock_fork_mutexes(philo);
	if (*(philo->left_fork) == id && *(philo->right_fork) == id \
	&& philo->left_fork_id != philo->right_fork_id)
	{
		unlock_fork_mutexes(philo);
		if (perform_activity(philo, get_time_stamp(), time_to_eat, EATING) == 1)
		{
			pthread_detach(philo->thread);
			lock_fork_mutexes(philo);
			set_forks_status(philo, 0);
			unlock_fork_mutexes(philo);
			return (1);
		}
		lock_fork_mutexes(philo);
		set_forks_status(philo, 0);
		unlock_fork_mutexes(philo);
		perform_activity(philo, get_time_stamp(), \
		philo->time_to_sleep, SLEEPING);
	}
	else
	{
		unlock_fork_mutexes(philo);
		usleep(200);
	}
	return (0);
}
