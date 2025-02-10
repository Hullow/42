/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:24:00 by francis           #+#    #+#             */
/*   Updated: 2025/01/16 18:32:42 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int main()
{
	int				i;
	unsigned char	forks[200];


	memset(&forks[0], 48, 9 * sizeof(unsigned char));
	memset(&forks[8], '1', sizeof(unsigned char));
	
	i = -1;
	while (++i < 10)
		printf("forks[%d]: %c\n", i, forks[i]);
	return (0);
}