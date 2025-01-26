#define TIMESEQUAL *=
#define PX printf("x: %d\n", x);
#define TE TIMESEQUAL
#include <stdio.h>

int main(void)
{
	int x = 1;

	x TE 2;
;
	PX
}