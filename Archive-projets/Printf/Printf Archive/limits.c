#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("printf:\nTEST 24: %lx \n", LONG_MAX);
	ft_printf("ft_printf:\nTEST 24: %x \n\n", LONG_MAX);

	// printf("printf:\nTEST 27 (decimal): %lu \n", ULONG_MAX); // nb: == 18446744073709551615
	// printf("printf:\nTEST 27 (hex): %lx \n", ULONG_MAX);
	// ft_printf("ft_printf:\nTEST 27: %x \n\n", ULONG_MAX);

	// printf("printf:\nTEST 27 (decimal) - 1: %lu \n", ULONG_MAX - 1);
	// printf("printf:\nTEST 27 (hex) - 1: %lx \n", ULONG_MAX -1);
	// ft_printf("ft_printf:\nTEST 27 - 1: %x \n\n", ULONG_MAX -1);

	printf("printf:\nTEST 27 (decimal) - 1: %llu \n", 18446744073709551614);
	printf("printf:\nTEST 27 (hex) - 1: %llx \n", 18446744073709551614);
	ft_printf("ft_printf:\nTEST 27 - 1: %x \n\n", 18446744073709551614);

	printf("printf:\nTEST 28: %llx \n", 9223372036854775807LL);
	ft_printf("ft_printf:\nTEST 28: %x \n\n", 9223372036854775807LL);

	printf("printf:\nTEST 29: %x %x %lx %lx %lx %x %x \n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("ft_printf:\nTEST 29: %x %x %x %x %x %x %x \n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

return(0);
}