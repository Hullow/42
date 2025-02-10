#include "function-pointers.h"

typedef struct s_operation
{
	int	(*add_ptr) (int, int);
	int	(*multiply_ptr) (int, int);
}	t_operation;

typedef union function_pointers
{
	int (*func_ptr) (int, int);
	float (*divide_ptr) (int, int);
}	t_func_ptr;



int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 3)
		return (0);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	t_operation	op;
	// int	(*add_ptr) (int, int);
	// add_ptr = add;
	op.add_ptr = add;
	op.multiply_ptr = multiply;
	t_func_ptr un;
	un.divide_ptr = divide;
	printf("adding: %d - multiplying: %d - dividing: %f\n", op.add_ptr(a, b), op.multiply_ptr(a, b), un.divide_ptr(a, b));
	return(0);
}

int	add(int a, int b)
{
	return (a + b);
}

int	multiply(int a, int b)
{
	return (a * b);
}

float	divide(int a, int b)
{
	float	c;

	c = a / b;
	printf("divide - c: %f\n", c);
	return (c);
}