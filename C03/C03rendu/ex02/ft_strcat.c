char	*ft_strcat(char *dest, char *src)
{
int	i;
int size;
	
i = 0;
size = 0;
while (dest[size] != 0)
size++;
while (src[i] != 0)
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
printf("my function: resulting string is \"%s\".\n", ft_strcat(dest, src));
printf("dest is \"%s\".\n", dest);
printf("strcat: resulting string is \"%s\".\n", strcat(dest, src));
return (0);
} */