#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int    ft_findstart(char const *s1, char const *set);
unsigned int    ft_findstop(char const *s1, char const *set);
size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t    ft_strlen(const char *str);
char *ft_strtrim(char const *s1, char const *set);

int    main()
{
    printf("ft_strtrim yields '%s'\n", \
    ft_strtrim("bgdfdfffc", "bc"));
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char            *ts1 = NULL;
    unsigned int    start;
    unsigned int    stop;

    start = ft_findstart(s1, set);
    stop = ft_findstop(s1, set);
    // ts1 = (char *)malloc((stop - start - 10) * sizeof(char)); // stop - start is 4
    // if (ts1 == NULL)
    //     return (NULL);
    ft_strlcpy(ts1, &s1[start], stop - start + 1); // stop - start + 1 is 5, ie desired string length + \0
    return (ts1);
}

unsigned int    ft_findstart(char const *s1, char const *set)
{
    unsigned int    j;
    unsigned int    start;

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

unsigned int    ft_findstop(char const *s1, char const *set)
{
    unsigned int    j;
    unsigned int    stop;

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

size_t    ft_strlen(const char *str)
{
    int    length;

    length = 0;
    while (str[length] != 0)
        length++;
    return (length);
}

size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    unsigned long                i;

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
    return (sizeof(src));
}