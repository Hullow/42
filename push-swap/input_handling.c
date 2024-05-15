/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:14:20 by fallan            #+#    #+#             */
/*   Updated: 2024/05/15 20:04:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*ft_string_to_stack(char **argv, int i)
{
	t_stack_list	*a_node;
	t_stack_list	*a_head;
	t_stacks		*full_stack;
	int				count;

	count = i;
	i = 1;
	a_node = ft_new_stack_node(ft_atoi(argv[i]));
	full_stack = (t_stacks *) malloc(sizeof(t_stacks)); // correct ?
	a_head = a_node;
	printf("\n\ninput stored in list:\n%d (head)\n", a_node->value);
	while (++i < count - 1)
	{
		a_node->next = ft_new_stack_node(ft_atoi(argv[i]));
		a_node = a_node->next;
		printf("%d\n", a_node->value);
	}
	a_node->next = ft_new_stack_node(ft_atoi(argv[i]));
	full_stack->a_tail = a_node->next;
	full_stack->a_tail->next = NULL;
	ft_printf("%d (tail)\n", full_stack->a_tail->value);
	ft_printf("_             _\n");
	full_stack->a_head = a_head;
	return (full_stack);
}

char	*ft_check_input(char *str)
{
	int	i;
	int	input;

	i = -1;
	while (str[++i])
		if (! ((str[i] >= '0' && str[i] <= '9') || str[0] == '-'))
			return (NULL);
	if (str[0] == '-' && ft_strlen(str) > 11)
		return (NULL);
	else if (str[0] != '-' && ft_strlen(str) > 10)
		return (NULL);
	input = ft_atoi(str);
	if ((str[0] == '-' && input > 0) || (str[0] != '-' && input < 0))
		return (NULL);
	return (str);
}
