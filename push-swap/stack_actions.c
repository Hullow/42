/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:13:09 by fallan            #+#    #+#             */
/*   Updated: 2024/05/14 20:47:26 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// using a define set in push_swap.h, calls the various actions:
// PA (push to stack A), PB (push to stack B),
// RA (rotate stack A), RB (rotate stack B),
// RRA (reverse rotate stack A), RB (reverse rotate stack B)
void	ft_do_action(int action, t_stacks *full_stack)
{
	if (action == 1)
		ft_push_a(full_stack);
	else if (action == 2)
		ft_push_b(full_stack);
	else if (action == 3)
		ft_rotate(&(full_stack->a_head), &(full_stack->a_tail));
	else if (action == 4)
		ft_rotate(&(full_stack->b_head), &(full_stack->b_tail));
	else if (action == 5)
		ft_reverse_rotate(&(full_stack->a_head), &(full_stack->a_tail));
	else if (action == 6)
		ft_reverse_rotate(&(full_stack->b_head), &(full_stack->b_tail));
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

// sends the first element (head) to the end of the list (tail)
// the second element of the list becomes the new head
void	ft_rotate(t_stack_list **head, t_stack_list **tail)
{
	t_stack_list	*temp_new_head;

	temp_new_head = (*head)->next;
	(*head)->next = NULL;
	(*tail)->next = *head;
	*tail = *head;
	(*tail)->next = NULL;
	*head = temp_new_head;
}

// sends the last element of the list (tail) to the beginning (head)
// the penultimate element becomes the last (tail)
void	ft_reverse_rotate(t_stack_list **head, t_stack_list **tail)
{
	t_stack_list	*temp_old_head;
	t_stack_list	*penultimate;

	temp_old_head = *head;
	penultimate = *head;
	while (penultimate->next != *tail)
		penultimate = penultimate->next;
	(*tail)->next = temp_old_head;
	*head = *tail;
	(*tail)->next = NULL;
	*tail = penultimate;
	(*tail)->next = NULL;
	(*head)->next = temp_old_head;
}
