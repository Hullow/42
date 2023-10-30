#include <stdio.h>

int main()
{

	int i = 0;

	printf("This is the while for (i++ < 10):\n");

	while (i++ < 10)
		printf("i is %d\n", i);

	i = 0;

	printf("\nThis is the while for (++i < 10):\n");
	
	while (++i < 10)
		printf("i is %d\n", i);

	return (0);
}