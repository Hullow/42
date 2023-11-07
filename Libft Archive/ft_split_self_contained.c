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

// do 3-5 directly for each word, rather than 3 for all words, 4, then 5.

// #include "Libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);
unsigned int	ft_findstart(char const *s1, char const *set);
unsigned int	ft_findstop(char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_count_words(char const *s, char c);

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
	character[1] = '\0';
	printf("character[0] is %c\n", character[0]);

	copy = ft_strtrim((char *) s, character);
	printf("input:'%s', trimmed copy: '%s'\n", s, copy);

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
		copy = ft_strtrim(ft_substr(copy, length, ft_strlen(copy) + 1), character); // trims the string by one word and prepares the string for the next loop
		printf("copy: %s\n", copy);
		// free (split[i]);
		i++;
	}
	printf("\noutput:\n");
	i = 0;
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
	return (split);
}

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


/* int main()
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

	ft_split(s9, c);
	printf("main:Hello, this is the main from ft_split\n");
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

/* 
char	**ft_split(char const *s, char c)
{

	return ();
}

char const *s = "BonjourChelloCgoodbyeCciaoChihiCnono";

total length of malloc = strlen(s) + 
 */


// substr: methode de Theo


/* 	while (*s)
	{
 		s = strchr(s, c); // ses for the next occurrence of c
		if (s == NULL)
			return (words); // if it doesn't find c, return the present number of words.
		while (*s == c)
			s++;

	} */


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

unsigned int	ft_findstart(char const *s1, char const *set);
unsigned int	ft_findstop(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ts1;
	unsigned int	start;
	unsigned int	stop;

	start = ft_findstart(s1, set);
	stop = ft_findstop(s1, set);
	ts1 = (char *)malloc((stop - start + 1) * sizeof(char));
	if (ts1 == NULL)
		return (NULL);
	ft_strlcpy(ts1, &s1[start], stop - start + 1);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)ft_calloc((len + 1), sizeof(char)); // 
	if (str == NULL)
		return (NULL);
	// ft_bzero(str, ft_strlen(str));
	i = 0;
	if (start <= ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}