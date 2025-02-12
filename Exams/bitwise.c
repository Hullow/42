#include <stdio.h>

int main()
{
	// bitwise operator practice
	int a = 101;
	int b = 42;
	printf("the & operator: %d\n", a & b);
	printf("the | operator: %d\n", a | b);
	printf("the ~ operator: %d\n", ~b);
	printf("the ~ operator (unsigned): %u\n", ~b);
	return (0);
}

// 101 decimal == 2^6 + 2^5 + 2^2 + 2^0, 1100101
// 42 decimal == 101010

// 1100101
//  101010

//  100000
// 1101111

// 101010
// 010101 == 1 + 4 + 16 = 21
