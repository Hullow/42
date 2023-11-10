#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *string = {"0123"};

	char *array = (char *)malloc(5 * sizeof(char));
	printf("before copy, array is '%s'\n", array);

	strcpy(array, string);
	printf("after copy, array is '%s'\n", array);
	
	free(array);
	printf("after free, array is '%s'\n", array);
	return (0);
}