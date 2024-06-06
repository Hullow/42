/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:28:08 by fallan            #+#    #+#             */
/*   Updated: 2024/05/15 16:28:46 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds where an element from a stack a must be placed in stack b
// returns the position it must be in (i-th element of b)
// inputs: the value of the element in a, the stack b, the min_max for b
int	ft_optimal_position(int value, t_stack_list *stack)
{
	t_stack_list	*anchor;
	int				optimal_position;
	int				difference;
	int				smallest_difference;

	if (!stack)
		return (0);
	optimal_position = 0;
	anchor = stack;
	smallest_difference = INT_MAX;
	while (stack)
	{
		difference = value - stack->value; // if a is bigger than the value pointed to in b, a can take its place in the stack
		if (ft_abs(difference) < smallest_difference)
			smallest_difference = ft_abs(difference); // 			printf("smallest_difference set to %d\n", smallest_difference);
		stack = stack->next;
	}
	stack = anchor;
	while (stack && smallest_difference != ft_abs(value - stack->value)) // set i to point to the element of b with the smallest difference
	{
		optimal_position++;
		stack = stack->next;
	}
	if (value < stack->value)
		optimal_position++;
	//printf("optimal position for a_element \"%d\" is %d), next to \"%d\"\n", value, optimal_position, stack->value);
	return (optimal_position);
}

// returns the absolute value of an int
int	ft_abs(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}

// returns the minimum between two integer values
int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

// returns the maximum between two integer values
int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
