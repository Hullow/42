#include <stdio.h>


int main(int argc, char **argv)
{
	int i = -1;
	if (argc == 2)
	{
		while (argv[1][++i])
			printf("argv[1][%d]: %c\n", i, (int) argv[1][i]);
		// printf("argv[1][%d]: %c\n", i, (int) argv[1][i]);
	}	
	return 0;
}