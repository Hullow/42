/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:09:24 by bwach             #+#    #+#             */
/*   Updated: 2023/11/06 09:24:43 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_print_hex(unsigned int nbr, const char conversion);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_percent(void);
int		ft_print_unsigned(unsigned int nbr);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_print_percent(void);
int		ft_printnbr(int n);

#endif