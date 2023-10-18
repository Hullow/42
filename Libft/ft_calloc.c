/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:20:12 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:20:15 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	total;
	
	total = (unsigned int)count * (unsigned int)size;
	ptr = malloc(total);
	unsigned char	*filler = (unsigned char*) ptr;
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

	printf("calloc generates a pointer with value(s): '%s' at address '%p'\n", calloc(count, size), calloc(count, size));
	printf("ft_calloc generates a pointer with value(s): '%s' at address '%p'\n", ft_calloc(count, size), ft_calloc(count, size));
	return (0);
} */