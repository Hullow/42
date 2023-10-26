/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:00 by francis           #+#    #+#             */
/*   Updated: 2023/10/26 17:08:40 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("your string '%s' is %zu characters \
		long.\n", argv[1], ft_strlen(argv[1]));
	return (0);
}
