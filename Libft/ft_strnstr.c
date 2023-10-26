/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:23:56 by fallan            #+#    #+#             */
/*   Updated: 2023/10/18 15:23:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*anchor;
	unsigned int	start;

	start = 0;
	anchor = (char *) haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && *needle && len > 0)
	{
		if (*needle == *haystack)
		{
			needle++;
			haystack++;
			len--;
		}
		else
		{
			haystack++;
			start++;
			len--;
		}
	}
	if (*needle == '\0')
		return (anchor + start);
	else
		return (NULL);
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	char	haystack[] = {'a', 'c', 'd', 'a', 'b', 'a', 'c', 'd', 'e', 'c', 'd', 'e', 'f', '\0'};

	char	needle0[] = "";
	char	needle1[] = {'c', '\0'};
	char	needle2[] = {'g', '\0'};
	char	needle3[] = {'c', 'd', '\0'};

	size_t	len = 15;
	printf("strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n", needle0, haystack, strnstr(haystack, needle0, len), strnstr(haystack, needle0, len));
	printf("ft_strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n\n", needle0, haystack, ft_strnstr(haystack, needle0, len), ft_strnstr(haystack, needle0, len));

	printf("strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n", needle1, haystack, strnstr(haystack, needle1, len), strnstr(haystack, needle1, len));
	printf("ft_strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n\n", needle1, haystack, ft_strnstr(haystack, needle1, len), ft_strnstr(haystack, needle1, len));

	printf("strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n", needle2, haystack, strnstr(haystack, needle2, len), strnstr(haystack, needle2, len));
	printf("ft_strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n\n", needle2, haystack, ft_strnstr(haystack, needle2, len), ft_strnstr(haystack, needle2, len));

	printf("strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n", needle3, haystack, strnstr(haystack, needle3, len), strnstr(haystack, needle3, len));
	printf("ft_strnstr, looking for '%s' in '%s', produces '%s' which is at address '%p'\n", needle3, haystack, ft_strnstr(haystack, needle3, len), ft_strnstr(haystack, needle3, len));
	return (0);
} */