#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

/* 
char	*ft_next_lines(char *src)
{
	unsigned int	i;
	char 			*dst;

	dst = NULL;
	i = 0;
	while (src[i] != '\n' && src[i] && i < BUFFER_SIZE)
		i++;
	if (!src[i] || i == BUFFER_SIZE)
		return (0);
	else if (src[i++] == '\n')
	{
		if (src[i] == '\0')
			return (0);
		else
		{
			while (src[i] && i < BUFFER_SIZE)
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (dst);
	}
	else
		return (0);
}
 */
char	*ft_next_lines(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0' && i < BUFFER_SIZE)
		i++;
	if (buf[i++] == '\n')
	{
		if (buf[i] == '\0')
			return (0);
		else
			return (buf + i);
	}
	else
		return (0);
}

char	*next_line(char *input)
{
	static char     *next_lines = NULL;
	char			*buf;
	
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	printf("buf address: {%p}\n", buf);
	strlcpy(buf, input, BUFFER_SIZE);
	printf("buf address: {%p}\n", buf);

	next_lines = ft_next_lines(buf);
	printf("buf: \"%s\"\nnext_lines: \"%s\"\n", buf, next_lines);
	free(buf);
	return (next_lines);
}

int main()
{
	char *input = "aaaaaaa\nbbbbbbb";
	char *input2 = "ccccccc\nddddddd";
	printf("next_line(input) is '\"%s\"\n\n", next_line(input));
	printf("next_line(input2) is '\"%s\"\n", next_line(input2));
	return (0);

}