#include <unistd.h>
#include <stdio.h>

void	putnbr(int	nb)
{
	if (nb <= 9 && nb >= 0)
		nb += 48;
		write(1, &nb, 1);

	if (nb > 9)
		putnbr(nb / 10);
		putnbr(nb % 10);
}

int main(int argc, char **argv)
{
    if (argc > 0)
		putnbr(argv[1]);
    return (0);
}
