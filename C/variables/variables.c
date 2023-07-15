#include <stdio.h>

int main(){
	int x; //declaration of a var to create space in memory
	x = 123; //initialization
	
	float gpa;
	gpa = 2.05;
	
	char grade; //single character
	grade = 'C';
    
	int age;
	age = 21;
	age += x;

	char str[2];
//	char str = "Mec";
	
	printf("Enter your name: "); //request input from user
	scanf("%s",str);	
	printf("Your name is %s",str); //display output on screen
	printf("Your GPA is %f\n\n", gpa);

//	printf("Hello %s", name);
//	printf("You are %d years old\t", age);
	
	return 0;
}
