/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:14 by fallan            #+#    #+#             */
/*   Updated: 2024/05/14 00:27:32 by fallan           ###   ########.fr       */
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
		ft_printf("\nb after 4 * PB:\n");
		ft_do_action(PB, full_stack);
		ft_do_action(PB, full_stack);
		ft_do_action(PB, full_stack);
		ft_do_action(PB, full_stack);
		ft_print_list(full_stack->b_head);
		// ft_printf("\nb after 1 * RB:\n");
		// ft_do_action(RB, full_stack);
		// ft_print_list(full_stack->b_head);
		ft_do_action(RRB, full_stack);
		ft_do_action(RRB, full_stack);
		ft_do_action(RRB, full_stack);
		ft_printf("\nb after 3 * RRB:\n");
		ft_print_list(full_stack->b_head);
		// ft_print_list(full_stack->b_head);
		// ft_do_action(PA, full_stack);
		// ft_do_action(PA, full_stack);
		// ft_do_action(PA, full_stack);
		// ft_do_action(PA, full_stack);
		// ft_print_list(full_stack->a_head);
		// ft_print_list(full_stack->b_head);

		// ft_free_full_stack(&full_stack);
	}
	return (0);
}
