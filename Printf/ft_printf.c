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

static int	ft_print_formatted_output(const char format_specifier, va_list ap)
{
	int			character;
	char		*str;
	void		*ptr;
	int			j;
	int			number;
	int			res;

	res = 0;
	if (format_specifier == 'd' || format_specifier == 'i')
	{
		number = va_arg(ap, int);
		ft_putnbr_fd(number, 1);
	}
	if (format_specifier == 'u')
	{
		number = va_arg(ap, unsigned int);
		ft_putnbr_fd(number, 1);
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
			write(1, "(null)", 6);
			return (0);
		}
		j = 0;
		while (str[j])
			write(1, &str[j++], 1);
	}
	if (format_specifier == 'p')
	{
		ptr = va_arg(ap, void *);
		if (!ptr)
		{
			write(1, "0x0", 3);
			return (0);
		}
		write(1, &ptr, 8);
	}
	if (format_specifier == '%')
		write(1, "%", 1);
	return (res);
}

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
static void	test_number(int number);
// static void	test_pointer(void *ptr);

int main()
{
	int number = 10;
	int numb = -10;
	printf("tests of number (10):\n");
	test_number(number);
	printf("**************\ntests of numb (-10):\n");
	test_number(numb);

	// test_character(0); // tests char = 0->127

	// test_string(NULL);
	// test_string("");
	// test_string("0");
	// test_string("a");
	// test_string("\t");
	
	// test_pointer(&number);
	// test_pointer(NULL);

	return 0;
}

static void	test_number(int number)
{
	int	pf_res = 0;
	int	ft_res = 0;

	// testing for %d
	// printf("testing '%d' for %%d:\n", number);
	// printf("pf - %%d: %d\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_printf("ft - %%d: %d\n", number);
	// printf("ft_res = %d\n\n", ft_res);

	// testing for %i
	// pf_res = 0;
	// ft_res = 0;
	// printf("testing '%d' for %%i:\n", number);
	// printf("pf - %%i: %i\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_printf("ft - %%i: %i\n", number);
	// printf("ft_res = %d\n\n", ft_res);

	// testing for %x
	pf_res = 0;
	ft_res = 0;
	printf("testing '%d' for %%x:\n", number);
	printf("pf - %%x: %x\n", number);
	printf("pf_res = %d\n\n", pf_res);
	// ft_printf("ft - %%x: %x\n", number);
	// printf("ft_res = %d\n\n", ft_res);

	// // testing for %u
	// pf_res = 0;
	// ft_res = 0;
	// printf("testing '%d' for %%u:\n", number);
	// printf("pf - %%u: %u\n", number);
	// printf("pf_res = %d\n\n", pf_res);
	// ft_printf("ft - %%u: %u\n", number);
	// printf("ft_res = %d\n\n", ft_res);

}

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
/* int	main()
{
// character tests:
// char character = 'b';


// pointer tests:
// 	char character2 = 'b';
// 	char *str2 = "hello";
// 	int number2 = 10;
// test_pointer(&character2);
// test_pointer(&str2);
// test_pointer(&number2);


// string tests:
// char *str = "hello";

	// test_string("aaa");
	//
	// printf("aaa%saaa%%aaa%s\n", str, str);
	// ft_printf("aaa%saaa%%aaa%s\n", str, str);
	// printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", "hello");

// number tests:
int number = 10;
// int number2 = -10;
	// printf("pf: %i\n", number);
	// ft_printf("ft: %i\n", number);

	// test_number(0);
	// test_number(-0);
	// test_number(1);
	// test_number(10);
	// test_number(-10);

	ft_printf("ft - %%u: %u\n", number);
	printf("pf - %%u: %u\n", number);
	// ft_printf("ft - %%u: %u\n", number2);
	// printf("pf - %%u: %u\n", number2);
	// test_number(2147483647);
	// test_number(-2147483647);
	// test_number(-2147483648);
	// test_number(0.5);
	// test_number(100.5);

	return (0);
}
*/