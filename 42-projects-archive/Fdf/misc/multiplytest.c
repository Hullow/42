#include <stdio.h>

int main()
{
	int zoom = 5;

	int point[2];

	point[0] = 2;
	point[1] = 9;

	point *= zoom;
	printf("point[0]: %d, point[1]: %d\n", point[0], point[1]);
	return ;
}