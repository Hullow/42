/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:04:09 by fallan            #+#    #+#             */
/*   Updated: 2023/11/10 11:24:36 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
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
			count++;
		}
	}
	return (count);
}

size_t	ft_word_length(char *copy, char c)
{
	size_t	length;

	length = 0;
	while (copy[length] != c && copy[length])
		length++;
	return (length);
}

char	*ft_add_word(char *string, char *copy, size_t length)
{
	size_t	j;

	string = (char *)malloc((length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	j = 0;
	while (j < length)
	{
		string[j] = copy[j];
		j++;
	}
	string[j] = '\0';
	return (string);
}

char	*ft_trim_string(char *copy, char *character)
{
	char	*substr;
	char	*trimmed;
	size_t	wordlength;
	size_t	copylength;

	copylength = ft_strlen(copy);
	wordlength = ft_word_length(copy, character[0]);
	substr = ft_substr(copy, wordlength, copylength + 1);
	trimmed = ft_strtrim(substr, character);
	ft_strlcpy(copy, trimmed, copylength);
	free(substr);
	free(trimmed);
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	count;
	char	*copy;
	char	character[1];

	split = NULL;
	split = ft_calloc(ft_count_words(s, c) + 1, sizeof (char *));
	if (split == NULL)
		return (NULL);
	character[0] = (char) c;
	copy = ft_strtrim((char *) s, character);
	count = ft_count_words(copy, c);
	i = 0;
	while (i < count)
	{
		split[i] = ft_add_word(split[i], copy, ft_word_length(copy, c));
		ft_trim_string(copy, character);
		i++;
	}
	split[i] = "";
	return (split);
}

/* int main()
{
	char 	*string = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char	c = ' ';

	char **split = ft_split(string, c);

	unsigned int count = ft_count_words(string, c);
	printf("count is %d\n", count);
	char character[1];
	character[0] = (char) c;
	unsigned int i = 0;
	while (i < count)
	{
		printf("split %d is '%s'\n", i, split[i]);
		i++;
	}
	printf("split %d is '%s'\n", i, split[i]);
	return (0);
} */