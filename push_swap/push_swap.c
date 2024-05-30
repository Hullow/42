/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/30 16:48:29 by fallan           ###   ########.fr       */
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
			//printf("[%d]:%s ", i, argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		//ft_printf("input okay\n");
		full_stack = ft_string_to_stack(argv, i);

		ft_calculate_sizes(full_stack);
		// printf("size: a %d, b %d\n", full_stack->size_a, full_stack->size_b);

		ft_do_multiple_actions(PB, full_stack, 2);
		ft_calculate_sizes(full_stack);
		// printf("size: a %d, b %d\n", full_stack->size_a, full_stack->size_b);

		t_cost	*cost = malloc (sizeof(t_cost));
 		t_cost	*min_cost_insert = malloc (sizeof(t_cost));
		min_cost_insert->total = INT_MAX;

		t_stack_list	*stack_iterator;
		stack_iterator = full_stack->a_head;
		// ft_print_both_stacks(full_stack);
		// int	loop = 0;
		// ft_print_both_stacks(full_stack);
		while(stack_iterator)
		{
			// ft_printf("\n***loop %d***\n", ++loop);
			// compute cheapest element
			while (stack_iterator)
			{
				ft_calculate_cost(stack_iterator, full_stack, cost);
				// printf("\nmain function: in the loop: cost total: %d\n", cost->total);
				if (cost->total < min_cost_insert->total)
				{
					min_cost_insert->xRA = cost->xRA;
					min_cost_insert->xRB = cost->xRB;
					min_cost_insert->xRR = cost->xRR;
					min_cost_insert->xRRA = cost->xRRA;
					min_cost_insert->xRRB = cost->xRRB;
					min_cost_insert->xRRR = cost->xRRR;
					min_cost_insert->total = cost->total;
				// 	printf("minimum cost reset:\n\tcost: xRA: %d, xRB: %d, xRR: %d, xRRA: %d, xRRB: %d, xRRR: %d\n", cost->xRA, cost->xRB, cost->xRR, cost->xRRA, cost->xRRB, cost->xRRR);
				// 	printf("\t********insertion selected: xRA: %d, xRB: %d, xRR: %d, xRRA: %d, xRRB: %d, xRRR: %d\n", min_cost_insert->xRA, min_cost_insert->xRB, min_cost_insert->xRR, min_cost_insert->xRRA, min_cost_insert->xRRB, min_cost_insert->xRRR);
				}
				if (stack_iterator)
					stack_iterator = stack_iterator->next;
			}
			// printf("insertion selected: xRA: %d, xRB: %d, xRR: %d, xRRA: %d, xRRB: %d, xRRR: %d\n", min_cost_insert->xRA, min_cost_insert->xRB, min_cost_insert->xRR, min_cost_insert->xRRA, min_cost_insert->xRRB, min_cost_insert->xRRR);
			ft_do_multiple_actions(RA, full_stack, min_cost_insert->xRA);
			ft_do_multiple_actions(RB, full_stack, min_cost_insert->xRB);
			ft_do_multiple_actions(RR, full_stack, min_cost_insert->xRR);
			ft_do_multiple_actions(RRA, full_stack, min_cost_insert->xRRA);
			ft_do_multiple_actions(RRB, full_stack, min_cost_insert->xRRB);
			ft_do_multiple_actions(RRR, full_stack, min_cost_insert->xRRR);
			ft_do_multiple_actions(PB, full_stack, 1);
			stack_iterator = full_stack->a_head;
			min_cost_insert->total = INT_MAX;
			// ft_print_both_stacks(full_stack);
		}

		// rearrange b_stack to put maximum value at the top
		// and push everything to a_stack
		t_stack_list *max = ft_stack_max_value(full_stack->b_head);
		while (full_stack->b_head != max)
			ft_do_multiple_actions(RB, full_stack, 1);
		// ft_print_both_stacks(full_stack);
		while (full_stack->b_head)
			ft_do_multiple_actions(PA, full_stack, 1);
		// ft_print_both_stacks(full_stack);

		// int max = 0;
		// int max_position = 0;
		// t_stack_list *tmp;
		// tmp = full_stack->b_head;
		// while (tmp)
		// {
		// 	if (tmp->value > max)
		// 		max = tmp->value;
		// 	tmp = tmp->next;
		// }
		// max_position = tmp->position;
		// ft_printf("segfault finder\n");
		// while (full_stack->b_head->value != max)
		// 	ft_do_multiple_actions(RB, full_stack, 1); // ajouter RRB
		// printf("size b: %i\n", full_stack->size_b);
		// ft_do_multiple_actions(PA,full_stack, full_stack->size_b);
		// ft_print_both_stacks(full_stack);
		ft_free(&max);
		ft_free(&cost);
		ft_free_full_stack(&full_stack);
	}
	return (0);
}
