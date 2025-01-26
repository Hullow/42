/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:45:25 by francis           #+#    #+#             */
/*   Updated: 2025/01/26 19:46:34 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/* Staggers the start of the simulation, so even and uneven philos eat 
at different times:
	- In all simulations, even-numbered philos wait 0.2ms before trying to eat
	- In simulations with an uneven number of philosophers, the first philo
	waits 0.5ms before trying to eat, so that there it can alternate with 
	the last philo, which is its neighbor, and also uneven-numbered
// 1st philo waiting 0.5 ms rather than 0.2 ms before trying to eat => likely no change; and yet, it seems to have changed things
	*/
void	stagger_start(int nb_philo, int id)
{
	if (id == 1 && nb_philo % 2 != 0)
		usleep(500);
	else if (id % 2 == 0)
		usleep(200);
}

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
		print_status(philo, activity_start, MSG_SLEEPING);
		desired_sleep = philo->time_to_sleep;
	}
	else if (activity == EATING)
	{
		pthread_mutex_lock(&philo->last_eaten_mutex);
		philo->last_eaten = activity_start;
		pthread_mutex_unlock(&philo->last_eaten_mutex);
		print_status(philo, activity_start, MSG_EATING);
		desired_sleep = philo->time_to_eat;
		philo->times_eaten++;
	}
	while (desired_sleep > get_time_stamp() - activity_start)
		usleep(250);
	if (philo->times_eaten == philo->must_eat)
	{
		printf("%ld %d has eaten %d times (must_eat == %d)\n", get_time_stamp(), philo->philo_id, philo->times_eaten, philo->must_eat);	
		return (1);
	}
	if (activity == SLEEPING)
		print_status(philo, get_time_stamp(), MSG_THINKING);
	return (0);
}

/* 	- Attempts to mark a specific fork (left or right) as taken
	by the calling philo/thread
	- If fork is available (*(fork) == 0), marks it as taken 
	using memset to change the fork's value to the philo's id
	- Protects fork with mutex before reading and writing
*/
int	attempt_take_fork(t_philo *philo, int fork_to_pick)
{
	pthread_mutex_t	*fork_mutex;
	unsigned char	*fork;

	fork_mutex = NULL;
	if (fork_to_pick == LEFT)
	{
		fork_mutex = philo->left_fork_mutex;
		fork = philo->left_fork;
	}
	else if (fork_to_pick == RIGHT)
	{
		fork_mutex = philo->right_fork_mutex;
		fork = philo->right_fork;
	}
	if (lock_single_fork_mutex(fork_mutex))
		return (-1);
	if (*(fork) == 0)
	{
		memset(fork, philo->philo_id, sizeof(unsigned char));
		if (unlock_single_fork_mutex(fork_mutex))
			return (-1);
		print_status(philo, get_time_stamp(), MSG_FORK);
	}
	else if (unlock_single_fork_mutex(fork_mutex))
		return (-1);
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
int	attempt_to_eat(t_philo *philo, int id)
{
	if (lock_fork_mutexes(philo))
		return (-1);
	if (*(philo->left_fork) == id && *(philo->right_fork) == id && philo->left_fork_id != philo->right_fork_id)
	{
		if (unlock_fork_mutexes(philo)) /* unlock both mutexes */
			return (-1);
		if (perform_activity(philo, get_time_stamp(), EATING) == 1) /* start eating */
		{
			if (pthread_detach(philo->thread))
				return (print_error(THREAD_DETACH_ERROR));
			if (lock_fork_mutexes(philo))
				return (-1); // add error handling
			set_forks_status(philo, 0);
			if (unlock_fork_mutexes(philo))
				return (-1); // add error handling
			return (1); /* return 1 if the philo eat number_of_times_must_eat */
		}
		if (lock_fork_mutexes(philo))
			return (-1); // add error handling
		set_forks_status(philo, 0);
		if (unlock_fork_mutexes(philo))
			return (-1); // add error handling
		perform_activity(philo, get_time_stamp(), SLEEPING);
	}
	else
	{
		if (unlock_fork_mutexes(philo)) /* otherwise, unlock both mutexes */
			return (-1); // add error handling
		usleep(50);
	}
	return (0);
}
