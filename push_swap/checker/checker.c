/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:48:12 by fallan            #+#    #+#             */
/*   Updated: 2024/06/05 13:44:18 by fallan           ###   ########.fr       */
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
			// if (found == 1)
			// 	ft_print_both_stacks(full_stack);
			if (found == 0) // typed "end"
			{
				if (ft_check_stack(full_stack) != 0)
					ft_printf("KO\n");
				free(move);
				exit(0);
			}				
			else if (found != 1)
			{
				ft_printf("Error: move not recognised, please enter move\n");
				read(0, temp, found + 47); // found is ft_strlen(move), 47 is the print we just entered to clear the buffer
				// ft_print_both_stacks(full_stack);
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
	char *table[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "rr", "rrr", "end", NULL};
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
			break;
		}
	}
	if (found == -1)
		return (found);
	i = -1;
	found = -1;
	while (table[++i])
	{
		if (!ft_strncmp(move, table[i], 4))
		{
			if (i == 10)
				return (0);
			ft_do_multiple_actions(i + 1, full_stack, 1);
			found = 1;
			break;
		}
	}
	if (found == -1)
		found = ft_strlen(move);
	return (found);
}
