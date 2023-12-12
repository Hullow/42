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

