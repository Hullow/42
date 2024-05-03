/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/05/03 14:10:32 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* counts the number of lines (line_data[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (line_data[1]) */

// Function too long !
int	*ft_examine_lines(int fd)
{
	int		*line_data;
	char	*line_read;
	int		i;

	i = 1;
	line_data = (int *)malloc(2 * sizeof(int));
	if (!line_data)
		return (NULL);
	line_data[0] = 0;
	line_read = get_next_line(fd);
	if (line_read)
		line_data[0]++;
	line_data[1] = ft_count_elements_in_2d_char_array(ft_split(line_read, ' '));
	// if (line_read)
	// 	free(line_read);
	while (line_read)
	{
		line_read = get_next_line(fd);
		if (line_read)
			line_data[0]++;
		i++;
		// if (line_read)
		// 	free(line_read);
	}
	if (!line_data[0] && !line_data[1])
		free(line_data);
	else
		printf("line count: %d, line length: %d\n", line_data[0], line_data[1]);
	return (line_data);
}

int	ft_count_elements_in_2d_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

// parses the input file to produce an array of integers
// the while() goes through all lines (line_data[0])
// and splits the elements with ft_split
// the nested while() then goes through each of these elements,
// i.e. through #columns (== line_data[1]),
// and creates an linked list of points which are filled by
// ft_fill_point
t_list	*ft_file_to_point_list(int fd, int i, int *line_data)
{
	t_list	*node;
	t_list	*head;
	char	**split_string;
	int		j;

	node = NULL;
	head = NULL;
	split_string = NULL;
	i = -1;
	while (++i < line_data[0])
	{
		split_string = ft_split(get_next_line(fd), ' ');
		j = -1;
		while (++j < line_data[1])
		{
			node = ft_lstnew(ft_fill_point(split_string, i, j, line_data));
			if (head == NULL)
				head = node;
			else
				ft_lstadd_back(&head, node);
		}
	}
	free(line_data);
	return (head);
}

/* creates a coordinate point with data:
point[0]: column, i.e. x
point[1]: line, i.e. y
point[2]: altitude, i.e. z
point[3]: #lines
point[4]: #columns
point[5]: color (if ',' is found in our split_string,
otherwise color is set to white/16777215) */
int	*ft_fill_point(char **split_string, int i, int j, int *line_data)
{
	int		*point;
	char	**color_input;

	color_input = NULL;
	point = (int *)malloc (6 * sizeof(int));
	point[0] = j;
	point[1] = i;
	point[2] = ft_atoi(split_string[j]);
	if (ft_strchr(split_string[j], 44))
	{
		color_input = ft_split(split_string[j], ',');
		point[2] = ft_atoi(color_input[0]);
		point[5] = ft_hex_string_to_int(color_input[1]);
	}
	else
	{
		point[2] = ft_atoi(split_string[j]);
		point[5] = 0x0000FF;
	}	
	point[3] = line_data[0];
	point[4] = line_data[1];
	return (point);
}

/* converts a hexadecimal string to an integer
with the corresponding decimal value */
int	ft_hex_string_to_int(char *hex_string)
{
	int	i;
	int	decimal_value;
	int	hex_factor;

	decimal_value = 0;
	i = 2;
	while (hex_string[i] == '0')
			i++;
	hex_factor = pow(16, ft_strlen(hex_string + i) - 1);
	while (hex_string[i])
	{
		if (hex_string[i] >= 65)
			decimal_value += (hex_string[i] - 55) * hex_factor;
		else
			decimal_value += (hex_string[i] - 48) * hex_factor;
		hex_factor /= 16;
		i++;
	}
	return (decimal_value);
}
