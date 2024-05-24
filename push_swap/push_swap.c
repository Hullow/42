/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/24 20:21:31 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	*full_stack;

	if (argc == 1)
		return (-1);
	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
		{
			printf("[%d]:%s ", i, argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		ft_printf("input okay\n");
		full_stack = ft_string_to_stack(argv, i);
		ft_do_multiple_actions(RRA, full_stack, 4);
		ft_do_multiple_actions(PB, full_stack, 5);
		ft_do_multiple_actions(RB, full_stack, 3);
		ft_do_multiple_actions(PA, full_stack, 3);
		ft_do_multiple_actions(RA, full_stack, 2);
		ft_do_multiple_actions(PB, full_stack, 1);
		ft_do_multiple_actions(RB, full_stack, 2);
		ft_do_multiple_actions(RRA, full_stack, 1);
		ft_do_multiple_actions(RRA, full_stack, 5);
		ft_do_multiple_actions(RRB, full_stack, 2);
		ft_do_multiple_actions(RB, full_stack, 1);
		ft_do_multiple_actions(PA, full_stack, 1);
		ft_do_multiple_actions(RA, full_stack, 1);

		ft_printf("\nafter a few manips:\na:\n");
		ft_print_list(full_stack->a_head);
		ft_printf("\nb:\n");
		ft_print_list(full_stack->b_head);

		ft_calculate_sizes(full_stack);
		ft_set_positions(full_stack);
	
	
		t_stack_list	*a_iterator = full_stack->a_head;
		t_stack_list	*best_element_to_insert;
		t_elem_insert	*insertion;
		t_elem_insert	*best_element_insertion;
		insertion = ft_optimised_insertion(full_stack->a_head, full_stack);
		int				minimal_insertion_moves;
		minimal_insertion_moves = insertion->total_moves_final;
		best_element_to_insert = full_stack->a_head;
		while (a_iterator->next)
		{
			a_iterator = a_iterator->next;
			insertion = ft_optimised_insertion(a_iterator, full_stack);
			// printf("\nthe optimised insert has actions:\n");
			// ft_print_moves(insertion);
			if (insertion->total_moves_final < minimal_insertion_moves)
			{
				best_element_to_insert = a_iterator;
				printf("new best element to insert found: %d – %d) in stack a\n", a_iterator->value, a_iterator->position);
			}
		}
		best_element_insertion = ft_optimised_insertion(best_element_to_insert, full_stack);
		printf("the best element to insert is \"%d\" – %d) in stack a, with moves:\n", best_element_to_insert->value, best_element_to_insert->position);
		ft_print_moves(best_element_insertion);
		// ft_free_full_stack(&full_stack);
	}
	return (0);
}
