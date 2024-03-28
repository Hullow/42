#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
			printf("%s seems to exist\n", argv[1]);
	}
	else
		printf("missing arguments\n");
 	return (0);
}