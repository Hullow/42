/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/13 16:08:28 by fallan           ###   ########.fr       */
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

t_stack	*ft_string_to_stack(char **argv, int i)
{
	t_stack			*a_stack;
	t_stack			*b_stack;
	t_full_stack	*full_stack;

	a_stack = (t_stack *) malloc (sizeof(t_stack));
	b_stack = (t_stack *) malloc (sizeof(t_stack));
	if (i - 1 > 2)
	{
		a_stack->in_between = (int *) malloc (sizeof(int) * (i - 3));
		b_stack->in_between = (int *) malloc (sizeof(int) * (i - 3));
	}
	full_stack = (t_full_stack *) malloc (sizeof(t_full_stack));
	full_stack->a_stack = a_stack;
	full_stack->b_stack = b_stack;
	printf("\n\n");
	a_stack->last = ft_atoi(argv[--i]);
	printf("%d\n", a_stack->last);
	while (--i > 1)
	{
		a_stack->in_between[i - 2] = ft_atoi(argv[i]);
		printf("%d\n", a_stack->in_between[i - 2]);
	}
	a_stack->first = ft_atoi(argv[i]);
	printf("%d\n", a_stack->first);
	printf("_             _\n");
	printf("%d, %d, %d, %d\n", b_stack->first, b_stack->in_between[0], b_stack->in_between[1], b_stack->last);
	printf("%d, %d, %d, %d\n", full_stack->a_stack->first, full_stack->a_stack->in_between[0], full_stack->a_stack->in_between[1], full_stack->a_stack->last);
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
		ft_string_to_stack(argv, i);
	}
	ft_printf("\ninput okay\n");
	return (0);
}
