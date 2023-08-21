#include <stdio.h>
#include <stdlib.h>

int     count_digits(int nbr) // Take number, divide until 0, counting digits
{
        int     digits;

	digits = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		digits = 1;
        while (nbr != 0)
        {
        nbr /= 10;
	digits++;
        }
        return (digits);
}

char    *itoa(int nbr)
{
	int	digits;  // to store the number of digits

	digits = count_digits(nbr);	
        char *array = malloc((digits + 1)* sizeof(char)); // Allocate memory space for the counted digits + 1 for \0
               if (array == NULL)
                        return (NULL);
	if (nbr < 0)
                array[0] = '-';
	array[digits--] = '\0'; // null-terminates the string 
        while (digits >= 0 && array[digits] != '-')
        {
		if (nbr < 0) // if negative, change the sign of the digit
			array[digits--] = -(nbr % 10) + '0'; // allocates the rightmost digit to the array from right to left
		else	array[digits--] = (nbr % 10) + '0';
                nbr /= 10;         // removes the last digit
        }
        return (array);
}


int	main(void)
{
	printf("Int min: %s\n", itoa(-2147483648));
	printf("Int max: %s\n", itoa(2147483647));
	printf("Zero: %s\n", itoa(0));
	printf("Random positive number: %s\n", itoa(1829817));
	printf("Random positive number: %s\n", itoa(928937));
	printf("Random negative number: %s\n", itoa(-918237));
	printf("Random negative number: %s\n", itoa(-123453));
}


/*
int     main(int ac, char **av)
{
        if (ac == 2)
        {
               printf("input is %d\n", atoi(av[1]));
               printf("String output is %s\n", itoa(atoi(av[1])));
        }
free(itoa(atoi(av[1])));

return (0);
} */
