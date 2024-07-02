#include <stdio.h>

void	ft_binary(unsigned int number)
{
	// printf("number: %d\n", number);
	if (number == 0)
	{
		printf("0");
		// kill(server_PID, SIGUSR1);
	}
	else if (number == 1)
	{
		printf("1");
		// kill(server_PID, SIGUSR2);
	}
	else
	{
		ft_binary(number / 2);
		ft_binary(number % 2);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = -1;
		while (argv[1][++i])
			ft_binary((int) argv[1][i]);
	}
	return (0);
}