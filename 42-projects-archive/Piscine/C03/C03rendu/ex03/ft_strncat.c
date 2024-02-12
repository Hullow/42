char *ft_strncat(char *dest, char *src, unsigned int nb)
{
unsigned int i;
int size;

i = 0;
size = 0;
while (dest[size] != 0)
size++;
while (src[i] != 0 && i < nb)
{
dest[size+i] = src[i];
i++;
}
dest[size+i] = 0;
return (dest);
}

/* 
#include <string.h>
#include <stdio.h>
int	main(void)
{
char	dest[] = "42 ";
char	src[] = "Network";
unsigned int nb = 6;

printf("my function: resulting string is \"%s\".\n", ft_strncat(dest, src, nb));
printf("dest is \"%s\".\n", dest);
printf("strcat: resulting string is \"%s\".\n", strncat(dest, src, nb));
return (0);
} */