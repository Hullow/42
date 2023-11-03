// count # of words, i.e # of char c
// calloc an array of # strings
// 3 count length of each word, i.e strchr - search_pointer iteratively (or use strrchr maybe)
// 4 malloc iteratively an array each word in the array of strings
// 5 copy iteratively each word, using strlcpy, to the array of strings

// do 3-5 directly for each word, rather than 3 for all words, 4, then 5.

#include <string.h>

size_t	ft_count_words(char const *s, char c)
{
	size_t words;
	char	*search;

	words = 0;
	search = (char *) s;
	search = strchr(search, c); // searches for the next occurrence of c
	if (search == NULL)
		return (words);
	words++;
	while (*search)
	{
		search = strchr(search, c); // searches for the next occurrence of c
		if (search == NULL)
			return (words);
		while (*search == c)
			search++;
		if (*search)
			words++;
	}
	return (words);
}

#include <stdio.h>
int main()
{
	char *s = "cAAAccccBBBcCCCccccS";
	char c = 'c';

	int words = ft_count_words(s, c);

	printf("word count: %d\n", words);
	return(0);
}

/* 
char	**ft_split(char const *s, char c)
{

	return ();
}

char const *s = "BonjourChelloCgoodbyeCciaoChihiCnono";

total length of malloc = strlen(s) + 
 */


// substr: methode de Theo