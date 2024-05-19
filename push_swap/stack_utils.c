/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/05/19 18:32:25 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_position(t_stack_list *a_stack)
{
	int	position;

	position = 0;
	while (a_stack->next)
	{
		a_stack->position = position++;
		a_stack = a_stack->next;
	}
}

// returns the minimum between two integer values
int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

// calculates and returns the minimum and maximum value of a stack
int	*ft_calculate_min_max(t_stack_list *input_stack)
{
	int     *min_max;

	min_max = malloc (sizeof(int) * 2);
	min_max[0] = input_stack->value;
	min_max[1] = input_stack->value;
	while (input_stack)
	{
		if (input_stack->value > min_max[1])
				min_max[1] = input_stack->value;
		else if (input_stack->value < min_max[0])
				min_max[0] = input_stack->value;
		input_stack = input_stack->next;
	}
	printf("minimum: %d, maximum: %d\n\n", min_max[0], min_max[1]); // printf
	return (min_max);
}

// calculates and sets the size of each stack
void	ft_calculate_sizes(t_stacks *full_stack)
{
	t_stack_list	*anchor;

	full_stack->size_a = 0;
	full_stack->size_b = 0;
	anchor = full_stack->a_head;
	while (full_stack->a_head)
	{
		full_stack->size_a++;
		full_stack->a_head = full_stack->a_head->next;
	}
	full_stack->a_head = anchor;
	anchor = full_stack->b_head;
	while (full_stack->b_head && ++full_stack->size_b)
			full_stack->b_head = full_stack->b_head->next;
	full_stack->b_head = anchor;
}
