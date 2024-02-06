#include <unistd.h>

static void ft_print_hex(int decimal)
{
	if (decimal < 16)
	{
		if (decimal <= 9)
		{
			decimal += 48;
			write(1, &decimal, 1);
		}
		else if (decimal == 10)
			write(1, "A", 1);
		else if (decimal == 11)
			write(1, "B", 1);
		else if (decimal == 12)
			write(1, "C", 1);
		else if (decimal == 13)
			write(1, "D", 1);
		else if (decimal == 14)
			write(1, "E", 1);
		else if (decimal == 15)
			write(1, "F", 1);
	}
}

int main()
{
	ft_print_hex(1);
	return 0;
}