/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:21:16 by fallan            #+#    #+#             */
/*   Updated: 2024/05/31 18:43:21 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// first count of moves required for each rotation combination,
// without optimization (aggregation, done by ft_aggregate_moves)
	// RA_to_top = a_element->position; 			// if in position 0, 0 moves. if position 1, 1 move. etc.
	// RRA_to_top = full_stack->size_a - a_element->position;
	// RB_to_optimal = optimal_position; 			// if optimal position is 0, 0 moves. if position 1, 1 move. etc.
	// RRB_to_optimal = full_stack->size_b - optimal_position;
void ft_calculate_cost(t_stack_list *a_element, t_stacks *full_stack, t_cost *cost)
{
	ft_calculate_sizes(full_stack);
	ft_set_positions(full_stack);
	int optimal_position = ft_optimal_position(a_element->value, full_stack->b_head);
	// printf("\nft_calculate_cost:\n");
	// printf("\t- size: a:%d, b:%d, optimal_position for \"%d\": %d\n", full_stack->size_a, full_stack->size_b, a_element->value, optimal_position);

	cost->xRA = a_element->position;
	cost->xRRA = full_stack->size_a - cost->xRA;
	if (a_element->position == 0)  // optimisation: if a_element is already at the top, don't do any reverse rotations
		cost->xRRA = 0;

	cost->xRB = optimal_position;
	cost->xRRB = full_stack->size_b - cost->xRB;
	if (optimal_position == 0 || optimal_position == full_stack->size_b)  // optimisation: if optimal_position is at the top, do 0 reverse rotations
	{
		cost->xRRB = 0;
		cost->xRB = 0;
	}

	cost->xRR = ft_min(cost->xRA, cost->xRB);
	cost->xRRR = ft_min(cost->xRRA, cost->xRRB);

	cost->xRB_aggregated = cost->xRB - cost->xRR;
	cost->xRRB_aggregated = cost->xRRB - cost->xRRR;
	cost->xRA_aggregated = cost->xRA - cost->xRR;
	cost->xRRA_aggregated = cost->xRRA - cost->xRRR;

	cost->total = cost->xRA + cost->xRB + cost->xRRA + cost->xRRB + cost->xRR + cost->xRRR;
/* 	printf("\t- total cost BEFORE adjustments: %d (from: %d (xRA) + %d (xRA_aggregated) + %d (xRRA) + %d (xRRA_aggregated) + %d (xRB) \
+ %d (xRB_aggregated) + %d (xRRB_aggregated) + %d (xRR) + %d (xRRR))\n", cost->total, cost->xRA, \
	cost->xRA_aggregated, cost->xRRA, cost->xRRA_aggregated, cost->xRB, cost->xRB_aggregated, cost->xRRB_aggregated, cost->xRR, cost->xRRR); */

	int costt[4];
	costt[0] = cost->xRR + ft_max(cost->xRA, cost->xRB) - ft_min(cost->xRA, cost->xRB);
	costt[1] = cost->xRRR + ft_max(cost->xRRA,cost->xRRB) - ft_min(cost->xRRA, cost->xRRB);
	costt[2] = cost->xRA + cost->xRRB;
	costt[3] = cost->xRB + cost->xRRA;

	// printf("\t- values of costt: %d, %d, %d, %d\n", costt[0], costt[1], costt[2], costt[3]);
	int i = -1;
	int min_cost = ft_min(ft_min(costt[0], costt[1]), ft_min(costt[2], costt[3]));
	while (++i < 4)
		if (min_cost == costt[i])
			break;
	if (i == 0)
	{
		cost->xRRR = 0;
		cost->xRRA = 0;
		cost->xRRB = 0;
		cost->xRA = cost->xRA_aggregated;
		cost->xRB = cost->xRB_aggregated;
		// printf("\t- min_cost of %d (costt[%d]) selected: (%d RR, %d RA, %d RB)\n", min_cost, i, cost->xRR, cost->xRA, cost->xRB);
	}
	else if (i == 1)
	{
		cost->xRR = 0;
		cost->xRA = 0;
		cost->xRB = 0;
		cost->xRRA = cost->xRRA_aggregated;
		cost->xRRB = cost->xRRB_aggregated;
		// printf("\t- min_cost of %d (costt[%d]) selected: (%d RRR, %d RRA, %d RRB)\n", min_cost, i, cost->xRRR, cost->xRRA, cost->xRRB);
	}
	else if (i == 2)
	{
		cost->xRR = 0;
		cost->xRB = 0;
		cost->xRRR = 0;
		cost->xRRA = 0;
		//printf("\t- min_cost of %d (costt[%d]) selected: (%d RA, %d RRB)\n", min_cost, i, cost->xRA, cost->xRRB);
	}
	else if (i == 3)
	{
		cost->xRR = 0;
		cost->xRA = 0;
		cost->xRRR = 0;
		cost->xRRB = 0;
		//printf("\t- min_cost of %d (costt[%d]) selected: (%d RB, %d RRA)\n", min_cost, i, cost->xRB, cost->xRRA);
	}
	cost->total = cost->xRA + cost->xRB + cost->xRRA + cost->xRRB + cost->xRR + cost->xRRR;
/* 	printf("\t- total cost AFTER adjustments: %d (from: %d (xRA) + %d (xRA_aggregated) + %d (xRRA) + %d (xRRA_aggregated) + %d (xRB) \
+ %d (xRB_aggregated) + %d (xRRB_aggregated) + %d (xRR) + %d (xRRR))\n", cost->total, cost->xRA, \
	cost->xRA_aggregated, cost->xRRA, cost->xRRA_aggregated, cost->xRB, cost->xRB_aggregated, cost->xRRB_aggregated, cost->xRR, cost->xRRR); */
}
