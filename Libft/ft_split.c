/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:21:41 by francis           #+#    #+#             */
/*   Updated: 2023/11/09 19:55:09 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. count # of words (nb: if # words == 0, return NULL I guess. if # words == 1, return ft_strtrim(string))
// 2. calloc an array of # strings
// 3. copy the original, trimmed string (ft_strtrim) within the ft_split function (with malloc?)
// iteratively:
// 4. count length n of beginning of string to char c, i.e strchr - s_pointer iteratively (or use strrchr maybe)
// 5. in ft_split, malloc an array of length (n + 1)
// 6. copy that string to the malloc-ated string in ft_split: ft_strlcpy ? ft_memcpy ?
// 7. trim the string from its first n characters using ft_substr: s= string, start = n, len = ft_strlen(s) - n
// free the malloc from ft_substr ?
// 8. in ft_split, got to the next string in the array
// 9. copy iteratively each word, using strlcpy, to the array of strings

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

	count = ft_count_words(s, c); // counts the number of words in the string

	split = ft_calloc(count + 1, sizeof(char*)); // allocates memory for an array of #count strings (+ 1 empty string at the end)
	if (split == NULL)
		return (NULL);

	character[0] = (char) c; // typecast the separator as a string to allow use in strtrim

	copy = ft_strtrim((char *) s, character); // trims the input string from the separator character at the beginning and the end

	i = 0;

/*
char **ft_add_word(char *string, char *copy, char c) // inputs: split[i], which is a pointer at a given index, i.e. a string, to be filled 
{
	size_t	length; // => probably not necessary, could have only j, but let's start with this
	size_t	j;

	length = 0;
	j = 0;

	while (copy[length] != c && copy[length])
		length++;

	split[i] = (char *)malloc((length + 1) * sizeof(char)); // allocate memory for the string in the array; n.b. need to change [i] here
	if (split[i] == NULL)
		return (NULL);

	j = 0; // start the index at the first character of the string
	while (j < length) // => transform this to remove length and stay with j
	{
		split[i][j] = copy[j]; // fill the string with each character
		j++;
	}

	split[i][j] = '\0'; // null-terminates the string
	return 
}
*/


/* ft_trim_string // remove the first word and the separator characters from the beginning and end of the string

*/

	while (i < count)
	{
		length = 0;

		while (copy[length] != c && copy[length])
			length++;

		split[i] = (char *)malloc((length + 1) * sizeof(char)); // allocate memory for the string in the array
		if (split[i] == NULL)
			return (NULL);

// ft_add_word (split[i], copy)

		j = 0; // start the index at the first character of the string
		while (j < length)
		{
			split[i][j] = copy[j]; // fill the string with each character
			j++;
		}

		split[i][j] = '\0'; // null-terminates the string

		char *substr = ft_substr(copy, length, ft_strlen(copy) + 1); // removes the initial word of the string
		char *trimmed = ft_strtrim(substr, character); // removes the separator character at the beginning and the end
		ft_strlcpy(copy, trimmed, ft_strlen(copy)); // copies the trimmed string back to 'copy'
		free(substr); // frees the memory used in the previous two operations
		free(trimmed);
	
		i++; // increments the index to point to the next string in the array to be filled
	}


	split[i] = ""; // adds an empty string at the end of the array
	return (split);
}

int main()
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
	// free(split);
	return (0);
}