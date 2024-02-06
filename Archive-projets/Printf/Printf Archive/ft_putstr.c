#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
	write(1, str, 1);
	str++;
	}
}

int	main(void)
{
	char	string[6];
	char *str;

	string[0] = 'h';
	string[1] = 'e';
	string[2] = 'l';
	string[3] = 'l';
	string[4] = 'o';
	string[5] = '\0';
//	str = NULL;
	str = string;
	ft_putstr(str);
}
