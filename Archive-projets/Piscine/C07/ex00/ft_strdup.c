/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:42:20 by fallan            #+#    #+#             */
/*   Updated: 2023/08/03 23:56:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(i * sizeof(char));
	if (copy == NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}
	else
	{
	i = 0;
		while (src[i])
		{
			copy[i] = src[i];
			i++;
		}
	copy[i] = '\0';
		return (copy);
	}
}
/* int main()
{
	char *result = ft_strdup("just a string:");
	printf("My function: %s\n", result);

	char *benchmark = strdup("just a string:");
	printf("strdup: %s\n", benchmark);

	if (strcmp(result, benchmark) == 0)
		printf("the strings are the same according to strcmp\n");
	free(result);
	free(benchmark);
	return (0);
} */