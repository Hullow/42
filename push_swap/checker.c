/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:48:12 by fallan            #+#    #+#             */
/*   Updated: 2024/06/20 17:15:42 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// stacks = ft_input_handling(argv, stacks); 
//				=> checks input for errors
// found = ft_read_and_execute_sequence(0, stacks); 
// 				=> reads all arguments from input and executes the move
// if (found == 0)
//				=> we've reached the end (GNL returned NULL)
// ft_checker(stacks);
//				=> checks if the stack a is ordered and stack b empty
int	main(int argc, char **argv)
{
	int			found;
	t_stacks	*stacks;

	found = 0;
	stacks = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		return (0);
	if (argc > 1)
	{
		stacks = ft_checker_input_handling(argv, stacks);
		found = ft_read_and_execute_sequence(0, stacks);
		if (found == 0)
			ft_checker(stacks);
		if (found == -1)
		{
			ft_printf("\nfound == -1\n");
			write(2, "Error\n", 7);
			ft_print_both_stacks(stacks);
		}
		ft_free_stacks_and_exit(&stacks);
	}
	return (0);
}

// checks if stack a is ordered, prints stacks, frees the memory and exits
// called from main if GNL arrived at the end (found == 0)
void	ft_checker(t_stacks *stacks)
{
	if (ft_check_stack(stacks) != 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_print_both_stacks(stacks);
	ft_free_stacks_and_exit(&stacks);
}

// checks the input for issues (non-numbers, duplicates, etc.)
// stores the input inside a struct t_stacks
t_stacks	*ft_checker_input_handling(char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_check_input(argv[i]) == NULL)
		{
			write(2, "Error\n", 7);
			exit (-1);
		}
	}
	stacks = ft_string_to_stack(argv, i);
	ft_find_duplicates(stacks);
	return (stacks);
}
