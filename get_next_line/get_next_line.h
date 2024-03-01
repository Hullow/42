/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:40 by fallan            #+#    #+#             */
/*   Updated: 2024/03/01 17:17:44 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

struct	Result {
	int		read_ret;
	char	*line;
	char	*buf;
};

char			*ft_add_string(char *addition, unsigned int end_of_line, char *base);
unsigned int	ft_locate_end_of_line(char *buf);
void			*ft_fill_char(void *s, unsigned int n, char c);
char			*get_next_line(int fd);
char			*ft_next_lines(char *buf);
size_t			ft_strlen(char *str);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
