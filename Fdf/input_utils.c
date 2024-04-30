/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/04/30 16:57:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* counts the number of lines (line_data[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (line_data[1]) */
int	*ft_examine_lines(int fd)
{
	int		*line_data;
	char	*line_read;
	int i = 1;

	line_data = (int *)malloc(2 * sizeof(int));
	if (!line_data)
		return (NULL);
	line_data[0] = 0;
	line_read = get_next_line(fd);
	line_data[1] = ft_count_elements_in_2d_char_array(ft_split(line_read, ' '));
	printf("line length: %d\n", line_data[1]);
	// if (line_read)
	// 	free(line_read);
	while (line_read)
	{
		if (ft_count_elements_in_2d_char_array(ft_split(line_read, ' ')) != line_data[1]) // what ?
			{
				free(line_data);
				return (NULL);
			}
		line_data[0]++;
		line_read = get_next_line(fd);
		ft_printf("line: %d - ", i);
		ft_printf("line read: %s\n", line_read);
		i++;
		// if (line_read)
		// 	free(line_read);
	}
	if (line_data[0] && line_data[1])
		printf("line count: %d, line length: %d\n", line_data[0], line_data[1]);
	return (line_data);
}

int	ft_count_elements_in_2d_char_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

// parses the input file to produce an array of integers
t_list	*ft_file_to_point_list(int fd, int i, int *line_data)
{
	t_list	*node = NULL;
	t_list	*head = NULL;
	char	**split_string = NULL;
	int 	j;

	i = -1;
	while (++i < line_data[0])
	{
		split_string = ft_split(get_next_line(fd), ' '); // read the line, split it 
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
	return (head);
}

/*
point[0]: column, i.e. x
point[1]: line, i.e. y
point[2]: altitude, i.e. z
point[3]: #lines
point[4]: #columns
*/

#include <stdlib.h>
int	*ft_fill_point(char **split_string, int i, int j, int *line_data)
{
	int		*point;
	// char	**color_input = NULL;

	point = (int *)malloc (5 * sizeof(int));
	point[0] = j;
	point[1] = i;
	point[2] = ft_atoi(split_string[j]);
	// if (ft_strchr(split_string[j], 44)) // if ',' found in our split string
	// {
	// 	color_input = ft_split(split_string[j], ',');
	// 	point[2] = ft_atoi(color_input[0]);
	// 	point[5] = atoi(color_input[1]);
	// 	printf("color detected: atoi: %d, string: %s\n", point[5], color_input[1]);
	// }
	// else
	// {
	// 	point[2] = ft_atoi(split_string[j]);
	// 	point[5] = 0x00FFFFFF;
	// }	
	point[3] = line_data[0];
	point[4] = line_data[1];
	return (point);
}

void	ft_print_point_list(t_env *env)
{
	int i = 0;
	t_list	*anchor = env->point_list;
	int	*temp;

	temp = (int *)malloc (5 * sizeof(int));
	
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp = (int *) env->point_list->content;
			printf("pt %d: (%d,%d), l:%d, c:%d – ", i, temp[0], temp[1], temp[3], temp[4]);

			if (i++ % 6 == 0)
				ft_printf("\n");
			env->point_list = env->point_list->next;
		}
	}
	env->point_list = anchor;
}

/* 
int	ft_hex_string_to_int(char *hex_string)
{
	int	i;
	int	integer;
	int	hex_factor;

	i = 2;
	integer = 0;
	hex_factor = pow(16, 8 - i + 1);
	while (hex_string[i])
	{
		integer += ft_atoi(hex_string[i]) / hex_factor;
		i++;
	}
	printf("ft_hex_string_to_int: %d\n", integer);
	return (integer);
}

 */