/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:41:01 by fallan            #+#    #+#             */
/*   Updated: 2025/01/07 16:53:25 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


// struct timeval {
// 		time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
// 		suseconds_t  tv_usec;  /* and microseconds */
// };

int	main()
{
	struct timeval		current_time; // = NULL;
	long				timestamp;

	// current_time = malloc(sizeof(struct timeval));
	current_time.tv_sec = 0;
	current_time.tv_usec = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	printf("time in seconds: %ld\n", current_time.tv_sec);
	printf("+ ms: %d\n", current_time.tv_usec);
	timestamp = (current_time.tv_sec * 1000) + current_time.tv_usec; 
	printf("time in ms: %ld\n", timestamp);
	return (0);
	// printf("%d Philosopher %d is thinking\n", philo->philo_id);
}