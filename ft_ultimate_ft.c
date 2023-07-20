#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int	i;
	int	*j;
	int	**k;
	int	***l;
	int	****m;
	int	*****n;
	int	******o;
	int	*******p;
	int	********q;
	int	*********nbr;

	i = 49;
	j = &i;
	k = &j;
	l = &k;
	m = &l;
	n = &m;
	o = &n;
	p = &o;
	q = &p;

	nbr = &q;
	ft_ultimate_ft(nbr);
	i += 48;
	write(1, &i, 1);

	int t = 88;
	write(1, &t, 1);
	return (0);
}
