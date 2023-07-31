/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_number_int_texte.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbinet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:04:50 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 16:15:48 by nbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// ======================================================================

char	*ft_strdup(const char *str);
void	ft_putchar(char *str);

// ======================================================================

char	*read_line_from_file(int fd)
{
	char	buffer[100];
	char	c;
	int		buffer_index;

	buffer_index = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			buffer[buffer_index] = '\0';
			return (ft_strdup(buffer));
		}
		else
			buffer[buffer_index++] = c;
	}
	return (NULL);
}

int	parse_number(const char *line)
{
	int	current_number;
	int	i;

	current_number = 0;
	i = 0;
	while (line[i] != '\0' && line[i] != ':')
	{
		if (line[i] >= '0' && line[i] <= '9')
			current_number = current_number * 10 + (line[i] - '0');
		i++;
	}
	return (current_number);
}

char	*parse_string(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ':')
		{
			i++;
			if (line[i] == ' ')
			{
				i++;
				break ;
			}
		}
		i++;
	}
	return (ft_strdup(line + i));
}

char	*find_line_with_number(int fd, int number)
{
	char	*line;
	int		current_number;
	char	*number_str;

	while (1)
	{
		line = read_line_from_file(fd);
		if (line == NULL)
			break ;
		current_number = parse_number(line);
		if (current_number == number)
		{
			number_str = parse_string(line);
			free(line);
			return (number_str);
		}
		free(line);
	}
	return (NULL);
}

char	*number_in_file(int number)
{
	int		fd;
	char	*result;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putchar("Impossible d'ouvrir le fichier numbers.dict.\n");
		return (NULL);
	}
	result = find_line_with_number(fd, number);
	close(fd);
	return (result);
}
