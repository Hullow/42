#include <unistd.h>
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	if (argc > 1)
	{
		while (argv[i] != 0)
			i++;
		i -= 1;
		while (i != 0)
		{
		j = 0;
			while (argv[i][j] != 0)
				j++;
			write(1, argv[i], j);
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}