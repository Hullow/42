#include <stdio.h>

double square(int x) {
    double result = x * x;
    return result;
}

int main() {

    int number;
    printf("Input a number: ");
    scanf("%d", &number);

    double a;
    a = square(number);
    printf("The square of that number is %lf\n", a);

    return 0;
}

//	double y = square(3.14);

//	printf("a bell (alert): \?");
//	char *amessage;
//	amessage = "This is a string.";
//	printf("%s", amessage);
