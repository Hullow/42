/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/27 16:24:59 by fallan           ###   ########.fr       */
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
			printf("[%d]:%s ", i, argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		ft_printf("input okay\n");
		full_stack = ft_string_to_stack(argv, i);

		ft_do_multiple_actions(PB, full_stack, 2);

// 5123   46
		t_cost cost;
		while(full_stack->a_head)
		{
			ft_print_both_stacks(full_stack);
			ft_calculate_cost(full_stack->a_head, full_stack, &cost);
			ft_do_multiple_actions(RA, full_stack, cost.xRA);
			ft_do_multiple_actions(RB, full_stack, cost.xRB);
			ft_do_multiple_actions(RR, full_stack, cost.xRR);
			ft_do_multiple_actions(RRA, full_stack, cost.xRRA);
			ft_do_multiple_actions(RRB, full_stack, cost.xRRB);
			ft_do_multiple_actions(RRR, full_stack, cost.xRRR);
			ft_do_multiple_actions(PB, full_stack, 1);
		}
		int max = 0;
		int max_position = 0;
		t_stack_list *tmp;
		tmp = full_stack->b_head;
		while (tmp)
		{
			if (tmp->value > max)
				max = tmp->value;
			max_position = tmp->position;
			tmp = tmp->next;
		}
		while (full_stack->b_head->value != max)
			ft_do_multiple_actions(RB, full_stack, 1); // ajouter RRB
		printf("size b: %i\n", full_stack->size_b);
		ft_do_multiple_actions(PA,full_stack, full_stack->size_b);
		ft_print_both_stacks(full_stack);


		// ft_free_full_stack(&full_stack);
	}
	return (0);
}
