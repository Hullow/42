/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:38 by fallan            #+#    #+#             */
/*   Updated: 2023/10/24 16:59:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	len;

	len = 0;
	while (s1[len])
		len++;
	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	if (str)
	{
		while (len > 0)
		{
			str[len - 1] = s1[len - 1];
			len--;
		}
	}
	return (str);
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	s1[] = "blablabla";

	printf("strdup copies s1: '%s' at address '%p' \
	to str '%s' at address '%p'\n", s1, s1, strdup(s1), strdup(s1));
	
	//printf("ft_strdup copies s1: '%s' at address '%p' \
	to str '%s' at address '%p'\n", s1, s1, ft_strdup(s1), ft_strdup(s1));
	
	return (0);
} */