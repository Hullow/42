/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:40 by fallan            #+#    #+#             */
/*   Updated: 2024/03/13 15:22:56 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
// to remove
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

struct	Result {
	int		read_ret;
	char	*line;
	char	*buf;
};

char			*get_next_line(int fd);
char			*ft_add_string(char *addition, unsigned int end_of_line, char *base);
unsigned int	ft_end_of_line(char *buf);
void			*ft_fill_char(void *s, char c);
struct Result	ft_fill_line(char *buf, char *line, int read_ret, int fd);
char			*ft_next_lines(char *dst, char *src);
int				ft_read(int fd, char *buf, int read_ret);
size_t			ft_strlen(char *str);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
void			ft_free(char *target, char *temp, int free_now);
int				ft_fd_check(int fd);