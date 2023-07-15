#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
	
	int age;
	printf("Enter your age\n");
	scanf("%d", &age);

	if (age >= 18){
		printf("You are now signed up!");
	}
	else {
		printf("Your age is %d, under 18, you are too young to sign up", age);
	}
	return 0;
}
