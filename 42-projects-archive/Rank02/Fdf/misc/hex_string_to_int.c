#include <stdio.h>
#include <string.h>
#include <math.h>
int	ft_hex_string_to_int(char *hex_string)
{
	int	i;
	int	decimal_value;
	int	hex_factor;

	i = 0;
	decimal_value = 0;
	hex_factor = 1;
	while (hex_string[i + 1])
	{
		printf("c%d: %c\n", i, hex_string[i]);	
		i++;
	}
	while (hex_string[i] != 'x' && hex_string[i] != 'X')
	{
		if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
			decimal_value += (hex_string[i] - 55) * hex_factor;
		else if (hex_string[i] >= 'a' && hex_string[i] <= 'f')
			decimal_value += (hex_string[i] - 87) * hex_factor;
		else
			decimal_value += (hex_string[i] - 48) * hex_factor;
		printf("decimal_value now: %d\n", decimal_value);
		hex_factor *= 16;
		i--;
	}
	return (decimal_value);
}

int main()
{
	printf("%d\n", ft_hex_string_to_int("0xff00"));
	return (0);
}