/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:39:00 by fallan            #+#    #+#             */
/*   Updated: 2023/08/04 00:07:15 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	calculate_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	str_num;
	int	sep_len;
	int	i;

	i = 0;
	sep_len = 0;
	str_num = 0;
	while (sep[sep_len])
		sep_len++;
	while (strs[str_num])
		str_num++;
	if (str_num > 0)
	{
		total_size = (size + ((str_num - 1) * (sep_len)));
		return (total_size);
	}
	else
		return (0);
}

char	*fill_str(char *result, int total_size, char **strs, char *sep)
{
	int		r;
	int		i;
	int		j;
	int		k;

	r = 0;
	i = 0;
	while (r < total_size)
	{
		while (strs[i])
		{
			j = 0;
			while (strs[i][j])
				result[r++] = strs[i][j++];
			k = 0;
			while (sep[k])
				result[r++] = sep[k++];
			i++;
		}
	}
	result[r] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_size;

	if (strs == NULL)
		return (0);
	if (size == 0)
		result = NULL;
	total_size = calculate_size(size, strs, sep);
	result = malloc(total_size * sizeof(char));
	if (result == NULL)
		return (0);
	result = fill_str(result, total_size, strs, sep);
	return (result);
}

/* int	main()
{
	char *sep = " aaa! ";
	char *strs[] = {"blob", "sqrt", "horny", "ben", NULL};
	char *result = ft_strjoin(21, strs, sep);

	printf("%s\n", result);
	free(result);
	return (0);
} */

/* 		while (tab[i] >= 10 && tab[i] <= 19)
		{
			printf("%d ", tab[i]);
			i++;
		}
		printf("\n"); */