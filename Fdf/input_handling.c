/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/05/04 18:59:51 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_list	*ft_file_to_list(int fd, char *arg)
{
	int		*line_data;

	line_data = malloc(sizeof(int) * 2);
	if (!line_data)
	{
		ft_printf("ft_file_to_list: malloc fail\n");
		return (NULL);
	}
	line_data = ft_examine_lines(fd, line_data);
	close(fd);
	fd = open(arg, O_RDONLY);
	return (ft_fill_list(fd, line_data, -1, -1));
}

/* counts the number of lines (line_data[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (line_data[1]) */

// Function too long !
int	*ft_examine_lines(int fd, int *line_data)
{
	char	*line_read;
	int		columns;

	line_read = get_next_line(fd);
	if (line_read)
		line_data[0] = 1;
	line_read = ft_whitespace_to_space(line_read);
	line_data[1] = ft_count_array_elements(ft_split(line_read, ' '));
	while (line_read)
	{
		free(line_read);
		line_read = get_next_line(fd);
		if (line_read)
			line_data[0]++;
		else
			break ;
		line_read = ft_whitespace_to_space(line_read);
		columns = ft_count_array_elements(ft_split(line_read, ' '));
		if (columns != line_data[1])
		{
			free(line_data);
			free(line_read);
			ft_printf("irregular map, aborting\n");
			exit(1);
		}
	}
	ft_free(line_read);
	if (!line_data[0] && !line_data[1])
		free(line_data);
	else
		printf("line count: %d, line length: %d\n", line_data[0], line_data[1]);
	return (line_data);
}


// parses the input file to produce an array of integers
// the while() goes through all lines (line_data[0])
// and splits the elements with ft_split
// the nested while() then goes through each of these elements,
// i.e. through #columns (== line_data[1]),
// and creates an linked list of points which are filled by
// ft_fill_point
t_list	*ft_fill_list(int fd, int *line_data, int i, int j)
{
	t_list	*node;
	t_list	*head;
	t_list	*last;
	char	**split_string;
	char	*line_read;

	node = NULL;
	head = NULL;
	last = NULL;
	split_string = NULL;
	// int k = 0;
	while (++i < line_data[0])
	{
		line_read = ft_whitespace_to_space(get_next_line(fd));
		// k++;
		// if (k % 25 == 0)
		// 	printf("read and whitespaced %d lines\n", k);
		split_string = ft_split(line_read, ' ');
		while (++j < line_data[1])
		{
			node = ft_lstnew(ft_fill_point(split_string, i, j, line_data));
			last = node;
			if (head == NULL)
				head = node;
			node = node->next;
		}
		j = -1;
	}
	free(line_data);
	printf("ft_fill_list: filled\n");
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
		point[5] = 0xFFFFFF;
	}	
	point[3] = line_data[0];
	point[4] = line_data[1];
	return (point);
}
