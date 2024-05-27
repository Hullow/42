/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/27 14:44:44 by fallan           ###   ########.fr       */
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

		ft_printf("\nafter a few manips:\n");
		ft_print_both_stacks(full_stack);
	
		// calculates the optimal element to insert
		ft_do_optimal_insertion(full_stack);
		ft_print_both_stacks(full_stack);

		ft_do_optimal_insertion(full_stack);
		ft_print_both_stacks(full_stack);

		ft_do_optimal_insertion(full_stack);
		ft_print_both_stacks(full_stack);

		ft_do_optimal_insertion(full_stack);
		ft_print_both_stacks(full_stack);

		ft_do_optimal_insertion(full_stack);
		ft_print_both_stacks(full_stack);

		// ft_free_full_stack(&full_stack);
	}
	return (0);
}
