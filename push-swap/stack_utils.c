/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:02:59 by fallan            #+#    #+#             */
/*   Updated: 2024/05/15 20:29:43 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_calculate_min_max(t_stack_list *input_stack)
{
	int	*min_max;

	min_max = malloc (sizeof(int) * 3);
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
	ft_printf("minimum: %d, maximum: %d\n", min_max[1], min_max[0]);
	return (min_max);
}

void		ft_calculate_sizes(t_stacks *full_stack)
{
	full_stack->size_a = 0;
	full_stack->size_b = 0;
	while (full_stack->a_head && ++full_stack->size_a)
		full_stack->a_head = full_stack->a_head->next;
	while (full_stack->b_head && ++full_stack->size_b)
		full_stack->b_head = full_stack->b_head->next;
	ft_printf("size_a: %d, size_b: %d\n", full_stack->size_a, full_stack->size_b);
}

// for a list, sets the position (in order of appearance)
// for each element of the list
void	ft_set_position(t_stack_list *a_stack)
{
	int	position;

	position = 0;
	while (a_stack)
	{
		a_stack->position = position++;
		a_stack = a_stack->next;
	}
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

// int	ft_max(int a, int b)
// {
// 	if (a >= b)
// 		return (a);
// 	else
// 		return (b);
// }