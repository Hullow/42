/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:13:09 by fallan            #+#    #+#             */
/*   Updated: 2024/05/13 23:13:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_action(int action, t_stacks *full_stack)
{
	if (action == 1)
		ft_push_a(full_stack);
	else if (action == 2)
		ft_push_b(full_stack);
}

// adds the first element (== head) of the b stack
// to the beginning (== head) of the a stack
// and removes the element from the b stack
void	ft_push_a(t_stacks *full_stack)
{
	t_stack_list	*temp_b_new_head;

	temp_b_new_head = full_stack->b_head->next;
	if (full_stack->a_head)
	{
		full_stack->b_head->next = full_stack->a_head; // point the head of a to the head of b
		full_stack->a_head = full_stack->b_head; // set the new head of b to the head of a, which
		full_stack->b_head = temp_b_new_head;
	}
	else
	{
		full_stack->a_head = full_stack->b_head; // set the new head of b to the head of a
		full_stack->a_head->next = NULL; // set the head of b (aka ex head of a) to point to NULL
		full_stack->a_tail = full_stack->a_head; // set the tail of b to be the same as the head of b 
		full_stack->b_head = temp_b_new_head; // set the new head of a
	}
}

// adds the first element (== head) of the a stack
// to the beginning (== head) of the b stack
// and removes the element from the a stack
void	ft_push_b(t_stacks *full_stack)
{
	t_stack_list	*temp_a_new_head;
	
	temp_a_new_head = full_stack->a_head->next;
	if (full_stack->b_head)
	{
		full_stack->a_head->next = full_stack->b_head; // point the head of a to the head of b
		full_stack->b_head = full_stack->a_head; // set the new head of b to the head of a, which
		full_stack->a_head = temp_a_new_head;
	}
	else
	{
		full_stack->b_head = full_stack->a_head; // set the new head of b to the head of a
		full_stack->b_head->next = NULL; // set the head of b (aka ex head of a) to point to NULL
		full_stack->b_tail = full_stack->b_head; // set the tail of b to be the same as the head of b 
		full_stack->a_head = temp_a_new_head; // set the new head of a
	}
}
