#include <stdio.h>

void test(int number)
{
	printf("testing '%d':\n", number);
	printf("%%d: %d\n", number);
	printf("%%i: %i\n", number);
	printf("%%u: %u\n", number);
	printf("%%o: %o\n", number);
	printf("%%x: %x\n", number);
	printf("%%X: %X\n\n", number);
}


int main()
{
	test(0);
	test(-0);
	test(1);
	test(10);
	test(-10);
	// test(0.5);
	// test(100.5);
	test(2147483647);
	test(-2147483647);
	test(-2147483648);
	return 0;
}