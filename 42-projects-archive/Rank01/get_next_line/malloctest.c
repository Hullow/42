#include <stdio.h>
#include <stdlib.h>

int	allocate_memory()
{
	void	*ptr;

	ptr = malloc (15);
	if (!ptr)
		return (-1);
	
	else
	{
		char *temp = ptr - 10;
		temp += 10;
		free(temp);
		return (1);
	}
}

int main()
{
	int ret;

	ret = allocate_memory();
	if (ret == -1)
		printf("malloc error\n");
	else if (ret == 1)
		printf("malloc success\n");
	else
		printf("other error\n");

	return (0);
}