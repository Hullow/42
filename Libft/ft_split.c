/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:21:41 by francis           #+#    #+#             */
/*   Updated: 2023/11/07 19:58:15 by francis          ###   ########.fr       */
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

/* #include <stdio.h>
int main()
{
	char c = 'C';
	
	// char *s1 = "";
	// char *s2 = "CCCCCC";
	// char *s3 = "CBonjour";
	// char *s4 = "BonjourC";
	// char *s5 = "CCCBonjour";
	// char *s6 = "CCCCBonjourC";
	// char *s7 = "BonjourCCCChello";
	// char *s8 = "BonjourChelloC";
	char *s9 = "CBonjourChelloCgoodbyeC";

	
	printf("input: %s\n\n", s9);

	char **split = ft_split(s9, c);
	printf("main:Hello, this is the main from ft_split\n");
	printf("\noutput:\n");
	int i = 0;
	int j = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			printf("%c", split[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");

	// ft_split(s2, c);
	// ft_split(s3, c);
	// ft_split(s4, c);
	// ft_split(s5, c);
	// ft_split(s6, c);
	// ft_split(s7, c);
	// ft_split(s8, c);
	// ft_split(s9, c);


	// int words = ft_count_words(s1, c);
	// int words2 = ft_count_words(s2, c);
	// int words3 = ft_count_words(s3, c);
	// int words4 = ft_count_words(s4, c);
	// int words5 = ft_count_words(s5, c);
	// int words6 = ft_count_words(s6, c);
	// int words7 = ft_count_words(s7, c);
	// int words8 = ft_count_words(s8, c);
	// int words9 = ft_count_words(s9, c);

	// printf("words to split 1: %d\n", words);
	// printf("words to split 2: %d\n", words2);
	// printf("words to split 3: %d\n", words3);
	// printf("words to split 4: %d\n", words4);
	// printf("words to split 5: %d\n", words5);
	// printf("words to split 6: %d\n", words6);
	// printf("words to split 7: %d\n", words7);
	// printf("words to split 8: %d\n", words8);
	// printf("words to split 9: %d\n\n", words9);

	return (0);
} */