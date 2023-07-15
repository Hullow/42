#include <stdio.h>

void birthday(char x[], int y) {
	printf("\nHappy Birthday dear %s!", x);
	printf("\nYou are %d years old!", y);
	
}

int main() {
	char name[] = "Bro";
	int age = 25;
	birthday(name, age);
//	birthday(age, name);
//	birthday();

	return 0;
}
