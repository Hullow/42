/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:37 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:26:44 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (1);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	character;

	character = 'i';

	printf("The return value of tupper is %c\n", toupper(character));
	printf("The return value of ft_tupper is %c\n", ft_toupper(character));
	printf("The variable character is now equal to: %c\n", character);
		return (0);
} */