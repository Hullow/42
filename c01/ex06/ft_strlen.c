#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(*str != '\0')
	{
	str++;
	i++;
	}
	
	write(1, (&i)+48, 1);
	return (i);
}

int	main(void)
{
	ft_strlen("abcde");
	return (0);
}
