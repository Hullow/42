/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:12 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:24:13 by fallan           ###   ########.fr       */
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


/* ft_strtrim(char const *s1, char const *set)
{
	char const	*s2;
	ft_strlen
	s2 = s1;
	while (s1)
	{
		while (set)
			{
				if (s1[i] == set[j])
					i++;
				else
				{
					length++;
					i++;
				}
			}

	}
	while (s1)
	{

	}
	return (ts1);
} */
