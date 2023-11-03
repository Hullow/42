#include "Libft.h"

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
#include <string.h>
int main()
{
	char src[] =  "abcd"; // srclen == 4
	char src2[] = "abcd";

	char dst[] =  "pqrstuvwxyz"; // dstlen == 11
	char dst2[] = "pqrstuvwxyz";

	size_t dstsize = 20;
	printf("for src '%s' and dst '%s', with dstsize = %lu,\n", src, dst, dstsize);
	printf("strlcat yields    '%s' with return value '%lu'\n", dst, strlcat(dst, src, dstsize));
	printf("strlen(dst) is %lu\n\n", strlen(dst));

	printf("for src '%s' and dst '%s', with dstsize = %lu,\n", src2, dst2, dstsize);
	printf("ft_strlcat yields '%s' with return value '%lu'\n", dst2, ft_strlcat(dst2, src2, dstsize));
	printf("strlen(dst) is %lu\n", strlen(dst2));

	return (0);
} */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	// printf("ft_strlen(dst) is %lu\n", dstlen);
	// printf("ft_strlen(src) is %lu\n", ft_strlen(src));
	if (dstsize > 0 && dstlen < dstsize)
	{
		while (i < dstsize - dstlen - 1)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	// else if (dstsize == 0)
	//  && dstlen >= dstsize)
	// {

	// }

	return (dstlen + ft_strlen(src));
}
























/* #include <stdio.h>
#include <string.h>
int main()
{
	char src[50] = "djdjdjd glou glou glou";
	char dst1[50];
	char dst2[50];

	size_t	result;
	size_t	dstsize = 0;

	result = strlcat(dst1, src, dstsize);
	printf("strlcat: dst is now %s\n, return value is %lu\n", dst1, result);

	result = ft_strlcat(dst2, src, dstsize);
	printf("ft_strlcat: dst is now %s, return value is %lu\n", dst2, result);
	strlcat();
	return (0);
} */