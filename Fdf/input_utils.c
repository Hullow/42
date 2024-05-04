/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:16:18 by fallan            #+#    #+#             */
/*   Updated: 2024/05/04 12:09:11 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_array_elements(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (i);
}

int	ft_count_array_elements_debug(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%d: %s |", i, array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	return (i);
}

/* converts a hexadecimal string to an integer
with the corresponding decimal value */
int	ft_hex_string_to_int(char *hex_string)
{
	int	i;
	int	decimal_value;
	int	hex_factor;

	i = 0;
	decimal_value = 0;
	hex_factor = 1;
	while (hex_string[i + 1])
		i++;
	while (hex_string[i] != 'x' && hex_string[i] != 'X')
	{
		if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
			decimal_value += (hex_string[i] - 55) * hex_factor;
		else if (hex_string[i] >= 'a' && hex_string[i] <= 'f')
			decimal_value += (hex_string[i] - 87) * hex_factor;
		else
			decimal_value += (hex_string[i] - 48) * hex_factor;
		hex_factor *= 16;
		i--;
	}
	return (decimal_value);
}

char	*ft_whitespace_to_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\t' | str[i] == '\n' | str[i] == \
	'\v' | str[i] == '\f' | str[i] == '\r')
		str[i] = ' ';
		i++;
	}
	return (str);
}

void	ft_free_list(t_list *point_list)
{
	t_list	*temp;

	temp = NULL;
	while (point_list)
	{
		temp = point_list;
		point_list = point_list->next;
		free(temp);
	}
}


// for debugging purposes
void	ft_print_point_list(t_env *env)
{
	int i = 0;
	t_list	*anchor = env->point_list;
	int	*temp;

	temp = (int *)malloc (6 * sizeof(int));
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp = (int *) env->point_list->content;
			printf("pt %d: (%d,%d), altitude %d, color %d   ", i++, \
			temp[0], temp[1], temp[2], temp[5]);
			if (i % 3 == 0)
				printf("\n");
			env->point_list = env->point_list->next;
		}
	}
	env->point_list = anchor;
}
