#include <stdio.h>
#include <string.h>

int main(){
	char name[25];
	int age;

	printf("Whats your name?");
	//scanf("%s", &name);
	fgets(name, 25, stdin);
	name[strlen(name)-1] = '\0';

	printf("Hello %s, How old are you?", name);
	scanf("%d", &age);
	
	printf("Okay %s, you are %d years old", name, age);
	
	return 0;
}
