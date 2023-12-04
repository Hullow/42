#include <stdarg.h>
#include <stdio.h>
// #include "Libft.h"

// va_list	args;

// va_start	( args, format);

// va_arg( args, char *)

// va_arg( args, int)

// va_end(args); //frees the allocated memory


// what happens in our function ? we use a function ft_printf with a string const char *

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}


int	ft_printf(const char *str, ...)
{
	// int		res;
	size_t		size;
	va_list	ap;

	// res = 0;
	size = ft_strlen(*ap);

	// return(res);
	return(size);
}


int	main()
{
	printf("the size of our initial argument is %d\n", (int) ft_printf("hello"));
	return (0);
}