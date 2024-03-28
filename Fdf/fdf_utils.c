/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/03/28 18:31:27 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_lines(int fd)
{
	char	*ret_value;
	int 	lines_count;

	lines_count = 0;
	ret_value = get_next_line(fd);
	while (ret_value)
	{
		lines_count++;
		ret_value = get_next_line(fd);
	}
	if (lines_count)
		printf("lines_count: %d\n", lines_count);
	else
		ft_printf("no lines found\n");
	return (lines_count);
}

char **ft_map_to_array(int fd, char *path)
{
	char	**map = NULL;
	char	*ret_value = NULL;
	int 	i;
	int 	lines_count;

	i = 0;
	lines_count = ft_count_lines(fd);
	close(fd);
	if (!lines_count)
		return (NULL);
	fd = open(path, O_RDONLY);

	map = malloc ((lines_count + 1) * sizeof(char *));

	ret_value = get_next_line(fd);
	map[0] = malloc((ft_strlen(ret_value) + 1) * sizeof(char));
	ft_strlcpy(map[0], ret_value, ft_strlen(ret_value) + 1);
	while (++i < lines_count)
	{
		map[i] = malloc((ft_strlen(ret_value) + 1) * sizeof(char));
		map[i] = get_next_line(fd);
		if (map[i])
			ft_printf("\"%s\"\n", map[i]);
		else
			ft_printf("get_next_line returned NULL\n");
	}
 
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