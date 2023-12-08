#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

// •Your function has to handle the following conversions: cspdiuxX%
//
// c: The int argument is converted to an unsigned char, and the resulting character is written.
//
// s: The char * argument is expected to be a pointer to an array of character type (pointer to a string).
//		Characters from the array are written up to (but not including) a terminating NUL character;
//		if a precision is specified, no more than the number specified are written.  If a precision is given, 
//		no null character need be present; if the precision is not specified, or is greater
//	    than the size of the array, the array must contain a terminating NUL character.
//
// p: The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx').
//
// %: A `%' is written.  No argument is converted.  The complete conversion specification is `%%'.
//
// diuxX : The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation.  The letters
//  		``abcdef'' are used for x conversions; the letters ``ABCDEF'' are used for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value
//  		requires fewer digits, it is padded on the left with zeros.

static int	ft_putnbr(int n, int res)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			n *= (-1);
			write(1, "-", 1);
			res++;
		}
		if (n >= 0 && n <= 9)
		{
			n += 48;
			write(1, &n, 1);
			n -= 48;
			res++;
		}
		if (n > 9)
		{
			res = ft_putnbr(n / 10, res);
			res = ft_putnbr(n % 10, res);
		}
	}
	return(res);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	if (n == 2147483648)
		write(1, "2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= (-1);
			write(1, "-", 1);
		}
		if (n >= 0 && n <= 9)
		{
			n += 48;
			write(1, &n, 1);
			n -= 48;
		}
		if (n > 9)
		{
			ft_putnbr_unsigned(n / 10);
			ft_putnbr_unsigned(n % 10);
		}
	}
	return(1);
}

static int	ft_print_hex(int decimal, char format_specifier)
{
	if (decimal < 16)
	{
		if (decimal <= 9)
		{
			decimal += 48;
			write(1, &decimal, 1);
		}
		else
		{
			if (format_specifier == 'X')
			{
				decimal += 55;
				write(1, &decimal, 1);
			}
			if (format_specifier == 'x')
			{
				decimal += 87;
				write(1, &decimal, 1);
			}
		}
		return (1);
	}
	else
		return (-1);
}

static int	ft_hex(unsigned int number, char format_specifier)
{
	int				res;

	res = 0;
	if (number < 16)
		res += ft_print_hex(number, format_specifier);
	else
	{
		res += ft_hex(number / 16, format_specifier);
		res += ft_hex(number % 16, format_specifier);
	}
	return (res);
}

static int	ft_print_formatted_output(const char format_specifier, va_list ap)
{
	int			character;
	char		*str;
	void		*ptr;
	int			j;
	int			number = 0;
	int			res;

	res = 0;
	if (format_specifier == 'd' || format_specifier == 'i')
	{
		number = va_arg(ap, int);
		res += ft_putnbr(number, 0);
	}
	if (format_specifier == 'u')
	{
		number = va_arg(ap, unsigned int);
		res += ft_putnbr_unsigned(number);
	}
	if (format_specifier == 'c')
	{
		character = va_arg(ap, int);
		res += write(1, &character, 1);
	}
	if (format_specifier == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
		{
			res += write(1, "(null)", 6);
			return (0);
		}
		j = 0;
		while (str[j])
			res += write(1, &str[j++], 1);
	}
	if (format_specifier == 'p')
	{
		ptr = va_arg(ap, void *);
		if (!ptr)
		{
			write(1, "0x0", 3);
			return (0);
		}
		res += write(1, &ptr, 8);
	}
	if (format_specifier == '%')
		res += write(1, "%", 1);
	if (format_specifier == 'X' || format_specifier == 'x')
		{
			number = va_arg(ap, unsigned int);
			res += ft_hex(number, format_specifier);
		}
	return (res);
}

// Data type: va_list. A type used for argument pointer variables
// Macro: void va_start (va_list ap, last-required). This macro initializes the argument pointer variable ap to point to the first of the optional arguments of the current function; last-required must be the last required argument to the function.
// Macro: type va_arg (va_list ap, type). This macro returns the value of the next optional argument, and modifies the value of ap to point to the subsequent argument. The type of the return value is specified in the call.
// Macro: void va_end(va_list ap). This macro ends the use of ap; after it, further va_arg calls with the same ap may not work. In the GNU C Library, va_end doesn't do anything and is only used for reasons of portability.

