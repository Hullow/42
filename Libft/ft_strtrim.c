/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:12 by fallan            #+#    #+#             */
/*   Updated: 2023/10/30 11:12:36 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

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
    if (ts1 == NULL)
        return (NULL);
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
#include <stdlib.h>
#include <string.h>
int	main()
{
    char *s;

    s = ft_strtrim("   xxx   xxx", " x");
	printf("ft_strtrim yields '%s'\n", s);

   return (0);
}
*/
