/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:01:50 by fallan            #+#    #+#             */
/*   Updated: 2024/06/07 18:27:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the sorting function that calls all functions
// checks for duplicates in the input
// checks if stack is already ordered
// calculates size of stack and positions of each element
// uses hardcoded sorting function for small stacks (< 6 elements)
// uses "Turkish" algorithm for larger stacks
void	ft_sort(t_stacks *full_stack)
{
	ft_find_duplicates(full_stack);
	if (ft_check_stack(full_stack) == 0)
		return ;
	ft_calculate_sizes(full_stack);
	ft_set_positions(full_stack);
	if (full_stack->size_a < 6)
		ft_sort_small_stack(full_stack);
	else
		ft_sort_big_stack(full_stack);
}

// hardcoded sorting of small stacks (size < 6)
void	ft_sort_small_stack(t_stacks *full_stack)
{
	if (full_stack->size_a == 2 && ft_check_stack(full_stack) != 0)
		ft_do_multiple_actions(SA, full_stack, 1, 0);
	if (full_stack->size_a == 3 && ft_check_stack(full_stack) != 0)
		ft_sort_three_elements(full_stack);
	else if (full_stack->size_a == 4 && ft_check_stack(full_stack) != 0)
		ft_sort_four_elements(full_stack);
	else if (full_stack->size_a == 5 && ft_check_stack(full_stack) != 0)
		ft_sort_five_elements(full_stack);
}

// sorts stack size 6 and above
// algorithm: "Turkish"
// - starts by pushing the first two elements to b
// - then computes the cheapest element of a to place at its sorted place in b
// - pushes this element to b
// - does this until stack a is empty
// - then pushes back all elements from b to a  
void	ft_sort_big_stack(t_stacks *full_stack)
{
	t_cost			*cost;
	t_cost			*min_cost_insert;
	t_stack_list	*iterator;

    cost = malloc (sizeof(t_cost));
    min_cost_insert = malloc (sizeof(t_cost));
	ft_do_multiple_actions(PB, full_stack, 2, 0);
	min_cost_insert->total = INT_MAX;
	iterator = full_stack->a_head;
	while (iterator)
	{
		while (iterator) // compute cheapest element
		{
			ft_calculate_cost(iterator, full_stack, cost);
			if (cost->total < min_cost_insert->total)
			    ft_set_min_cost(cost, min_cost_insert);
			iterator = iterator->next;
		}
        ft_do_optimal_insertion(full_stack, min_cost_insert);// insert cheapest element
		iterator = full_stack->a_head;
		min_cost_insert->total = INT_MAX;
	}
    ft_sort_and_empty_stack_b(full_stack);
	free(cost);
	free(min_cost_insert);
}

// rearrange b_stack to put maximum value at the top
// and push everything to a_stack
void    ft_sort_and_empty_stack_b(t_stacks *full_stack)
{  
	t_stack_list *max;

    max = ft_stack_max_value(full_stack->b_head);
	while (full_stack->b_head != max)
		ft_do_multiple_actions(RB, full_stack, 1, 0);
	while (full_stack->b_head)
		ft_do_multiple_actions(PA, full_stack, 1, 0);
}
