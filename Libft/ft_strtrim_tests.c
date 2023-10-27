/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:12 by fallan            #+#    #+#             */
/*   Updated: 2023/10/27 04:19:45 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

// To do :
// 1) Starting from the beginning of the string, evaluate each char of s1 for each char of set.
// 1.1) If member of set, increment _start_. If not member, (next step)
// Then do the same from the end: evaluate each char of s1 for each of set.
// 1.2) If member of set, decrement _stop_, which was initialized to strlen(s1) (-1?)
// If not member of set, (next step)
// We now have start and stop. (stop - start) is the length of our desired string.
// 2) Calloc a string of length (stop - start) (this fills it with zeroes)
// 3) Start filling our empty string with the characters from the trimmed string: 
// while s1 from start to stop


char *ft_strtrim(char const *s1, char const *set)
{
	unsigned int	j;
	unsigned int	start;
	unsigned int	stop;

	j = 0;
	start = 0;
	stop = ft_strlen(s1); // (== '\0' by definition, because strlen doesnteg 100 characters long, not including null terminator. So str[strlen]=='\0' by definition
	printf("stop is '%d', meaning s1['%d'] is '%c', and s1['%d'] is '%c'\n", stop, stop, s1[stop], stop - 1, s1[stop-1]);
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
	printf("start is '%d', meaning s1['%d'] is '%c'\n", start, start, s1[start]);
	j = 0;
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
	printf("after manipulation stop is now '%d', meaning s1['%d'] is '%c', and s1['%d'] is '%c'\n", stop, stop, s1[stop], stop - 1, s1[stop-1]);
	char	*ts1;
	ts1 = calloc(stop - start, sizeof(char));
	if (ts1 == NULL)
		return (NULL);
	ft_strlcpy(ts1, &s1[start], stop - start + 1);
	printf("stop - start is: '%d'\n", stop - start);
	printf("address of s1 is: '%p', address of s1[start] is '%p', difference is '%ld'\n", s1, &s1[start], &s1[start] - s1);
	printf("ts1 is: '%s'\n", ts1);
	return(ts1);
	}

#include <stdlib.h>
int	main()
{
	printf("ft_strtrim yields '%s'\n", ft_strtrim("aabcabSimoancacabab", "cab"));
	return (0);
}