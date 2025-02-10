/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:45:25 by francis           #+#    #+#             */
/*   Updated: 2025/01/29 19:55:45 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

/**
 * @brief	Sleeps the precise number of ms
 * @details - Takes as input the desired_time (in ms) and the start_time
 * 			for the activity (eating or sleeping).
 * 			- Runs a while loop that usleep for a short period, continuously
 * 			checking if the desired_time has passed since the start_time		
 * */
void	improved_usleep(long desired_time, long start_time)
{
	while (desired_time > get_time_stamp() - start_time)
		usleep(250);
}

/* does the eating:
	- resets last_eaten to the given timestamp
	- prints a message "X is eating"
	- increments the times_eaten
 */
int	eat(t_philo *philo)
{
	long	start_time;

	start_time = get_time_stamp();
	if (start_time == -1)
		return (-1);
	if (check_simulation_stop(philo->table))
		return (STOP);
	pthread_mutex_lock(&philo->last_eaten_mutex);
	philo->last_eaten = start_time;
	pthread_mutex_unlock(&philo->last_eaten_mutex);
	print_status(philo, start_time, MSG_EATING);
	improved_usleep(philo->table->time_to_eat, start_time);
	philo->times_eaten++;
	if (philo->times_eaten == philo->table->must_eat)
		return (DONE_EATING);
	return (0);
}

/**
 * @brief	Puts the philosopher to sleep, and then wakes him to think
 * @details Checks the current time since the desired start_time,
 * 			taking as input the desired_time (in ms),
 * 			and the activity (eating or sleeping)
 */
int	sleeping(t_philo *philo)
{
	long	start_time;

	start_time = get_time_stamp();
	if (start_time == -1)
		return (-1);
	if (check_simulation_stop(philo->table))
		return (STOP);
	print_status(philo, start_time, MSG_SLEEPING);
	improved_usleep(philo->table->time_to_sleep, start_time);
	if (check_simulation_stop(philo->table))
		return (STOP);
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
int	attempt_to_eat(t_philo *philo, int id)
{
	int	activity_return;

	activity_return = 0;
	lock_fork_mutexes(philo);
	if (forks_available(philo, id))
	{
		unlock_fork_mutexes(philo);
		activity_return = eat(philo);
		if ((activity_return) == STOP)
			return (STOP);
		else if ((activity_return) == DONE_EATING)
		{
			set_forks_status(philo, FREE);
			return (DONE_EATING);
		}
		set_forks_status(philo, FREE);
		sleeping(philo);
	}
	else
	{
		unlock_fork_mutexes(philo);
		usleep(200);
	}
	return (0);
}

/* philosopher thread routine
Loop : eating, then sleeping
eat_return: if -1, means mutex error, if 1, means eat enough times */
void	*philo_routine(void *vargp)
{
	t_philo	*philo;
	int		eat_return;

	philo = (t_philo *)vargp;
	eat_return = 0;
	print_status(philo, get_time_stamp(), MSG_THINKING);
	stagger_start(philo->table->nb_philo, philo->philo_id);
	while (1)
	{
		if (check_simulation_stop(philo->table))
			return (NULL);
		if (attempt_to_take_forks(philo) == STOP)
			return (NULL);
		eat_return = attempt_to_eat(philo, philo->philo_id);
		if (eat_return == STOP)
			return (NULL);
		if (check_simulation_stop(philo->table)) // virer ? 
			return (NULL); // (vu le check juste avant...à tester!)
		else if (eat_return == DONE_EATING)
		{
			change_status(philo->done_eating_mutex, philo->done_eating);
			return (NULL);
		}
	}
	return (NULL);
}
