/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/05/05 18:06:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// line_data[2] is the toggle to stop counting when set to 1
t_list	*ft_file_to_list(int fd, char *arg)
{
	char	***split;
	int		*line_data;

	line_data = malloc(sizeof(int) * 3);
	if (!line_data)
	{
		ft_printf("ft_file_to_list: malloc fail\n");
		return (NULL);
	}
	line_data[0] = 0;
	line_data[1] = 0;
	line_data[2] = 1;
	line_data = ft_find_dimensions(fd, line_data);
	close(fd);
	fd = open(arg, O_RDONLY);
	split = ft_read_to_array(fd, line_data);
	return (ft_fill_list(split, line_data, -1, -1));
}

// while line_data[2]: if set to 0, we've read an empty line => stop
// line_data[1] != columns: irregular map handling
int	*ft_find_dimensions(int fd, int *line_data)
{
	char	*line_read;
	int		columns;

	line_read = NULL;
	line_data = ft_examine_line(fd, line_read, line_data);
	columns = line_data[1];
	while (line_data[2])
	{
		line_data = ft_examine_line(fd, line_read, line_data);
		if (line_data[1] != columns)
		{
			ft_free(line_read);
			ft_free(line_data);
			ft_printf("irregular map, aborting\n");
			exit(1);
		}
	}
	ft_free(line_read);
	return (line_data);
}

/* counts the number of lines (line_data[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (line_data[1]) */
int	*ft_examine_line(int fd, char *line_read, int *line_data)
{
	char	**temp_split;

	line_read = get_next_line(fd);
	line_read = ft_whitespace_to_space(line_read);
	if (line_read)
		line_data[0]++;
	else
	{
		line_data[2] = 0;
		return (line_data);
	}
	temp_split = ft_split(line_read, ' ');
	line_data[1] = ft_count_array_elements(temp_split);
	ft_free(line_read);
	ft_free(temp_split);
	return (line_data);
}

char	***ft_read_to_array(int fd, int *line_data)
{
	char	***split;
	char	*line_read;
	int	i;

	split = (char ***)malloc(sizeof(char **) * line_data[0]);
	line_read = NULL;
	i = -1;
	while (++i < line_data[0])
	{
		line_read = ft_whitespace_to_space(get_next_line(fd));
		split[i] = ft_split(line_read, ' ');
	}
	return (split);
}

// parses the input file to produce an array of integers
// the while() goes through all lines (line_data[0])
// and splits the elements with ft_split
// the nested while() then goes through each of these elements,
// i.e. through #columns (== line_data[1]), and creates a
// linked list of points which are filled by ft_fill_pt
t_list	*ft_fill_list(char ***split, int *line_data, int i, int j)
{
	t_list	*node;
	t_list	*head;

	node = NULL;
	head = NULL;
	while (++i < line_data[0])
	{
		while (++j < line_data[1])
		{
			if (node)
			{
				node->next = ft_lstnew(ft_fill_pt(split[i], i, j, line_data));
				node = node->next;
			}
			else
			{
				node = ft_lstnew(ft_fill_pt(split[i], i, j, line_data));
				head = node;
			}
		}
		j = -1;
	}
	ft_free_array(split, line_data);
	free(line_data);
	return (head);
}

/* creates a coordinate point with data:
point[0]: column, i.e. x
point[1]: line, i.e. y
point[2]: altitude, i.e. z
point[3]: #lines
point[4]: #columns
point[5]: color (if ',' is found in our split,
otherwise color is set to white/16777215) */
int	*ft_fill_pt(char **split, int i, int j, int *line_data)
{
	int		*point;
	char	**color_input;

	color_input = NULL;
	point = (int *)malloc (6 * sizeof(int));
	point[0] = j;
	point[1] = i;
	point[2] = ft_atoi(split[j]);
	if (ft_strchr(split[j], 44))
	{
		color_input = ft_split(split[j], ',');
		point[2] = ft_atoi(color_input[0]);
		point[5] = ft_hex_string_to_int(color_input[1]);
	}
	else
	{
		point[2] = ft_atoi(split[j]);
		point[5] = 0xFFFFFF;
	}	
	point[3] = line_data[0];
	point[4] = line_data[1];
	return (point);
}
