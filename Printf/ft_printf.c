#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
// #include "Libft.h"



// Requirements:
// Don’t implement the buffer management of the original printf().
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

void	ft_print_formatted_output(const char *format, int i, va_list ap)
{
	int			character;
	char		*str;
	void		*ptr;
	int			j;
	int			number;

	if (format[i+1] == 'd' || format[i+1] == 'i')
	{
		number = va_arg(ap, int);
		ft_putnbr_fd(number, 1);
	}
	if (format[i+1] == 'u')
	{
		number = (unsigned int)va_arg(ap, int);
		write(1, &number, 1);
	}
	if (format[i+1] == 'c')
	{
		character = va_arg(ap, int);
		write(1, &character, 1);
	}
	if (format[i+1] == 's')
	{
		str = va_arg(ap, char *);
		j = 0;
		while (str[j])
			write(1, &str[j++], 1);
	}
	if (format[i+1] == 'p')
	{
		ptr = va_arg(ap, void *);
		write(1, &ptr, 1);
	}
	if (format[i+1] == '%')
		write(1, "%", 1);

}

int	ft_print_characters(const char *format, int i)
{
	while (format[i] != '%' && format[i])
	{
		write(1, &format[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	// ap = malloc(sizeof(va_list));
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		i = ft_print_characters(format, i); // prints characters before the first % and returns i to the array index of % (if present)
		// printf("\tbefore ft_format_specification, i is %d\n", i);
		if (format[i] == '%')
			ft_print_formatted_output(format, i++, ap);
		i++;
	}
	// free(ap);
	va_end(ap);
	return(0);
}


/* void	test_string(char *str)
{
	printf("testing '%s':\n", str);
	printf("pf - %%s: %s\n", str);
	ft_printf("ft - %%s: %s\n", str);
} */

/* void	test_number(int number)
{
	printf("testing '%d':\n", number);
	printf("pf - %%d: %d\n", number);
	ft_printf("ft - %%d: %d\n", number);
	// printf("pf - %%i: %i\n", number);
	// ft_printf("ft - %%i: %i\n", number);
	// printf("pf - %%u: %u\n", number);
	// ft_printf("ft - %%u: %u\n", number);
	// printf("pf - %%o: %o\n", number);
	// ft_printf("ft - %%o: %o\n", number);
	// printf("pf - %%x: %x\n", number);
	// ft_printf("ft - %%x: %x\n", number);
	// printf("pf - %%X: %X\n\n", number);
	// ft_printf("ft - %%X: %X\n\n", number);
} */

int	main()
{
	// string tests:
	//
	// test_string("aaa");
	//
	// char character = 'b';
	// char *str = "hello";
	// printf("aaa%saaa%%aaa%s\n", str, str);
	// ft_printf("aaa%saaa%%aaa%s\n", str, str);
	// printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", "hello");

	// number tests:
	//
	int number = 10;
	write(1, &number, 8);
	// ft_printf("ft: %i\n", number);
	//
	// test_number(0);
	// test_number(-0);
	// test_number(1);
	// test_number(10);
	// test_number(-10);
	// test_number(2147483647);
	// test_number(-2147483647);
	// test_number(-2147483648);
	// test_number(0.5);
	// test_number(100.5);

	return (0);
}



