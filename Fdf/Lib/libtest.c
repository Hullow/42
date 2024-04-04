#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_isalpha((int)argv[1]))
			ft_printf("%c (int: %d) is alphanumerical\n", argv[1], argv[1]);
		else
			ft_printf("%c (int: %d) is not alphanumerical\n", argv[1], argv[1]);
	}
	return (0);
}