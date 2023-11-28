/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:58:36 by fallan            #+#    #+#             */
/*   Updated: 2023/11/28 10:06:36 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */

/* t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode->content = *content;
	newnode->next = NULL;
	return (*content);
} */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current = *lst;
	while (current->next != NULL)
		current = current->next;
	
	current->next = (t_list *)malloc(sizeof(t_list));
	current->next->content = (void *)new;
	current->next->next = NULL;
}

/* int	main()
{
	t_list *node0 = malloc(sizeof(t_list)); // Allocate memory for the first node
    t_list *node1 = malloc(sizeof(t_list)); // Allocate memory for the second node

    if (!node0 || !node1)
		return (1);

	int nodecontent0 = 1;
	int nodecontent1 = 2;

	node0->content = &nodecontent0;
	node0->next = node1;

	node1->content = &nodecontent1;
	node1->next = NULL;

	int result = *(int *)(node0->next->content);

	printf("The content of the node after node0 is : %d\n", result);

// void	ft_lstadd_back(t_list **lst, t_list *new)
	int nodecontent2 = 3;
	ft_lstadd_back(&(node0), (t_list *)&nodecontent2);

	int result2 = *(int *)(node1->next->content);

	printf("The content of the last node after ft_lstadd_back is : %d\n", result2);

	return (0);
} */