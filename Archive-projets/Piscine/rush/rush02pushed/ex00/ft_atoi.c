/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:50:14 by cmegret           #+#    #+#             */
/*   Updated: 2023/07/30 07:36:32 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	is_numeric(char *str, int *number_found, long int *result)
{
	while (*str >= '0' && *str <= '9')
	{
		*number_found = 1;
		*result = *result * 10 + (*str - '0');
		str++;
	}
}

long int	ft_atoi(char *str)
{
	long int	result;
	int			number_found;

	result = 0;
	number_found = 0;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			if (is_alpha(*str))
				return (-1);
			str++;
		}
		is_numeric(str, &number_found, &result);
		if (number_found == 1)
			break ;
	}
	return (result);
}

int	is_valid(char *str)
{
	int	is_valid;

	is_valid = 1;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			is_valid = 0;
			break ;
		}
		str++;
	}
	return (is_valid);
}
