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
char	*ft_next_lines(char *dst, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\n' && src[i] && i < BUFFER_SIZE)
		i++;
	if (!src[i] || i == BUFFER_SIZE)
		return (0);
	else if (src[i++] == '\n')
	{
		if (src[i] == '\0')
			return (0); // issue if \n\n somewhere
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

char	*next_line(char *input)
{
	static char     *next_lines;
	char			*buf;
	
	printf("size of next_lines: %zu\n", sizeof(next_lines));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	printf("buf address: {%p}\n", buf);
	printf("next_lines address: {%p}\n", next_lines);
	strlcpy(buf, input, BUFFER_SIZE);
	printf("buf address: {%p}\n", buf);

	next_lines = ft_next_lines(buf);
	// printf("buf: \"%s\"\n", buf); // next_lines: \"%s\"\n", buf); //, next_lines);
	// free(buf);
	return (0);
}

int main()
{
	char *input = "aaaaaaaaa\nbbbbbbbbb";
	char *input2 = "ccccccccc\nddddddddd";
	printf("next_line(input) is '\"%s\"\n\n", next_line(input));
	printf("next_line(input2) is '\"%s\"\n", next_line(input2));
	return (0);

}
