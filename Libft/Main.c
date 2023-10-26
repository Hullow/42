#include "Libft.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("your string '%s' is %zu characters long.\n", argv[1], ft_strlen(argv[1]));
	
	return(0);
}