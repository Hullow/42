/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:04:21 by francis           #+#    #+#             */
/*   Updated: 2024/06/28 18:39:37 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

#include <errno.h>

int main(int argc, char **argv)
{
	int	server_PID;

	if (argc == 3)
	{
		server_PID = ft_atoi(argv[1]);
		printf("argv[1]: %d\n", server_PID);
	}
	else
		ft_printf("please input args\n");
	// pause();
	int killret = kill(server_PID, SIGUSR1);
	printf("client: kill returned %d\n", killret);
	if (killret == -1)
		perror("kill error:");
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