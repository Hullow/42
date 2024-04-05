/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/04/05 17:14:58 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_elements_in_2d_char_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}


// counts the number of lines from our file descriptor (array of characters)
// and calls ft_count_columns to count the number of columns
// line_data : [0]->line count, [1]->line length
static int	*ft_examine_lines(int fd)
{
	int		*line_data;
	char	*line_read;

	line_data = malloc(2 * sizeof(int));
	if (!line_data)
		return (NULL);
	line_data[0] = 0;
	line_read = get_next_line(fd);
	line_data[1] = ft_count_elements_in_2d_char_array(ft_split(line_read, ' '));
	if (line_read)
		free(line_read);
	while (line_read)
	{
		if (ft_count_elements_in_2d_char_array(ft_split(line_read, ' ')) != line_data[1])
			{
				free(line_data);
				return (NULL);
			}
		line_data[0]++;
		line_read = get_next_line(fd);
		if (line_read)
			free(line_read);
	}
	if (line_data[0] && line_data[1])
		ft_printf("lines_count: %d\nline length: %d\n", line_data[0], line_data[1]);
	return (line_data);
}

void	ft_print_map(int **map, int* line_data)
{
	int	i = -1;
	int	j = -1;

	while (++i < line_data[0])
	{
		if (map[i])
		{
			j = -1;
			while (++j < line_data[1])
				ft_printf("%d ", map[i][j]);
		}
		else
			ft_printf("get_next_line returned NULL\n");
		ft_printf("\n");
	}
}

typedef struct s_point{
	int				x;
	int				y;
	int				z;
	int				line_count;
	int				column_count;
	struct s_point	*next;
} 	t_point;

t_point	*ft_fill_list_element(t_point *list_element, char **split_string, int i, int j, int *line_data)
{
	list_element->x = j;
	list_element->y = i;
	list_element->z = ft_atoi(split_string[j]);
	list_element->line_count = line_data[0];
	list_element->column_count = line_data[1];
	return (list_element);
}


// parses the input file to produce an array of integers
static t_point	*ft_file_to_coordinate_list(int fd, int *line_data)
{
	t_point	*head = NULL;
	t_point	*new_element = NULL;
	char	**split_string = NULL;
	int 	i;
	int 	j;

	i = -1;
	while (++i < line_data[0])
	{
		split_string = ft_split(get_next_line(fd), ' '); // read the line, split it 
		j = -1;
		while (++j < line_data[1])
		{
			new_element = ft_lstnew(NULL);
			ft_fill_list_element(new_element, split_string, i, j, line_data);
			if (head == NULL)
				head = new_element;
			else
				ft_lstadd_back(&head, new_element);
		}
	}
	return (head);
}

// void	ft_print_coordinate_map(s_list coordinate_map, int* line_data)
// {
// 	int	i = -1;
// 	int	j = -1;

// 	while (++i < line_data[0])
// 	{
// 		if (coordinate_map.x)
// 		{
// 			j = -1;
// 			while (++j < line_data[1])
// 				ft_printf("%d ", map[i][j]);
// 		}
// 		else
// 			ft_printf("get_next_line returned NULL\n");
// 		ft_printf("\n");
// 	}
// }

// int	**ft_isometric_projection(int **map)
// {
// 	int **projection = NULL;

// }



int main(int argc, char *argv[])
{
	int	fd;
	int	*line_data;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s seems to exist\n", argv[1]);
			line_data = ft_examine_lines(fd);
			close(fd);
			fd = open(argv[1], O_RDONLY);
			// int	**map = ft_file_to_array(fd, line_data);
			// ft_print_map(map, line_data);
			// ft_coordinate_map(map, line_data);
		}
	}
	else
		ft_printf("missing arguments\n");
 	return (0);
}