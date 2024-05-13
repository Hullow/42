/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:24:15 by fallan            #+#    #+#             */
/*   Updated: 2024/05/13 23:10:09 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adapted from ft_lstnew (libft bonus)
t_stack_list	*ft_new_stack_node(int value)
{
	t_stack_list	*new_node;

	new_node = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

// Adapted from ft_lstadd_front(libft)
// Ajoute l’élément ’new’ au début de la liste
// lst: L’adresse du pointeur vers le premier élément de la liste.
// new: L’adresse du pointeur vers l’élément à rajouter à la liste.
void	ft_stackadd_front(t_stack_list **stack_head, t_stack_list *new)
{
	new->next = *stack_head;
	*stack_head = new;
}

void	ft_free(void **temp)
{
	if (*temp)
	{
		free(*temp);
		*temp = NULL;
	}
}

void	ft_free_full_stack(t_stacks **full_stack)
{
	while ((*full_stack)->b_head)
	{
		free((*full_stack)->b_head);
		(*full_stack)->b_head = (*full_stack)->b_head->next;
	}
	while ((*full_stack)->a_head)
	{
		free((*full_stack)->a_head);
		(*full_stack)->a_head = (*full_stack)->a_head->next;
	}
	free(*full_stack);
	*full_stack = NULL;
}
