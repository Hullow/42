#include "Libft.h"

int	main(int argc, char **argv)
{
/* 	if (argc > 1)
		printf("your string '%s' is %zu characters long.\n", argv[1], ft_strlen(argv[1]));
	 */

	if (argc > 2)
		printf("the output for function '%s' from input '%s' is '%s'.\n"
		, argv[1], argv[1](argv[2]));
	
	return(0);
}