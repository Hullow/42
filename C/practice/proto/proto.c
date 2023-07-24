#include <stdio.h>

void hello(char[], int); //function prototype, ensuring that calls to a function are made with the correct arguments

int main() {
	char name[] = "Bryan";
	int age = 21;

	hello(name, age);
	return 0;
}

void hello(char name[], int age) {
	printf("\nHello %s", name);
	printf("You are %d years old", age);
}


