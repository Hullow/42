#include <unistd.h>
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	
	if (argc > 0)
	{
		while (argv[0][i] != 0)
			i++;
	write(1, argv[0], i);
	write(1, "\n", 1);
	}
	return (0);
}

/* Test:
	write(1, argv[0], i); works because argv[0] is a pointer. So it prints i characters of that pointer. 
	write(1, &argv[0][i], 1); //argv[][] is a value, need & to reference
	write(1, " ", 1);
*/
