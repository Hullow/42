/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/06/05 11:58:03 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	*full_stack;

	if (argc == 1)
		return (-1);
	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
		{
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		if (i == 2)
		{
			ft_printf("Single argument\n");
			return (0);
		}
		full_stack = ft_string_to_stack(argv, i);
		ft_find_duplicates(full_stack);
		ft_calculate_sizes(full_stack);
		ft_set_positions(full_stack);
		if (full_stack->size_a < 5)
		{
			ft_sort_small_stack(full_stack);
			if (ft_check_stack(full_stack) != 0)
				ft_printf("KO\n");
			// ft_print_stack(full_stack->a_head);
			return (0);
		}

		ft_do_multiple_actions(PB, full_stack, 2);
		ft_calculate_sizes(full_stack);

		t_cost	*cost = malloc (sizeof(t_cost));
 		t_cost	*min_cost_insert = malloc (sizeof(t_cost));
		min_cost_insert->total = INT_MAX;

		t_stack_list	*stack_iterator;
		stack_iterator = full_stack->a_head;
		while (stack_iterator)
		{
			// compute cheapest element
			while (stack_iterator)
			{
				ft_calculate_cost(stack_iterator, full_stack, cost);
				if (cost->total < min_cost_insert->total)
				{
					min_cost_insert->xRA = cost->xRA;
					min_cost_insert->xRB = cost->xRB;
					min_cost_insert->xRR = cost->xRR;
					min_cost_insert->xRRA = cost->xRRA;
					min_cost_insert->xRRB = cost->xRRB;
					min_cost_insert->xRRR = cost->xRRR;
					min_cost_insert->total = cost->total;
				}
				if (stack_iterator)
					stack_iterator = stack_iterator->next;
			}
			ft_do_multiple_actions(RA, full_stack, min_cost_insert->xRA);
			ft_do_multiple_actions(RB, full_stack, min_cost_insert->xRB);
			ft_do_multiple_actions(RR, full_stack, min_cost_insert->xRR);
			ft_do_multiple_actions(RRA, full_stack, min_cost_insert->xRRA);
			ft_do_multiple_actions(RRB, full_stack, min_cost_insert->xRRB);
			ft_do_multiple_actions(RRR, full_stack, min_cost_insert->xRRR);
			ft_do_multiple_actions(PB, full_stack, 1);
			stack_iterator = full_stack->a_head;
			min_cost_insert->total = INT_MAX;
		}
		// rearrange b_stack to put maximum value at the top
		// and push everything to a_stack
		t_stack_list *max = ft_stack_max_value(full_stack->b_head);
		while (full_stack->b_head != max)
			ft_do_multiple_actions(RB, full_stack, 1);
		while (full_stack->b_head)
			ft_do_multiple_actions(PA, full_stack, 1);
		ft_free_full_stack(&full_stack);
	}
	return (0);
}
