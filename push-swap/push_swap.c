/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/10 17:10:26 by francis          ###   ########.fr       */
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

int	*ft_string_to_int(char **argv, int i)
{
	int	*a_stack;
	// int	*b_stack;

	a_stack = (int *) malloc (sizeof(int) * (i - 1));
	// b_stack = (int *) malloc (sizeof(int) * (i - 1));
	while (--i >= 1)
	{
		a_stack[i - 1] = ft_atoi(argv[i]);
		printf("\na_stack[%d]: %d\n", i - 1, a_stack[i - 1]);
	}
	return (a_stack);
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
			printf("%d: %s ", i, argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		ft_string_to_int(argv, i);
	}
	ft_printf("\ninput okay\n");
	return (0);
}
