#include <stdarg.h>
#include <stdio.h>
// #include "Libft.h"

// va_list	args;

// va_start	( args, format);

// va_arg( args, char *)

// va_arg( args, int)

// va_end(args); //frees the allocated memory


// what happens in our function ? 
// it takes a string pointer const char: the format
// if the string is empty, it writes the va characters as in putstr

// Requirements:
// Don’t implement the buffer management of the original printf().
// •Your function has to handle the following conversions: cspdiuxX%
// •Your function will be compared against the original printf().
// •You must use the command ar to create your library.
// Using the libtool command is forbidden.
// •Your libftprintf.a has to be created at the root of your repository.
// 5

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}


int	ft_printf(const char *format, ...)
{
	// int		res;
	size_t		size;
	va_list		ap;

	va_start(ap, format);
	// res = 0;
	char	*str = va_arg(ap, char *);
	size = ft_strlen(str);

	va_end(ap);
	// return(res);e
	return(size);
}

int	main()
{
	printf("%d\n", (int) ft_printf("%s", "hello"));
	return (0);
}