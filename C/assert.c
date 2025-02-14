#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("please input one argument\n");
		return (0);
	}
	assert(atoi(argv[1]) > 0);
	printf("assert passed!\n");
	return (0);
}