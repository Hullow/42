#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
// #include "Libft.h"

// va_list	args;

// va_start	( args, format);

// va_arg( args, char *)

// va_arg( args, int)
// va_end(args); // frees the allocated memory



// what happens in our function ? 
// it takes a string pointer const char: the format
// if the string is empty, it writes the va characters as in putstr


// Requirements:
// Don’t implement the buffer management of the original printf().
// •Your function has to handle the following conversions: cspdiuxX%
//
// diuxX : The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation.  The letters
//  		``abcdef'' are used for x conversions; the letters ``ABCDEF'' are used for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value
//  		requires fewer digits, it is padded on the left with zeros.
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


// •Your function will be compared against the original printf().
// •You must use the command ar to create your library.
// Using the libtool command is forbidden.
// •Your libftprintf.a has to be created at the root of your repository.

void	ft_print_formatted_output(const char *format, int i, va_list ap)
{
	int			character;
	char		*str;
	void		*ptr;
	int			j;

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

	ap = malloc(sizeof(va_list));
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		i = ft_print_characters(format, i);
		// printf("\tbefore ft_format_specification, i is %d\n", i);
		if (format[i] == '%')
			ft_print_formatted_output(format, i++, ap);
		i++;
	}
	va_end(ap);
	free(ap);
	return(0);
}

/* int	test(char *format, ...)
{
	va_list	testargs;

	va_start(testargs);
	printf(str);
} */

int	main()
{
	char character = 'b';
	char *str = "hello";
	// printf("aaa%c\n", character);
	// ft_printf("aaa%c\n", "hello");
	// ft_printf("aaa%c\n", character);
	printf("aaa%saaa%%aaa%s\n", str, str);
	ft_printf("aaa%saaa%%aaa%s\n", str, str);
	// test("hello");
	// printf("\tbro");
	return (0);
}