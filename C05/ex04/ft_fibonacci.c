/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:10:18 by fallan            #+#    #+#             */
/*   Updated: 2023/08/02 20:01:08 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index)
{
	int	result;

	result = 0;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	
	else if (index == 1 || index == 2)
		return (1);

	else if (index > 2)
	{
		result += ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}
	return (result);
}

/* int	main(int argc, char **argv)
{
	if (argc > 0)
		printf("%d\n", ft_fibonacci(atoi(argv[1])));
	else
		return (0);
} */