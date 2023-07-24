#include <stdio.h>
#include <stdbool.h>

int main(){
	float item1 = 5.75;
	float item2 = 10.00;
	float item3 = 100.99;
	
	printf("Item 1: $%8.2f", item1);
	printf("Item 2: $-4%.2f", item2);
	printf("Item 3: $2%.1f", item3);

}
