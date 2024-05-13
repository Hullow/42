/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/13 23:06:30 by fallan           ###   ########.fr       */
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

int	*ft_atoi_to_pointer(char *string)
{
	int	*ptr;

	ptr = malloc (sizeof(int));
	*ptr = ft_atoi(string);
	return (ptr);
}

t_stacks	*ft_string_to_stack(char **argv, int i)
{
	t_stack_list	*a_stack;
	t_stack_list	*a_head;
	t_stacks		*full_stack;
	int				count;

	count = i;
	i = 1;
	a_stack = ft_new_stack_node(ft_atoi(argv[i]));
	full_stack = (t_stacks *) malloc(sizeof(t_stacks)); // correct ?
	a_head = a_stack;
	printf("\n\n%d\n", a_stack->value);
	while (++i < count)
	{
		a_stack->next = ft_new_stack_node(ft_atoi(argv[i]));
		a_stack = a_stack->next;
		printf("%d\n", a_stack->value);
	}
	printf("_             _\n");
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

int main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
		return (-1);
	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
		{
			printf("%d: %s ", i, argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		t_stacks *full_stack = ft_string_to_stack(argv, i);
		ft_do_action(PB, full_stack);
		ft_do_action(PB, full_stack);
		ft_do_action(PB, full_stack);
		ft_do_action(PB, full_stack);
		ft_print_list(full_stack->a_head);
		ft_print_list(full_stack->b_head);

		ft_do_action(PA, full_stack);
		ft_do_action(PA, full_stack);
		ft_do_action(PA, full_stack);
		ft_do_action(PA, full_stack);
		ft_print_list(full_stack->a_head);
		ft_print_list(full_stack->b_head);
		ft_free_full_stack(&full_stack);
	}
	ft_printf("\ninput okay\n");
	return (0);

}