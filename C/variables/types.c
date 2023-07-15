#include <stdio.h>
#include <stdbool.h>

int main(){
	char a = 'C'; // single character %c
	char b[]="Bro"; // array of characters %s

	float pi = 3.141592653589793; // 4 bytes (32 bits of precision) 6-7 digits %f
	double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15 - 16 digits %lf
	printf("Here is my float %f\n", pi);
	unsigned char c = 226;
	printf("Here is an unsigned char at 226: %c\n", c);
	
	printf("Here is a char printed using %%c format specifier: %c\n", c);
	printf("Here is a char printed using '\%d' format specifier: %d\n", c);
//	printf("Here is a string: %s\n", b);

	return 0;
}
