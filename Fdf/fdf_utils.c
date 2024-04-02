/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/04/02 17:12:51 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_columns(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

// counts the number of lines
// and calls ft_count_columns to count the number of columns
// line_data : [0]->line count, [1]->line length
static int	*ft_examine_lines(int fd)
{
	int		*line_data;
	char	*line_read;
	int 	i;

	line_data = malloc(2 * sizeof(int));
	if (!line_data)
		return (NULL);
	line_data[0] = 0;
	i = -1;
	line_read = get_next_line(fd);
	line_data[1] = ft_count_columns(ft_split(line_read, ' '));
	if (line_read)
		free(line_read);
	while (line_read)
	{
		if (ft_count_columns(ft_split(line_read, ' ')) != line_data[1])
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


// int *ft_string_to_int_array(char *string, int column_count)
// {
// 	char **split_string = NULL;
// 	int *array = NULL;
// 	int i;

// 	split_string = ft_split(string);
// 	i = -1;
// 	while (++i < column_count)
// 		array[i] = ft_atoi(split_string[i]);
// 	array[i] = NULL;
// 	return (array);
// }

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
	if (!line_data)
		return (NULL);
	fd = open(path, O_RDONLY);
	map = malloc ((line_data[0] + 1) * sizeof(int *)); // array of array of ints * number of line
	while (++i < line_data[0])
	{
		map[i] = malloc((line_data[1] + 1) * sizeof(int)); // array of ints * number of columns
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
				ft_printf("\"%d\" ", map[i][j + 1]);
		}
		else
			ft_printf("get_next_line returned NULL\n");
		ft_printf("\n");
	}
	close(fd);
	return (map);
}



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
			ft_file_to_array(fd, argv[1]);
		}
	}
	else
		ft_printf("missing arguments\n");
 	return (0);
}