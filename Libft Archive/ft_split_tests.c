// 1. count # of words, i.e # of char c (nb: if # words == 0, return the original string)
// 2. calloc an array of # strings
// 3. count length of each word, i.e strchr - search_pointer iteratively (or use strrchr maybe)
// 4. malloc iteratively an array each word in the array of strings
// 5. copy iteratively each word, using strlcpy, to the array of strings

// do 3-5 directly for each word, rather than 3 for all words, 4, then 5.

#include <string.h>

size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	char	*search;

	words = 0;
	search = (char *) s;
	while (*search)
	{
		if (*search == c)
		{	
			while (*search == c)
				search++;
		}
		else
		{	
			while (*search != c && *search)
				search++;
			words++;
		}
	}
	return (words);


}
// ft_count_word tests
#include <stdio.h>
int main()
{
	char c = 'C';
	
	char *s1 = "";
	char *s2 = "CCCCCC";
	char *s3 = "CBonjour";
	char *s4 = "BonjourC";
	char *s5 = "CCCBonjour";
	char *s6 = "CCCCBonjourC";
	char *s7 = "BonjourCCCChello";
	char *s8 = "BonjourChelloC";
	char *s9 = "CBonjourChelloCgoodbye";

	int words = ft_count_words(s1, c);
	int words2 = ft_count_words(s2, c);
	int words3 = ft_count_words(s3, c);
	int words4 = ft_count_words(s4, c);
	int words5 = ft_count_words(s5, c);
	int words6 = ft_count_words(s6, c);
	int words7 = ft_count_words(s7, c);
	int words8 = ft_count_words(s8, c);
	int words9 = ft_count_words(s9, c);

	printf("words to split 1: %d\n", words);
	printf("words to split 2: %d\n", words2);
	printf("words to split 3: %d\n", words3);
	printf("words to split 4: %d\n", words4);
	printf("words to split 5: %d\n", words5);
	printf("words to split 6: %d\n", words6);
	printf("words to split 7: %d\n", words7);
	printf("words to split 8: %d\n", words8);
	printf("words to split 9: %d\n", words9);

	return (0);
}