/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:50 by fallan            #+#    #+#             */
/*   Updated: 2024/06/28 18:41:23 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("sa_handler: SIGUSR1 received\n");
	}
	else
		printf("sa_handler: received signal %d\n", signum);
}


int main()
{
	pid_t				sample_PID;
	// struct	sigaction 	sigact;
	
	sample_PID = getpid();
	// sigact.sa_handler = handler;
	ft_printf("%d\n", sample_PID);
	// sigaction(SIGUSR1, (const) sigact, NULL);
	pause();
	// while (1)
	// {
	// 	pause();
	// 	kill(getpid(), SIGKILL);
	// }
	// write(1, &sample_PID, 50);
	printf("server: signal received\n");
	return (0);
}