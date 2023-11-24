/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:23:13 by fallan            #+#    #+#             */
/*   Updated: 2023/11/24 19:39:58 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.learn-c.org/en/Linked_lists
// https://www.educative.io/answers/how-to-use-the-typedef-struct-in-c
// https://www.simplilearn.com/tutorials/c-tutorial/singly-linked-list-in-c : "A Singly linked list is a collection of data called nodes, where each node is divided into two parts to store data and address at some random addresses. The pointer next, points to the address of the next node in a list."

#include "Libft.h"

/* typedef struct	s_list
{
	void			*content; a pointer to content. to get its content, "*content"
	struct s_list	*next; a pointer to the next node. to get its address, "*node"
}					t_list; */

// we've got a linked list, we want to add an element


t_list *ft_lstnew(void *content) // input: we've got a pointer to content. 
{
	t_list	*new_node; // we declare a new pointer 
	
	new_node = (t_list *)malloc(sizeof(t_list)); // we declare a new node

	// new_node->next = (t_list *)malloc(sizeof(t_list));
	// if (new_node == NULL)
	// 	return (NULL);

	new_node->content = content;
	new_node->next = NULL;
	return (new_node->content);
}

/* int main()
{

return (0);
} */