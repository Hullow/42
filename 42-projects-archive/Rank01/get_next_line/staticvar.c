#include <stdio.h>

void	function_two(int read_ret)
{
	read_ret = read_ret + 1;
	return;
}

int	function_one(void)
{
	static int	read_ret = 1;
	printf("read_ret before function two is: %d\n", read_ret);
	function_two(read_ret);
	printf("read_ret after function two is: %d\n", read_ret);
	function_two(read_ret);
	printf("read_ret after function two is: %d\n", read_ret);
	function_two(read_ret);
	return (read_ret);
}



int main()
{
	function_one();
}