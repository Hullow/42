/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:23:34 by fallan            #+#    #+#             */
/*   Updated: 2023/07/31 21:23:51 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen] != 0)
		strlen++;
	return (strlen);
}

/* int	main(int argc, char **argv)
{
	if (argc > 0)
		printf("Your string has %s characters\n", ft_strlen(argv[1]));
	return (0);
} */
