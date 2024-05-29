/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:48:12 by fallan            #+#    #+#             */
/*   Updated: 2024/05/29 12:14:21 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
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
			//printf("[%d]:%s ", i, argv[i]);
			if (ft_check_input(argv[i]) == NULL)
			{
				write(2, "Error\n", 7);
				return (-1);
			}
		}
		//ft_printf("input okay\n");
		full_stack = ft_string_to_stack(argv, i);
		char	*move = malloc(sizeof(char) * 4);
		char	*actions = malloc(sizeof(char) * 4);
		char	*temp;
		static int		j = 0;
		while (1)
		{
			if (read(0, move, 4) > 0)
			{
				ft_execute_move(move, full_stack->a_head);

			}
		}
	}
	return (0);
}

void	ft_execute_move(char *move, t_stack_list *a_stack)
{
	char *table[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "rr", "rrr"};
	int	action;

	if (move[3] == '\n')
		move[3] = '\0';
	else
		ft_printf("ft_execute_move: error in replacing \\n with \\0\n");
	if ()
}