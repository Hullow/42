/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:50 by fallan            #+#    #+#             */
/*   Updated: 2024/07/06 22:14:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	handler(int signum)
{
	static int	byte = 0;
	static int 	multiplicator = 64;
	
	// ft_printf("\nserver: handler called\n");
	if (signum == SIGUSR1 && multiplicator) // if bit is 0
	{
		// printf("\nhandler: SIGUSR1, byte is %d and multiplicator is %d\n", byte, multiplicator);
		multiplicator /= 2;
	}
	else if (signum == SIGUSR2 && multiplicator) // if bit is 1
	{
		// printf("\nhandler: SIGUSR2, byte is %d and multiplicator is %d\n", byte, multiplicator);
		byte += multiplicator;
		multiplicator /= 2;
	}
	if (multiplicator == 0)
	{
		// printf("\nhandler: end reached, byte is %d and multiplicator is %d\n", byte, multiplicator);
		write(1, &byte, 4);
		byte = 0;
		multiplicator = 64;
	}
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
	{
		pause();
		// ft_printf("\nserver: signal received\n");
	}
	return (0);
}