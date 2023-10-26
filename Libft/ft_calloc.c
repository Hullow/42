/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:20:12 by fallan            #+#    #+#             */
/*   Updated: 2023/10/26 17:51:41 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	total;
	unsigned char	*filler;

	total = (unsigned int)count * (unsigned int)size;
	ptr = malloc(total);
	filler = (unsigned char *) ptr;
	while (total > 0)
	{
		*filler = '\0';
		filler++;
		total--;
	}
	return (ptr);
}

/* #include <stdlib.h>
#include <stdio.h>
int	main()
{
	size_t count = 3;
	size_t size = 4;

	printf("ft_calloc generates: '%s' at address '%p'\n", \
	(char *)ft_calloc(count, size), ft_calloc(count, size));
	printf("calloc generates: '%s' at address '%p'\n", \
	(char *)calloc(count, size), calloc(count, size));
	return (0);
} */