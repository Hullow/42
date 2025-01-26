#include "fdf.h"

// hex_factor: length of string minus "0x"
// if hex_string[i] >= 'A' (65), - 55 to get decimal value from character
// else - 48
int	ft_hex_string_to_int(char *hex_string)
{
	int	i;
	int	decimal_value;
	int	hex_factor;

	decimal_value = 0;
	i = 2;
	while (hex_string[i] == '0')
			i++;
	hex_factor = pow(16, ft_strlen(hex_string + i) - 1);
	while (hex_string[i])
	{
		if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
			decimal_value += (hex_string[i] - 'A' + 10) * hex_factor;
		else if (hex_string[i] >= 'a' && hex_string[i] < 'z')
			decimal_value += (hex_string[i] - 'a' + 10) * hex_factor;
		else
			decimal_value += (hex_string[i] - 48) * hex_factor;
		hex_factor /= 16;
		i++;
	}
	ft_printf("decimal value: %d\n", decimal_value);
	return (decimal_value);
}


int main()
{
	char	*hex1 = "0x0000000";
	char	*hex2 = "0xFFFFFF";
	char	*hex3 = "0xABCDEF";
	char	*hex4 = "0x00FF0000";
	char	*hex5 = "A1B2C3";
	ft_hex_string_to_int(hex1);
	ft_hex_string_to_int(hex2);
	ft_hex_string_to_int(hex3);
	ft_hex_string_to_int(hex4);
	ft_hex_string_to_int(hex5);

	return (0);
}