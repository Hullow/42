/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/10 16:08:28 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_check_input(char *str)
{
	int	i;
	int	input;
	
	i = -1;
	while (str[++i])
		if (! ((str[i] >= '0' && str[i] <= '9') || str[0] == '-'))
			return (NULL);
	if (str[0] == '-' && ft_strlen(str) > 11)
			return (NULL);
	else if (str[0] != '-' && ft_strlen(str) > 10)
			return (NULL);
	input = ft_atoi(str);
	if ((str[0] == '-' && input > 0) || (str[0] != '-' && input < 0))
		return (NULL);
	return (str);
}

int main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
		return (-1);
	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
		{
			ft_printf("%s ", argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		int	*a_stack = (int *) malloc (sizeof(int) * (i - 1));
		i = 0;
		while (argv[i++])
			a_stack[i - 1] = ft_atoi(argv[i - 1]);
		while (--i > 0)
			ft_printf("a_stack[%d]: %d\n", i, a_stack[i]);
	}
	ft_printf("\ninput okay\n");
	return (0);
}

// ft_string_to_int(char *)