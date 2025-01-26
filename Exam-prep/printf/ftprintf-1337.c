/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf-1337.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:21:36 by francis           #+#    #+#             */
/*   Updated: 2024/09/19 17:43:20 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


To remember:

- Va args:
void function()
{
	va_list *arg_list;
	va_start(arg_list);
	va_arg(arg_list, type);
	va_end(arg_list);
}
- count != i; also, increment i++ after each %s
- putnbr: -2147483648, < 0 => write - and * (-1), / 10, %10, number += 48 -= 48
- hex: analog to putnbr but print_hex needed for 10-15 => number += some ascii value

// printf("Hello my name is %s and I am %d years old. My favorite memory address is %x", "Francis", 1337, 1337);

// Take in arguments to function, store them in memory
// Printing out sentence:
	// Print out characters until you recognize a format specifier:
	// Then, seek arguments in order and use corresponding format printing function to print out the argument
	// Increment an argument counter
	// Continue printing until you arrive at the end of the first argument
	// Increment a counter of characters printed out


	// Questions: return value ?
	// #include <string.h> allowed ?

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_putnbr(int number)
{
	int	count;

	count = 0;
	// printf("number: %d\n", number);
	if (number == -2147483648)
		return(write(1, "-2147483648", 11));
	else if (number < 0)
	{
		count += write(1, "-", 1);
		number *= -1;
	}
	if (number < 10)
	{
		number += 48;
		count += write(1, &number, 1);
		number -= 48;
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	return (count);
}

int	ft_print_hex(int number)
{
	if (number < 10)
		ft_putnbr(number);
	else if (number == 10)
		write(1, 'A', 1);
	else if (number == 10)
		write(1, 'A', 1);
	else if (number == 10)
		write(1, 'A', 1);
	else if (number == 10)
		write(1, 'A', 1);
	else if (number == 10)
		write(1, 'A', 1);
	else if (number == 10)
		write(1, 'A', 1);


}

int	ft_put_hex(int number)
{
	int	count;

	count = 0;
	// printf("number: %d\n", number);
	if (number == -2147483648)
		return(write(1, "-2147483648", 11));
	else if (number < 0)
	{
		count += write(1, "-", 1);
		number *= -1;
	}
	if (number < 16)
		count += ft_print_hex(number);
	else
	{
		ft_putnbr(number / 16);
		ft_putnbr(number % 16);
	}
	return (count);
}


int	ft_print_string(char *string)
{
	int	i;
	
	// printf("ft_print_string: string is {%s}\n", string);
	if (!string)
	{
		write(1, "No string to print\n", 20);
		return (-1);
	}
	i = 0;
	while (string[i])
		write(1, &string[i++], 1);
	return (i);
}

int	ft_printf_1337(char *string, ...)
{
	int		i;
	int		count;
	va_list	arg_list;

	va_start(arg_list, string);
	i = -1;
	count = 0;
	while (string[++i])
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == 's')
			{
				count += ft_print_string(va_arg(arg_list, char *));
				i++;
			}
			else if (string[i + 1] == 'd')
			{
				count += ft_putnbr(va_arg(arg_list, int));
				i++;
			}
			else if (string[i + 1] == 'x')
			{
				count += ft_put_hex(va_arg(arg_list, int));
				i++;
			}
			else
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(string[i]);
	}
	va_end(arg_list);
	return (count);
}

int	main()
{
	// ft_printf_1337("Hello, world !\n");
	// ft_printf_1337("Hello, world ! String: %s \n", "test string");
	// ft_printf_1337("%s\n", "test string");
	// ft_printf_1337("%d\n", 5);
	ft_printf_1337("%d is my favorite %s, but I prefer it in hex: %x\n", -271719, "number", -271719);
	return (1);
}


	/* 
	The va_arg() macro expands to an expression that has the type and value of the next argument in the call.
	The parameter ap is the va_list ap initialized by va_start(). 
	Each call to va_arg() modifies ap so that the next call returns the next argument. 
	The parameter type is a type name specified so that the type of a pointer to an object that has the specified
     type can be obtained simply by adding a * to type.
	*/



			// else if (string[i + 1] == 'd' || string[i + 1] == 'D')
			// 	i += ft_print_decimal(va_arg(arg_list, int));
			// else if (string[i + 1] == 'x' || string[i + 1] == 'X')
			// 	i += ft_print_hex(va_arg(arg_list, unsigned int));