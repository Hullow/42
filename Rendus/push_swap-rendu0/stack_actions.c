/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:13:09 by fallan            #+#    #+#             */
/*   Updated: 2024/06/10 17:39:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adds the first element (== head) of the b stack
// to the beginning (== head) of the a stack
// and removes the element from the b stack
// method line by line:
// method line by line:
	// if stack a exists:
		// point the head of b to the head of a
		// set the new head of a to the head of b
		// set the head of b to the second element
	// if stack a doesn't exists:
	// set the new head of a to the head of b
	// set the head of a (aka ex head of b) to point to NULL
	// set the tail of a to be the same as the head of a 
	// set the new head of b
void	ft_push_a(t_stacks *stacks)
{
	t_stack	*temp_b_new_head;

	if (!stacks->b_head)
	{
		ft_printf("stack b empty, cannot push to a\n");
		return ;
	}
	temp_b_new_head = stacks->b_head->next;
	if (stacks->a_head)
	{
		stacks->b_head->next = stacks->a_head;
		stacks->a_head = stacks->b_head;
		stacks->b_head = temp_b_new_head;
	}
	else
	{
		stacks->a_head = stacks->b_head;
		stacks->a_head->next = NULL;
		stacks->a_tail = stacks->a_head;
		stacks->b_head = temp_b_new_head;
	}
}

// adds the first element (== head) of the a stack
// to the beginning (== head) of the b stack
// and removes the element from the a stack
// method line by line:
	// if stack b exists:
		// point the head of a to the head of b
		// set the new head of b to the head of a
		// set the head of a to the second element
	// if stack b doesn't exists:
	// set the new head of b to the head of a
	// set the head of b (aka ex head of a) to point to NULL
	// set the tail of b to be the same as the head of b 
	// set the new head of a
void	ft_push_b(t_stacks *stacks)
{
	t_stack	*a_second_element;

	a_second_element = stacks->a_head->next;
	if (!stacks->a_head)
	{
		ft_printf("stack a empty, cannot push to b\n");
		return ;
	}
	if (stacks->b_head)
	{
		stacks->a_head->next = stacks->b_head;
		stacks->b_head = stacks->a_head;
		stacks->a_head = a_second_element;
	}
	else
	{
		stacks->b_head = stacks->a_head;
		stacks->b_head->next = NULL;
		stacks->b_tail = stacks->b_head;
		stacks->a_head = a_second_element;
	}
}

// swap the first two elements of the stack
// method line by line:
	// new head is the 2nd element
	// old head points to 3rd element
	// 2nd element points to old head
	// new head is old 2nd element
void	ft_swap(t_stack **head, t_stack **tail, int stack_size)
{
	t_stack	*temp_new_head;

	if (!head || !(*head) || stack_size == 1)
		return ;
	if (stack_size == 2)
	{
		ft_rotate(head, tail);
		return ;
	}
	else
	{
		temp_new_head = (*head)->next;
		(*head)->next = (*head)->next->next;
		temp_new_head->next = *head;
		*head = temp_new_head;
	}
}

// sends the first element (head) to the end of the list (tail)
// the second element of the list becomes the new head
void	ft_rotate(t_stack **head, t_stack **tail)
{
	t_stack	*temp_new_head;

	if (!head || !tail || !(*head) || !(*tail) || (*head == *tail))
	{
		ft_printf("no element or a single element found, could not rotate\n");
		return ;
	}
	temp_new_head = (*head)->next;
	(*head)->next = NULL;
	(*tail)->next = *head;
	*tail = *head;
	(*tail)->next = NULL;
	*head = temp_new_head;
}

// sends the last element of the list (tail) to the beginning (head)
// the penultimate element becomes the last (tail)
void	ft_reverse_rotate(t_stack **head, t_stack **tail)
{
	t_stack	*temp_old_head;
	t_stack	*penultimate;

	if (!head || !tail || !(*head) || !(*tail) || (*head == *tail))
	{
		ft_printf("reverse rotation: head/tail not found, nothing done\n");
		return ;
	}
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
