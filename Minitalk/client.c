/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:04:21 by francis           #+#    #+#             */
/*   Updated: 2024/07/01 19:55:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

#include <errno.h>

void	ft_binary(int server_PID, unsigned int number)
{
	int killret;
	
	killret = -2;
	if (number == 0)
	{
		killret = kill(server_PID, SIGUSR1);
		if (killret == -1)
			perror("\nkill error:");
	}
	else if (number == 1)
	{
		kill(server_PID, SIGUSR2);
		if (killret == -1)
			perror("\nkill error:");
	}
	else
	{
		ft_binary(server_PID, number / 2);
		ft_binary(server_PID, number % 2);
	}
}

int main(int argc, char **argv)
{
	int	server_PID;

	server_PID = 0;
	if (argc == 3)
	{
		server_PID = ft_atoi(argv[1]);
		ft_printf("argv[1]: %d\n", server_PID);
		ft_printf("argv[2]: %s\n", argv[2]);
		int	i = -1;
		while (argv[2][++i])
		{
			// ft_printf("c");
			ft_binary(server_PID, argv[2][i]);
		}
	}
	else
		ft_printf("please input args\n");
	return (0);
}


/* 
Vous pouvez utiliser une variable globale par programme (une pour le client
et une pour le serveur) mais leur usage doit être justifié.

◦write
◦ft_printf et tout équivalent que VOUS avez codé
◦signal
◦sigemptyset
◦sigaddset
◦sigaction
◦kill
◦getpid
◦malloc
◦free
◦pause
◦sleep
◦usleep
◦exit
*/