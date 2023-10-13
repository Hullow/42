#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int	i;
	unsigned char *s1 = (unsigned char *) src;
	unsigned char *s2 = (unsigned char *) dst;

	i = 1;

/* 	if (dst > src  && src + len >= dst)
	{ */
		while (i <= len)
		{
			s2[len - i] = s1[len - i];
			i++;
		}
/* 	}
	else
	{
		while (len > 0)
		{
			
		}
	} */
	return (dst);
}

int	main()
{
	char *src = "Blablabla";
	char dest[50];

	strcpy(dest, "Hello");

	printf("src is: '%s'\n", src);
	printf("dest is: '%s'\n\n", dest);

	memmove(dest, src, sizeof(src)+1);
	printf("dest after memmove is: '%s'\n\n", dest);

	strcpy(dest, "Hello");
	printf("dest is re-initialized to:'%s'\n\n", dest);

	ft_memmove(dest, src, sizeof(src)+1);
	printf("dest after ft_memmove is: '%s'\n", dest);

	return (0);
}