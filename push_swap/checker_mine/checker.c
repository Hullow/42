/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:48:12 by fallan            #+#    #+#             */
/*   Updated: 2024/05/31 19:03:06 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_execute_move(char *move, t_stacks *full_stack);

int main(int argc, char **argv)
{
	int			i;
	int			found;
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
		ft_find_duplicates(full_stack);

		char	*move = malloc(sizeof(char) * 4);
		char	*temp = malloc(sizeof(char) * 40);
		while (1)
		{
			if (read(0, move, 4) > 0)
				found = ft_execute_move(move, full_stack);
			else
			{
				free(move);
				exit(0);
			}
			if (found == 1)
				ft_print_both_stacks(full_stack);
			else if (found == 0)
			{
				ft_check_stack(full_stack);
				free(move);
				exit(0);
			}				
			else
			{
				ft_printf("Error: move not recognised, please enter move\n");
				read(0, temp, 40); // to clear the buffer
			}
		}
	}
	return (0);
}

// matches the input (char *move) to an action on the stack,
// and executes the action
// returns the value of found to indicate whether there was a match
int	ft_execute_move(char *move, t_stacks *full_stack)
{
	char *table[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "rr", "rrr", "end"};
	int	i;
	int	found;

	i = 1;
	found = -1;
	while (move[++i] && i <= 3)
	{
		if (move[i] == '\n')
		{
			move[i] = '\0';
			found = 1;
			ft_printf("ft_execute_move: replaced \\n with \\0\n");
			break;
		}
	}
	if (found == -1)
		return (found);
	i = -1;
	while (table[++i])
	{
		if (!ft_strncmp(move, table[i], 4))
		{
			printf("ft_execute_move: move is %s, table[%d] is %s\n", move, i, table[i]);
			if (i == 10)
			{
				found = 0;
				ft_printf("ending\n");
				break;
			}
			ft_do_multiple_actions(i + 1, full_stack, 1);
			found = 1;
			break;
		}
	}
	return (found);
}
