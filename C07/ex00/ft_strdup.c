#include <string.h>
#include <stdio.h>

int main()
{
	char *result = strdup("just a string:");
	printf("Here is the result: %s\n", result);
	return (0);
}