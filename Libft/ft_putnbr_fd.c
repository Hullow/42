/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:58:09 by francis           #+#    #+#             */
/*   Updated: 2023/11/21 10:01:45 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void	ft_putnbr_fd(int n, int fd);

int	main()
{
	ft_putnbr_fd(56, 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putnbr_fd(2147483646, 1);
	ft_putnbr_fd(2147483648, 1);
	ft_putnbr_fd(56458485859, 1);
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(-56, 1);
	ft_putnbr_fd(-2147483647, 1);
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}

void	ft_putnbr_fd(int n, fd)
{
	int		i;
	int		d;
	int		temp;
	char	*str[11];

	i = 0;
	d = 0;
	temp = n;
	if (nb == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{	
		if (n < 0)
		{
			n *= (-1);
			write(fd, "-", 1);
		}
		while (temp != 0)
		{
		temp /= 10;
		d++;
		}
		while (i < d)
		{
	str[d - i - 1] = (n % 10) + 48;
	n /= 10;
	i++;
		}
	i = 0;
		while (i <= d)
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
}

