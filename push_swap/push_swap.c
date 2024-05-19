/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/19 18:47:46 by francis          ###   ########.fr       */
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
		ft_do_multiple_actions(PB, full_stack, 4);
		// ft_do_multiple_actions(RRB, full_stack, 1);
		ft_printf("\nafter a few manips:\na:\n");
		ft_print_list(full_stack->a_head);
		ft_printf("\nb:\n");
		ft_print_list(full_stack->b_head);
		ft_calculate_sizes(full_stack);
		ft_optimal_insertion(full_stack->a_head, full_stack);
		// printf("result of those moves:\n");
		// ft_do_multiple_actions(RA, full_stack, 1);
		// ft_do_multiple_actions(RB, full_stack, 4);
		// ft_print_list(full_stack->a_head);
		// ft_printf("\nb:\n");
		// ft_print_list(full_stack->b_head);

		// ft_set_position(full_stack->a_head);
		// ft_free_full_stack(&full_stack);

	}
	return (0);
}
