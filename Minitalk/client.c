/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:04:21 by francis           #+#    #+#             */
/*   Updated: 2024/07/08 17:16:06 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

void	ft_binary_signal(int server_PID, unsigned int number)
{
	if (number == 0)
	{
		if (kill(server_PID, SIGUSR1) == -1)
		{
			ft_printf("\nclient: kill error");
			exit(-1);
		}
		usleep (100);
	}
	else if (number == 1)
	{
		if (kill(server_PID, SIGUSR2) == -1)
		{
			ft_printf("\nclient: kill error");
			exit(-1);
		}
		usleep (100);
	}
	else
	{
		ft_binary_signal(server_PID, number / 2);
		ft_binary_signal(server_PID, number % 2);
	}
}

int main(int argc, char **argv)
{
	int	server_PID;
	int	killret;

	server_PID = 0;
	killret = -2;
	if (argc == 3)
	{
		server_PID = ft_atoi(argv[1]);
		// int	i = 0;
		// while (argv[2][i] != NULL)
		// 	i++;
		// ft_binary_signal(server_PID, i);
		int i = -1;
		while (argv[2][++i])
		{
			if ((unsigned int) argv[2][i] < 128)
			{
				killret = kill(server_PID, SIGUSR1);
				usleep (100);
				if (killret == -1)
				ft_printf("\nclient: kill error");
			}
			if ((unsigned int) argv[2][i] < 64)
			{
				killret = kill(server_PID, SIGUSR1);
				usleep (100);
				if (killret == -1)
				ft_printf("\nclient: kill error");
			}
			ft_binary_signal(server_PID, (unsigned int) argv[2][i]);
		}
		ft_printf("\n");
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