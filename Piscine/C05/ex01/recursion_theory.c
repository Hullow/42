outer loop:
	nb = 4

int	ft(4)
{
	if (4 == 0)
		return (1);
	int	factorial = 4;
	while (4 > 1)
	{
		nb--; first outer loop : 3;
		factorial *= nb; = 12
		ft(nb); => first inner loop: ft(3)
	}
	return(factorial);
}

first inner loop: ft(3)
int	ft(3)
{
	if (nb == 0)
		return (1);
	int	factorial = 3;
	while (3 > 1)
	{
		nb--; first inner loop: 2; first inner loop(2): 1
		factorial *= nb; first inner loop : 6; first inner loop(2): 6
		ft(nb); => ft(2) => second inner loop: ft(2) => returns 2; since nb == 2, we go through while again => first inner loop(2)(see above), ft(1) => returns 1; while: nb !<1, we exit while loop of first inner(2)
	}
	return(factorial); first inner loop(2)=> return 6 => back to first inner loop
}

second inner loop: ft(2)
int	ft(2)
{
	if (nb == 0)
		return (1);
	int	factorial = 2;
	while (nb > 1)
	{
		nb--; second inner loop: 1;
		factorial *= nb; = 2
		ft(nb); ft(1) => third inner loop: ft(1) => returned 1; since nb now == 1, we exit the while, and return 2
	}
	return(factorial);
}

third inner loop: ft(1)
int	ft(1)
{
	if (nb == 0)
		return (1);
	int	factorial = nb; = 1
	while (nb > 1) 1 !> 1 => we skip the while
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial); => return(1) to second inner loop;
}

int	ft(int nb)
{
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}

int	ft(int nb)
{
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}

int	ft(int nb)
{
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}

int	ft(int nb)
{
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}

int	ft(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}

int	ft(int nb)
{
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}

int	ft(int nb)
{
	if (nb == 0)
		return (1);
	int	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
		ft(nb);
	}
	return(factorial);
}