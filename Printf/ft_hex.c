/* // Converting decimal to hexadecimal
hex: 0-9, A-F 

decimal: 0-9

if < 16, use ascii table correspondance

if 
0-16*16^3 –– 0-16*16^2 –– 0-16*16^1 ––– 0-16*16^0
										
Decimal : modulo 16

dec 		hex
1000 	=	1000/16 == 60 (960) + 2 (32) + 8 = 62

// count hex_base
while()
1000 / 16 = 62
hex_base = 1;

62 / 16 = 3;
hex_base = 2;

// print out the hex, base by base
while()
1000 / 16**hex_base == 1000 /256 == 3; 
	=> print 3
1000 = 1000 % 16**hex_base == 232;
hex_base--; hex_base == 1

232 / 16**hex_base == 232/16*1 == 14
	=> print E
232 % 16**hex_base == 8;
hex_base--; hex_base == 0;

//print out the modulo
	=> print 8 */

static void	ft_print_hex(int decimal)
{
	if (decimal < 16)
	{
		if (decimal <= 9)
			write(1, &decimal, 1);
		else if (decimal == 10)
			write(1, "A", 1);
		else if (decimal == 11)
			write(1, "B", 1);
		else if (decimal == 12)
			write(1, "C", 1);
		else if (decimal == 13)
			write(1, "D", 1);
		else if (decimal == 14)
			write(1, "E", 1);
		else if (decimal == 15)
			write(1, "F", 1);
		return (0);
	}
	else
		return (-1);
}

static int	ft_hex(int input)
{
	int number;

	number = input;
	while (number > 15)
		{
			number /= 16;
			hex_base++;
		}
	number = input;
	while (hex_base > 0)
	{
		if (ft_print_hex(number /= 16**hex_base) == -1)
			write(1, "ft_print_hex error", 20);
		number %= 16**hex_base;
		hex_base--;
	}
	if (ft_print_hex(number) == -1);
		write(1, "ft_print_hex error", 20);
}