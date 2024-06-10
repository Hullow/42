/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:14:20 by fallan            #+#    #+#             */
/*   Updated: 2024/06/10 17:12:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// initializes the struct holding the two stacks
// fills stack a with values from the input
t_stacks	*ft_string_to_stack(char **argv, int i)
{
	t_stack		*a_node;
	t_stack		*a_head;
	t_stacks	*stacks;
	int			count;

	count = i;
	i = 1;
	a_node = ft_new_stack_node(ft_atoi(argv[i]));
	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	a_head = a_node;
	while (++i < count - 1)
	{
		a_node->next = ft_new_stack_node(ft_atoi(argv[i]));
		a_node = a_node->next;
	}
	if (argv[i])
		a_node->next = ft_new_stack_node(ft_atoi(argv[i]));
	stacks->a_tail = a_node->next;
	stacks->a_tail->next = NULL;
	stacks->a_head = a_head;
	stacks->b_head = NULL;
	return (stacks);
}

// verifies that the input has proper form
char	*ft_check_input(char *str)
{
	int	i;
	int	input;

	i = -1;
	if (str[0] == '\0')
		return (NULL);
	if (ft_strrchr(str, '-') - str > 0)
		return (NULL);
	while (str[++i])
		if (! ((str[i] >= '0' && str[i] <= '9') || str[0] == '-'))
			return (NULL);
	if (str[0] == '-' && (ft_strlen(str) > 11 || ft_strlen(str) == 1))
		return (NULL);
	else if (str[0] != '-' && ft_strlen(str) > 10)
		return (NULL);
	input = ft_atoi(str);
	if ((str[0] == '-' && input > 0) || (str[0] != '-' && input < 0))
		return (NULL);
	return (str);
}

// checks for duplicate numbers in stack
void	ft_find_duplicates(t_stacks *stacks)
{
	t_stack	*anchor;
	t_stack	*iterator;

	anchor = stacks->a_head;
	iterator = stacks->a_head;
	while (anchor)
	{
		if (anchor->next)
			iterator = anchor->next;
		else
			return ;
		while (iterator)
		{
			if (anchor->value == iterator->value)
			{
				write(2, "Error (duplicates found in input)\n", 35);
				ft_free_stacks(&stacks);
				exit(-1);
			}
			iterator = iterator->next;
		}
		anchor = anchor->next;
	}
}
