/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/04/29 10:25:55 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_elements_in_2d_char_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/* counts the number of lines (line_data[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (line_data[1]) */
int	*ft_examine_lines(int fd)
{
	int		*line_data;
	char	*line_read;

	line_data = (int *)malloc(2 * sizeof(int));
	if (!line_data)
		return (NULL);
	line_data[0] = 0;
	line_read = get_next_line(fd);
	line_data[1] = ft_count_elements_in_2d_char_array(ft_split(line_read, ' '));
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
		// if (line_read)
		// 	free(line_read);
	}
	if (line_data[0] && line_data[1])
		ft_printf("line count: %d\nline length: %d\n", line_data[0], line_data[1]);
	return (line_data);
}

int	*ft_fill_point(char **split_string, int i, int j, int *line_data)
{
	int	*point;

	point = (int *)malloc (5 * sizeof(int));
	point[0] = j;
	point[1] = i;
	point[2] = ft_atoi(split_string[j]);
	point[3] = line_data[0];
	point[4] = line_data[1];
	point[5] = 1;
	return (point);
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
