/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:50 by fallan            #+#    #+#             */
/*   Updated: 2024/07/01 19:21:30 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("0");
	}
	else if (signum == SIGUSR2)
		ft_printf("1");
}

int main()
{
	pid_t				sample_PID;
	struct	sigaction	sigact;

	sample_PID = getpid();
	ft_printf("%d\n", sample_PID);
	sigact.sa_handler = handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	ft_printf("\nserver: signal received\n");
	return (0);
}