// Macro: va_copy(va_list dest, va_list src). This macro allows copying of objects of type va_list even if this is not an integral type. 
//        The argument pointer in dest is initialized to point to the same argument as the pointer in src.


int	ft_printf(const char *format, ...)
{
	// if (!format)
	// 	return (0);
	int		i;
	int		res;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
			res += ft_print_formatted_output(format[++i], ap);
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
		}
		i++;
	}
	va_end(ap);
	return(res);
}

// static void	test_string(char *str);
// static void	test_character(int character);
//  static void	test_number(int number);
// static void	test_pointer(void *ptr);

/*
int main()
{
// number tests:
	test_number(10);
	// test_number(-10);
	test_number(0);
	// test_number(-0);
	// test_number(1);
	test_number(100);
	test_number(12832);
	test_number(2147483647);
	test_number(-100);
	test_number(-2147483647);
	// test_number(-2147483648);
	// test_number(0.5);
	// test_number(100.5);

// character tests:
// char character = 'b';
	// test_character(0); // tests char = 0->127


// pointer tests:
// 	char character2 = 'b';
// 	char *str2 = "hello";
// 	int number2 = 10;
// test_pointer(&character2);
// test_pointer(&str2);
// test_pointer(&number2);

	// test_pointer(&number);
	// test_pointer(NULL);

// string tests:
// char *str = "hello";

	// test_string("aaa");
	//
	// printf("aaa%saaa%%aaa%s\n", str, str);
	// ft_printf("aaa%saaa%%aaa%s\n", str, str);
	// printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", "hello");

	// test_string(NULL);
	// test_string("");
	// test_string("0");
	// test_string("a");
	// test_string("\t");

	return 0;
}

static void	test_number(int number)
{
	int	pf_res = 0;
	int	ft_res = 0;

	// testing for %d
	printf("testing '%d' for %%d:\n", number);
	pf_res = printf("pf - %%d: %d\n", number);
	printf("pf_res 1 = %d\n\n", pf_res);
	ft_res = ft_printf("ft - %%d: %d\n", number);
	printf("ft_res 1 = %d\n", ft_res);
	printf("*********************\n");

	// testing for %i
	// pf_res = 0;
	// ft_res = 0;
	// printf("testing '%d' for %%i:\n", number);
	// printf("pf - %%i: %i\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_printf("ft - %%i: %i\n", number);
	// printf("ft_res = %d\n\n", ft_res);

	// testing for %X
	// printf("testing '%d' for %%X:\n", number);
	// pf_res = printf("pf - %%X: %X\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_res = ft_printf("ft - %%X: %X\n", number);
	// printf("ft_res = %d\n", ft_res);
	// printf("*********************\n");

	// testing for %x
	// printf("testing '%d' for %%x:\n", number);
	// pf_res = printf("pf - %%x: %x\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_res = ft_printf("ft - %%x: %x\n", number);
	// printf("ft_res = %d\n", ft_res);
	// printf("*********************\n");

	// // testing for %u
	// pf_res = 0;
	// ft_res = 0;
	// printf("testing '%d' for %%u:\n", number);
	// pf_res = printf("pf - %%u: %u\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_res = ft_printf("ft - %%u: %u\n", number);
	// printf("ft_res = %d\n", ft_res);
	// printf("*********************\n");
}
 */
/* 
static void	test_pointer(void *address)
{
	int	pf_res = 0;
	int	ft_res = 0;
	printf("pf - %%p: %p\n", address);
	printf("pf_res = %d\n\n", pf_res);
	ft_printf("ft - %%p: %p\n\n", address);
	printf("ft_res = %d\n", ft_res);
}

static void	test_string(char *str)
{
	int	pf_res = 0;
	int	ft_res = 0;
	printf("testing '%s':\n", str);
	printf("pf - %%s: %s\n", str);
	printf("pf_res = %d\n\n", pf_res);
	ft_printf("ft - %%s: %s\n\n", str);
	printf("ft_res = %d\n", ft_res);
}

static void	test_character(int character)
{
	int	pf_res = 0;
	int	ft_res = 0;
	while (character < 128)
	{
		ft_res = ft_printf("ft: %cokok\n", character);
		printf("ft_res = %d\n", ft_res);

		pf_res = printf("pf: %cokok\n", character);
		printf("pf_res = %d\n\n", pf_res);
	
		character++;
		pf_res = 0;
		ft_res = 0;
	}
}
*/