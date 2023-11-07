/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:19 by fallan            #+#    #+#             */
/*   Updated: 2023/11/07 18:53:45 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			strlens;

	strlens = ft_strlen(s);
	if (len > strlens)
		len = strlens;
	str = (char *)ft_calloc((len + 1), sizeof(char)); // 
	if (str == NULL)
		return (NULL);
	// ft_bzero(str, ft_strlen(str));
	i = 0;
	if (start <= strlens)
	{
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

/* void ft_print_result(char const *s, unsigned int start, size_t len)
{
	printf("ft_substr on '%s' at \
address '%p' with start = %d and len = %zu, \
yields '%s' at address '%p'\n\n", s, s, start, len, \
	ft_substr(s, start, len), ft_substr(s, start, len));
}

#include <stdio.h>
int	main()
{
	char s[] = "hola"; // Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus.
	unsigned int start = 0;
	size_t len = 1844674407370955161;

	ft_print_result(s, start, len);
	// ft_print_result(s, start + 2, len - 3);
	
	return (0);
} */