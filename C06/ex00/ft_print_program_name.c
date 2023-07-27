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
	}
	return (0);
}
