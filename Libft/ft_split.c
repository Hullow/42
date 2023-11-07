/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:21:41 by francis           #+#    #+#             */
/*   Updated: 2023/11/07 20:29:45 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
		{	
			while (*s == c)
				s++;
		}
		else
		{
			while (*s != c && *s)
				s++;
			words++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split = NULL;
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	length;
	char	*copy;
	char character[1];

	count = ft_count_words(s, c);
	split = ft_calloc(count + 1, sizeof(char));
	if (split == NULL)
		return (NULL);
	character[0] = (char) c;
	copy = ft_strtrim((char *) s, character);
	i = 0;
	while (i < count)
	{
		length = 0;
		while (copy[length] != c && copy[length])
			length++;
		split[i] = malloc((length + 1) * sizeof(char));
		if (split[i] == NULL)
			return (NULL);
		j = 0;
		while (j < length)
		{
			split[i][j] = copy[j];
			j++;
		}
		split[i][j] = '\0';
		copy = ft_strtrim(ft_substr(copy, length, ft_strlen(copy) + 1), character);
		i++;
	}
	return (split);
}