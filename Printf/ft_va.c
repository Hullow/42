#include <stdarg.h>
#include <stdio.h>

// va_list	args;

// va_start	( args, format);

// va_arg( args, char *)

// va_arg( args, int)

// va_end(args); //frees the allocated memory


/* 
First example:
size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}


size_t	ft_printsize(const char *format, ...)
{
	va_list	ap;
	size_t	size;

	va_start(ap, format);

	char	*str = va_arg(ap, char *);
	size = ft_strlen(str);
	va_end(ap);
	return(size);
}
*/

/* 
Second example:
float	average(int n, ...)
{
	va_list	ap; // points to the first argument n
	int	total;
	int	i;

	va_start(ap, n);
	total = 0;
	i = 0;

	while(i < n)
	{
		total += va_arg(ap, int);
		i++;
	}
	return ((float)total/n);
}

void	test_average(int n, ...)
{
	int	average_age;
	average_age = average(n, 10, 4, 7);
	printf("the average age of those five people is %d\n", average_age);
}
*/


void	ft_va_position(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	// printf("va_start sets ap to point to address %p with the corresponding string: %s\n", ap, ap);
	char *ret =	va_arg(ap, char *);
	printf("va_start sets ap to point to address %p and returns string: %s which is at address %p\n", ap, ret, ret);
	// va_arg(ap, char *);
	va_end(ap);

}


int	main()
{
	ft_va_position("%d", "hello");
	// printf("%d\n", (int) ft_printsize("%s", "hello"));
	return (0);
}
