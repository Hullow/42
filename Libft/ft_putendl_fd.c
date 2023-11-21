/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:58:12 by francis           #+#    #+#             */
/*   Updated: 2023/11/21 09:58:12 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, ft_strjoin(s, "\n"), ft_strlen(s) + 1);
}

/* int	main()
{
	ft_putendl_fd("Hey Johnny", 0);
	ft_putendl_fd("Hey Johnny", 1);
	ft_putendl_fd("Hey Johnny", 2);
	ft_putendl_fd("Hey Johnny\n", 2);

	ft_putendl_fd("Hey Johnny", 3);
	return (0);
} */