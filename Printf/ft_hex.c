// Converting decimal to hexadecimal


hex: 0-9, A-F 

decimal: 0-9

if < 16, use ascii table correspondance

if 
0-16*16^3 –– 0-16*16^2 –– 0-16*16^1 ––– 0-16*16^0

										
Decimal : modulo 16

dec 		hex
1000 	=	1000/16 == 60 (960) + 2 (32) + 8 = 62

1000 / 16 = 62
hex_base = 1;

62 / 16 = 3;
hex_base = 2;

//next step:
1000 / 16**hex_base == 1000 /256 == 3; 
	+> print 3
1000 = 1000 - 256*3 == 1000 - 768 == 232;
hex_base--;

232 / 16**hex == 232/16 ==

//recap:
int number = input;

while (number > 15)
	{
		number /= 16;
		hex_base++;
	}

rest = input % 16;

imagine 