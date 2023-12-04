#include <stdarg.h>
#include <stdio.h>

// va_list	args;

// va_start	( args, format);

// va_arg( args, char *)

// va_arg( args, int)

// va_end(args); //frees the allocated memory


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



int	main()
{

	int	average_age;

	average_age = average(3, 18, 45, 32);
	printf("the average age of those five people is %d\n", average_age);
}
