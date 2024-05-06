/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:16:18 by fallan            #+#    #+#             */
/*   Updated: 2024/05/06 17:56:08 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// These functions are used to examine the input,
// including finding its dimensions and checking
// its regularity, as well as converting types
// (hexadecimal string to int for the color)

// while line_data[2]: if set to 0, we've read an empty line => stop
// line_data[1] != columns: irregular map handling
int	*ft_find_dimensions(int fd, int *line_data)
{
	char	*line_read;
	int		columns;

	line_read = NULL;
	line_data = ft_examine_line(fd, line_read, line_data);
	if (!line_data[2])
	{
		ft_printf("no line found\n");
		ft_free(line_data);
		exit(1);
	}
	columns = line_data[1];
	while (line_data[2])
	{
		line_data = ft_examine_line(fd, line_read, line_data);
		if (line_data[1] != columns)
		{
			ft_printf("irregular map, aborting\n");
			ft_free(line_data);
			exit(1);
		}
	}
	return (line_data);
}

/* counts the number of lines (line_data[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (line_data[1]) */
int	*ft_examine_line(int fd, char *line_read, int *line_data)
{
	line_read = get_next_line(fd);
	if (line_read)
	{
		line_data[0]++;
		line_read = ft_whitespace_to_space(line_read);
		line_data[1] = ft_count_columns(line_read);
	}
	else
		line_data[2] = 0;
	ft_free(line_read);
	return (line_data);
}

int	ft_count_columns(char *line)
{
	int	i;
	int	columns;

	columns = 0;
	if (!line)
		return (-1);
	i = 0;
	columns = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
		{
			columns++;
			while (line[i] != ' ' && line[i])
				i++;
		}
	}
	return (columns);
}

int	ft_count_array_elements(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
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
