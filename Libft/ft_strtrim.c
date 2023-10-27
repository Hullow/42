/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:12 by fallan            #+#    #+#             */
/*   Updated: 2023/10/27 15:29:23 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

unsigned int	ft_findstart(char const *s1, char const *set);
unsigned int	ft_findstop(char const *s1, char const *set);

char *ft_strtrim(char const *s1, char const *set)
{
	char			*ts1;
	unsigned int	start;
	unsigned int	stop;

	start = ft_findstart(s1, set);
		// printf("start is %d\n", start);
	stop = ft_findstop(s1, set);
		// printf("stop is %d\n", stop);
		// printf("stop - start + 1 is %d\n", stop - start + 1);
	ts1 = (char *)malloc((stop - start + 1) * sizeof(char)); // stop - start is 4
	if (ts1 == NULL)
		return (NULL);
	// printf("s1[start] is %c\n", s1[start]);
	// printf("s1[stop + 1] is %c\n", s1[stop + 1]);
	ft_strlcpy(ts1, &s1[start], stop - start + 1); // stop - start + 1 is 5, ie desired string length + \0
	return (ts1);
}

unsigned int	ft_findstart(char const *s1, char const *set)
{
	unsigned int	j;
	unsigned int	start;

	j = 0;
	start = 0;
	while (s1[start] && set[j])
	{
		if (s1[start] == set[j])
		{
			start++;
			j = 0;
		}
		else
			j++;
	}
	return (start);
}

unsigned int	ft_findstop(char const *s1, char const *set)
{
	unsigned int	j;
	unsigned int	stop;

	j = 0;
	stop = ft_strlen(s1);
	while (stop > 0 && set[j])
	{
		if (s1[stop - 1] == set[j])
		{
			stop--;
			j = 0;
		}
		else
			j++;
	}
	return (stop);
}

#include <stdlib.h>
int	main()
{
	printf("ft_strtrim yields '%s'\n", \
	ft_strtrim("bcbcghghcabc", "aaaacebacccccddd"));
	return (0);
}