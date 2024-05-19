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

// finds where an element from stack a must be placed in stack b
// returns the position it must be in (i-th element of b)
// inputs: the value of the element in a, the stack b, the min_max for b
int	ft_optimal_position(int a_value, t_stack_list *b_stack, int *min_max)
{
	t_stack_list *anchor;
	int	i;
	int	smallest_difference;
	int	difference;

	anchor = b_stack;
	i = -1;
	difference = 0;
	smallest_difference = min_max[1] - min_max[0];
	if (!b_stack)
	{
		printf("the optimal position for \"%d\" in stack b is %d)\n", a_value, ++i); // printf
		return (i);
	}
	while (b_stack)
	{
		difference = a_value - b_stack->value; // if a is bigger than the value pointed to in b, a can take its place in the stack
		if (difference > 0 && difference < smallest_difference)
			smallest_difference = difference;
		b_stack = b_stack->next;
	}
	b_stack = anchor;
	while (b_stack && smallest_difference != a_value - b_stack->value && ++i)
	{
		// i++;
		b_stack = b_stack->next;
	}
	printf("the optimal position for \"%d\" in stack b is %d), before \"%d\"\n", a_value, i, b_stack->value); // printf
	return (i);
}
