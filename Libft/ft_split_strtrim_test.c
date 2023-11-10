#include "Libft.h"
#include <stdlib.h>

unsigned int	ft_findstart(char const *s1, char const *set);
unsigned int	ft_findstop(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
    char			*ts1;
    unsigned int	start;
    unsigned int	stop;

    start = ft_findstart(s1, set);
    stop = ft_findstop(s1, set);
    if (start > stop)
        stop = start;
    ts1 = (char *)malloc((stop - start + 1) * sizeof(char));
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

/*
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
//	split[i] = "";
    return (split);
}*/

int main()
{
	char c;
    char 	*s = "hello!"; // "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
    char    *copy;
    char	character[1];

    c = ' ';
    character[0] = (char) c;
    copy = s;
    copy = ft_strtrim((char *) s, (char *)character);
/*	char **split = ft_split(string, c);
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
	printf("split %d is '%s'\n", i, split[i]);*/
	return (0);
}
