int	ft(int nb, int power)
{
	int	result;

	result = nb;
	while (power > 0)
	{
		power--;
		result *= nb;
		ft(nb, result);
	}
	return (result);
}

int	main(void)
{
	ft(2, 4);
	return (0);
}