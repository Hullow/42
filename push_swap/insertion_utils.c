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

// int	ft_smallest_difference(t_stack_list *b_stack, int *min_max)
// {

// }

// finds where an element from stack a must be placed in stack b
// returns the position it must be in (i-th element of b)
// inputs: the value of the element in a, the stack b, the min_max for b
int	ft_optimal_position(int a_value, t_stack_list *b_stack)
{
	t_stack_list	*anchor;
	int				optimal_position;
	int				difference;
	int				smallest_difference;

	if (!b_stack)
		return (0);
	optimal_position = 0;
	anchor = b_stack;
	smallest_difference = INT_MAX;
	while (b_stack)
	{
		difference = a_value - b_stack->value; // if a is bigger than the value pointed to in b, a can take its place in the stack
		if (ft_abs(difference) < smallest_difference)
			smallest_difference = ft_abs(difference); 			printf("smallest_difference set to %d\n", smallest_difference);
		b_stack = b_stack->next;
	}
	b_stack = anchor;
	while (b_stack && smallest_difference != ft_abs(a_value - b_stack->value)) // set i to point to the element of b with the smallest difference
	{
		printf("smallest_difference: %d; a_value - b_stack->value: %d\n", smallest_difference, a_value - b_stack->value);
		optimal_position++;
		printf("\nstep %d:\nb_stack->value: %d, b_stack->next->value: %d\n", optimal_position, b_stack->value, b_stack->next->value);
		b_stack = b_stack->next;
	}
	if (smallest_difference == a_value - b_stack->value)	printf("\n\t**************\n\t*** equal! ***\n\t**************\n\n");
	if (a_value	< b_stack->value)
		optimal_position++;
	printf("optimal position for a_element \"%d\" is %d), next to \"%d\"\n", a_value, optimal_position, b_stack->value);
	return (optimal_position);
}

int	ft_abs(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}