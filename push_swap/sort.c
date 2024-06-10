/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:01:50 by fallan            #+#    #+#             */
/*   Updated: 2024/06/10 17:12:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the sorting function that calls all functions
// checks for duplicates in the input
// checks if stack is already ordered
// calculates size of stack and positions of each element
// uses hardcoded sorting function for small stacks (< 6 elements)
// uses "Turkish" algorithm for larger stacks
void	ft_sort(t_stacks *stacks)
{
	if (ft_check_stack(stacks) == 0)
		return ;
	ft_calculate_sizes(stacks);
	ft_set_positions(stacks);
	if (stacks->size_a < 6)
		ft_sort_small_stack(stacks);
	else
		ft_sort_large_stack(stacks);
}

// hardcoded sorting of small stacks (size < 6)
void	ft_sort_small_stack(t_stacks *stacks)
{
	if (stacks->size_a == 2 && ft_check_stack(stacks) != 0)
		ft_do_multiple_actions(SA, stacks, 1, 0);
	if (stacks->size_a == 3 && ft_check_stack(stacks) != 0)
		ft_sort_three_elements(stacks);
	else if (stacks->size_a == 4 && ft_check_stack(stacks) != 0)
		ft_sort_four_elements(stacks);
	else if (stacks->size_a == 5 && ft_check_stack(stacks) != 0)
		ft_sort_five_elements(stacks);
}

// sorts stack size 6 and above
// algorithm: "Turkish"
// - pushes the first two elements to b
// - while(): calculates the (optimised) cost of insertion
// for each element of stack a into stack b
// in a way that the element is at its place in b,
//      - inner while(): selects the cheapest insertion
//      - performs the cheapest insertion from a into b (ft_cheapest_insertion)
//	  - does this until stack a is empty
// - pushes back all elements from b to a
void	ft_sort_large_stack(t_stacks *stacks)
{
	t_cost	*cost;
	t_cost	*min_cost_insert;
	t_stack	*iterator;

	cost = malloc (sizeof(t_cost));
	min_cost_insert = malloc (sizeof(t_cost));
	ft_do_multiple_actions(PB, stacks, 2, 0);
	min_cost_insert->total = INT_MAX;
	iterator = stacks->a_head;
	while (iterator)
	{
		while (iterator)
		{
			ft_calculate_cost(iterator, stacks, cost);
			if (cost->total < min_cost_insert->total)
				ft_set_min_cost(cost, min_cost_insert);
			iterator = iterator->next;
		}
		ft_do_cheapest_insertion(stacks, min_cost_insert);
		iterator = stacks->a_head;
		min_cost_insert->total = INT_MAX;
	}
	ft_sort_and_empty_stack_b(stacks);
	free(cost);
	free(min_cost_insert);
}

// rearrange b_stack to put maximum value at the top
// and push everything to a_stack
void	ft_sort_and_empty_stack_b(t_stacks *stacks)
{
	t_stack	*max;

	max = ft_stack_max_value(stacks->b_head);
	if (max->position < stacks->size_b / 2)
		while (stacks->b_head != max)
			ft_do_multiple_actions(RB, stacks, 1, 0);
	else
		while (stacks->b_head != max)
			ft_do_multiple_actions(RRB, stacks, 1, 0);
	while (stacks->b_head)
		ft_do_multiple_actions(PA, stacks, 1, 0);
}
