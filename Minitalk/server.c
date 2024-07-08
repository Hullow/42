/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:10:50 by fallan            #+#    #+#             */
/*   Updated: 2024/07/08 17:11:14 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	handler_binary(int signum)
{	
	if (signum == SIGUSR1) // if bit is 0
	{
		// printf("\nhandler: SIGUSR1, byte is %d and multiplicator is %d\n", byte, multiplicator);
		write(1, "0", 1);
	}
	else if (signum == SIGUSR2) // if bit is 1
	{
		write(1, "1", 1);
	}
}

void	handler(int signum)
{
	static int	byte = 0;
	static int 	multiplicator = 64;
	// char		*string;
	// static int	strlen;
	// static int	lengthflag;

	// strlen = 0;
	// lengthflag = 8;
	// if (lengthflag == 0)
	// {

	// 	return ;
	// }
	if (signum == SIGUSR1 && multiplicator) // if bit is 0
	{
		multiplicator /= 2;
	}
	else if (signum == SIGUSR2 && multiplicator) // if bit is 1
	{
		byte += multiplicator;
		multiplicator /= 2;
	}
	if (multiplicator == 0)
	{
		write(1, &byte, 1); // maybe malloc instead
		// string = malloc (sizeof(char));
		// string++;
		// strlen++;
		byte = 0;
		multiplicator = 64;
		kill(getpid(), SIGUSR1);
	}
}

int main()
{
	pid_t				sample_PID;
	struct	sigaction	sigact;

	sample_PID = getpid();
	ft_printf("%d\n", sample_PID);
	// first send one byte with (decimal) length of character string

	sigact.sa_handler = handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
	{
		pause();
	}
	ft_printf("\n");
	return (0);
}