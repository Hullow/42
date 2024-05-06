/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:16:18 by fallan            #+#    #+#             */
/*   Updated: 2024/05/06 15:08:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_array_elements(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
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
		if (str[i] == '\t' || str[i] == '\n' || str[i] == \
	'\v' || str[i] == '\f' || str[i] == '\r')
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

void	ft_free_array(char ***split, int *line_data)
{
	int	i;

	i = -1;
	if (split)
	{
		while (++i < line_data[0])
			free(split[i]);
		free(split);
	}
}
