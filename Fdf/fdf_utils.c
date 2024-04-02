/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/04/02 11:57:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*ft_count_lines(int fd)
{
	char	*ret_value;
	int 	*line_data;

	line_data = malloc(2 * sizeof(int));
	if (!line_data)
		return (NULL);
	line_data[0] = 0;
	ret_value = get_next_line(fd);
	line_data[1] = (int)ft_strlen(ret_value);
	while (ret_value)
	{
		if ((int)ft_strlen(ret_value) != line_data[1])
			{
				free(line_data);
				return (NULL);
			}
		line_data[0]++;
		ret_value = get_next_line(fd);
	}
	if (line_data[0])
	{
		printf("lines_count: %d\n", line_data[0]);
		printf("line length: %d\n", line_data[1]);
	}
	else
		ft_printf("no lines found\n");
	return (line_data);
}

char **ft_map_to_array(int fd, char *path)
{
	char	**map = NULL;
	int 	i;
	int 	*line_data;

	i = 0;
	line_data = ft_count_lines(fd);
	close(fd);
	if (!line_data)
		return (NULL);
	fd = open(path, O_RDONLY);

	map = malloc ((line_data[0] + 1) * sizeof(char *));
	while (++i < line_data[0])
	{
		map[i - 1] = malloc((line_data[1] + 1) * sizeof(char));
		map[i - 1] = get_next_line(fd);
		if (map[i])
			ft_printf("\"%s\"\n", map[i]);
		else
			ft_printf("get_next_line returned NULL\n");
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
			ft_map_to_array(fd, argv[1]);
		}
	}
	else
		ft_printf("missing arguments\n");
 	return (0);
}