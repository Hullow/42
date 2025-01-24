// I am working through the exercises in the book "Learn C the hard way". Exercise 7 asks the reader to find the value which makes the range of an unsigned long exceed.

// Change long to unsigned long and try to find the number that makes it too big.

// So my approach is to first get the size of an unsigned long on my machine:

// printf("SIZEOF ULONG: %lu", sizeof(unsigned long));
// This prints 8 as a result. So assuming that an unsigned long will take up 64 bits on my machine I looked up the maximum range on Wikipedia.

// 64-Bits (word, doubleword, longword, long long, quad, quadword, qword, int64)

// Unsigned: From 0 to 18,446,744,073,709,551,615
// I was expecting that declaring an unsigned long with the above value would compile without warnings until I increment the value by 1. The result is different though. compiling the following program results in a warning.

#include <stdio.h>
int main()
{
    unsigned long value = 18446744073709551615UL;
    printf("SIZEOF ULONG: %lu", sizeof(unsigned long));
    printf("VALUE: %lu", value);
    return 0;
}