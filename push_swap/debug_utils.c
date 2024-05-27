/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:35:21 by fallan            #+#    #+#             */
/*   Updated: 2024/05/27 14:26:10 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // to remove or comment out
void	ft_print_both_stacks(t_stacks *full_stack)
{
	ft_printf("\na:\n");
	ft_print_stack(full_stack->a_head);
	ft_printf("\nb:\n");
	ft_print_stack(full_stack->b_head);
}

void	ft_print_stack(t_stack_list *list)
{
	int		i;

	i = -1;
	// ft_printf("ft_print_list: list address %p\n", list);
	if (!list)
		ft_printf("(empty)\n");
	if (list && list->next != NULL)
	{
		while (list)
		{
			if (list != NULL) // if (list->value)
				printf("%d) %d\n", ++i, list->value); // printf
			list = list->next;
		}
	}
}

void	ft_print_moves(t_elem_insert *insertion)
{
	int	actions;
	int	moves_1;
	int	moves_2;

	actions = insertion->actions;
	moves_1 = insertion->moves_1;
	moves_2 = insertion->moves_2;
	if (insertion->actions_aggregated)
	{
		// printf("actions_aggregated found; insertion->actions: %d, insertion->actions_aggregated: %d\n", insertion->actions, insertion->actions_aggregated);
		actions = insertion->actions_aggregated;
		moves_1 = insertion->moves_1_aggregated;
		moves_2 = insertion->moves_2_aggregated;
	}
	if (actions == 9)
		printf(" RR (10) (%d) == %d moves\n", moves_1, moves_1 + moves_2);
	if (actions == 10)
		printf(" RA_RB (10) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 11)
		printf(" RRA_RB (11) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 12)
		printf(" RRA_RRB (12) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 13)
		printf(" RA_RRB (13) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	if (actions == 14)
		printf(" RR_RB (14) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 15)
		printf(" RR_RA (15) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 16)
		printf(" RRR_RRB (16) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 17)
		printf(" RRR_RRA (17) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
	else if (actions == 18)
		printf(" RRR (18) (%d, %d) == %d moves\n", moves_1, moves_2, moves_1 + moves_2);
}
