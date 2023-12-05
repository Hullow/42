/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:22:21 by fallan            #+#    #+#             */
/*   Updated: 2023/07/31 21:23:09 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, (str + i), 1);
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	if (argc > 0)
	ft_putstr(argv[1]);	
//	printf("Your string's characters are %s\n", ft_putstr(argv[1]));
	return (0);
}*/
