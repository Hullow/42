/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 23:12:00 by fallan           ###   ########.fr       */
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

static int	ft_count_elements_in_2d_int_array(int **array, int dimension)
{
	int i;

	i = 0;
	if (dimension == 0)
	{
		while (array[i])
			i++;
	}
	else if (dimension == 1)
	{
		while (array[0][i])
		{
			ft_printf("%d ", array[0][i]);
			i++;
		}
		ft_printf("\n");
	}
	else
		return (-1);
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
	{
		ft_printf("lines_count: %d\n", line_data[0]);
		ft_printf("line length: %d\n", line_data[1]);
	}
	else
		ft_printf("no lines found\n");
	return (line_data);
}

// int	**ft_add_line_data_to_map(int **map, int *line_data)
// {
// 	map[0] = malloc((line_data[1] + 1) * sizeof(int)); // array of ints *times* number of columns
// 	if (!map[0])
// 		return (NULL);
// 	map[0][0] = line_data[0];
// 	map[0][1] = line_data[1];

// 	while (line_data[1] > 1)
// 	{
// 		map[0][line_data[1]] = 0;
// 		line_data[1]--;
// 	}
// 	return (map);
// }

// parses the input file to produce an array of integers
static int **ft_file_to_array(int fd, char *path)
{
	int		**map = NULL;
	char	**split_string = NULL;
	int 	i;
	int 	j;
	int 	*line_data;

	i = -1;
	line_data = ft_examine_lines(fd);
	close(fd);
	if (!line_data) // really necessary ?
		return (NULL);
	fd = open(path, O_RDONLY);
	map = malloc ((line_data[0] + 2) * sizeof(int *)); // array of array of ints *times* number of line
	while (++i < line_data[0])
	{
		map[i] = malloc((line_data[1] + 1) * sizeof(int)); // array of ints *times* number of columns
		if (!map[i])
			return (NULL);
		split_string = ft_split(get_next_line(fd), ' '); // read the line, split it 
		j = -1;
		while (++j < line_data[1])
			map[i][j] = ft_atoi(split_string[j]);
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
	close(fd);
	return (map);
}


// adds x and y coordinates to the input map
int	ft_coordinate_map(int **map)
{
	// int	***coordinate_map = NULL;
	int 	line;
	int 	column;
	// int 	altitude;


	line = ft_count_elements_in_2d_int_array(map, 0);
	ft_printf("ft_coordinate_map: %d lines in map\n", line);

	column = ft_count_elements_in_2d_int_array(map, 1);
	ft_printf("ft_coordinate_map: %d columns in map\n", column);

	ft_printf("sizeof(map): %d\n", sizeof(map));

	return (0);
}

// int	**ft_isometric_projection(int **map)
// {
// 	int **projection = NULL;

// }



int main(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s seems to exist\n", argv[1]);
			int	**map = ft_file_to_array(fd, argv[1]);
			ft_coordinate_map(map);
		}
	}
	else
		ft_printf("missing arguments\n");
 	return (0);
}