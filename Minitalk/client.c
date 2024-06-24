/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:04:21 by francis           #+#    #+#             */
/*   Updated: 2024/06/20 19:02:43 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	sleep(1);
	if (argc > 1)
	{
		printf("argv[1]: %s, argv[2]: %s\n", argv[1], argv[2]);
		printf("argv[1]: %s, argv[2]: %s\n", argv[1], argv[2]);
	}
	// pause();
	printf("client: ok\n");
	return (0);
}
