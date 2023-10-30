#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = {'w', 'x', 'y', '\0'};
	printf("strlen of string is %lu\n", strlen(str));

	size_t i = 0;
	while (str[i])
	{
		printf("str[%lu]: %c\n", i, str[i]);
		i++;
	}
	printf("str[%lu]: %c\n", i, str[i]);
	return (0);
}