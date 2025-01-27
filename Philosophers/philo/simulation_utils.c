/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:45:25 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 22:43:31 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/*	Used to signal the death of a philosopher or count the number of philos
	that have eaten.
	
	How it works:
	- Increments the value of a shared status variable 
	(death_status or finished_eating) by 1.
	- If the variable is death_status, prints the death announcement
	for the corresponding philosopher (given in parameters)
*/
int	edit_status_var(t_philo *philo, pthread_mutex_t *status_mutex, \
unsigned char *variable)
{
	unsigned char	value;

	value = *variable + 1;
	if (pthread_mutex_lock(status_mutex))
		return (print_error(MUTEX_LOCK_ERROR));
	memset(variable, value, sizeof(unsigned char));
	if (pthread_mutex_unlock(status_mutex))
		return (print_error(MUTEX_UNLOCK_ERROR));
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
	{
		printf("%ld %d has eaten %d times (must_eat == %d)\n", \
		get_time_stamp(), philo->philo_id, philo->times_eaten, philo->must_eat);
		return (1);
	}
	if (activity == SLEEPING)
		print_status(philo, get_time_stamp(), MSG_THINKING);
	return (0);
}

// bool	check_id(t_philo *philo, int id)
// {
// 	bool	return_value;
// 	if (*(philo->left_fork) == id && *(philo->right_fork) == id \
// 	&& philo->left_fork_id != philo->right_fork_id)
// 		return_value = TRUE;
// 	else
// 		return_value = FALSE;
// 	return (return_value);
// }

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
int	attempt_to_eat(t_philo *philo, int id)
{
	if (lock_fork_mutexes(philo))
		return (-1);
	if (*(philo->left_fork) == id && *(philo->right_fork) == id \
	&& philo->left_fork_id != philo->right_fork_id) // or if (check_id(philo))
	{
		if (unlock_fork_mutexes(philo))
			return (-1);
		if (perform_activity(philo, get_time_stamp(), philo->time_to_eat, EATING) == 1)
		{
			if (pthread_detach(philo->thread))
				return (print_error(THREAD_DETACH_ERROR));
			if (lock_fork_mutexes(philo))
				return (-1);
			set_forks_status(philo, 0);
			if (unlock_fork_mutexes(philo))
				return (-1);
			return (1);
		}
		if (lock_fork_mutexes(philo))
			return (-1);
		set_forks_status(philo, 0);
		if (unlock_fork_mutexes(philo))
			return (-1);
		perform_activity(philo, get_time_stamp(), philo->time_to_sleep, SLEEPING);
	}
	else
	{
		if (unlock_fork_mutexes(philo))
			return (-1);
		usleep(50);
	}
	return (0);
}
