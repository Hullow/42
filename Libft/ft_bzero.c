
void	ft_bzero (void *s, unsigned int n)
{
	unsigned char *str = (unsigned char*) s;

	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

#include <strings.h>
#include <stdio.h>

int main ()
{
	char str[6] = "Blabla";

/* 	bzero(str, 3);
	puts(str);
	puts(str+3); */

	ft_bzero(str, 3);
	puts(str);
	puts(str+3);

	return (0);
}