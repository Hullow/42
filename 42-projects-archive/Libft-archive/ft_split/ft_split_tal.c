/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:56 by tkashi            #+#    #+#             */
/*   Updated: 2024/04/02 14:31:33 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// UTILS
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	total_size;
	unsigned char	*filler;

	total_size = (unsigned int)count * (unsigned int)size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	filler = (unsigned char *) ptr;
	while (total_size > 0)
	{
		*filler = '\0';
		filler++;
		total_size--;
	}
	return (ptr);
}

// FT_SPLIT PROPER
int	ft_calc_size(char const *s, char c)
{
	int	prev;
	int	i;
	int	count;

	prev = -1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i - prev - 1 > 0)
				count++;
			prev = i;
		}
		i++;
	}
	if (i - prev - 1 > 0)
		count++;
	return (count);
}

int	ft_add_splitted(char const *s, int start, int end, char **ret)
{
	*ret = ft_substr(s, start + 1, end - start - 1);
	if (*ret == NULL)
		return (0);
	return (1);
}

int	ft_apply_split(char const *s, char c, char **ret)
{
	int	prev;
	int	i;

	prev = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i - prev - 1 > 0)
			{
				if (!ft_add_splitted(s, prev, i, ret))
					return (0);
				ret++;
			}
			prev = i;
		}
		i++;
	}
	if (i - prev - 1 > 0)
	{
		if (!ft_add_splitted(s, prev, i, ret))
			return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;
	int		i;

	size = ft_calc_size(s, c);
	ret = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	if (!ft_apply_split(s, c, ret))
	{
		i = 0;
		while (ret[i] != NULL)
		{
			free(ret[i]);
			i++;
		}
		free(ret);
		return (NULL);
	}
	return (ret);
}

int main()
{
	int i = -1;
	char **ret;

	char *s;
	s = "a b c d e f";
	char c;
	
	c = ' ';

	ret = ft_split(s, c);
	if (ret)
		while (ret[++i])
			printf("ret[%d]: %s\n", i, ret[i]);
	printf("\n");
	ret = NULL;

	// s = "e  b  c  d  e  f";
	// c = ' ';

	// ret = ft_split(s, c);
	// i = -1;
	// if (ret)
	// 	while (ret[++i])
	// 		printf("ret[%d]: %s\n", i, ret[i]);
	// printf("\n");
	// ret = NULL;

	// s = "f   b    c    d e  f";
	// c = ' ';

	// ret = ft_split(s, c);
	// i = -1;
	// if (ret)
	// 	while (ret[++i])
	// 		printf("ret[%d]: %s\n", i, ret[i]);
	// printf("\n");
	// ret = NULL;


	return (0);
}