// John Carmack's sqrt function

    float Q_rsqrt( float number )
    {
     long i;
     float x2, y;
     const float threehalfs = 1.5F;
    
     x2 = number * 0.5F;
     y  = number;
     i  = * ( long * ) &y;                       // evil floating point bit level hacking
     i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
     y  = * ( float * ) &i;
     y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    
     return y;

    }

#include <stdio.h>
#include <time.h>
#include <math.h>


void	print_time_used(clock_t start, clock_t end)
{
	double cpu_time_used;
	

	cpu_time_used = ((double) (end - start) / CLOCKS_PER_SEC);
	printf("cpu_time_used: %f\n", cpu_time_used);
	
}


int main()
{
	float result;
	clock_t start, end;

	//result = 0;
	
	start = clock();
	result = Q_rsqrt(3.1459493);	
	end = clock();

	print_time_used(start, end);
	printf("(result: %f\n", result);	
	
	start = clock();
	result = sqrt(3.1459493);
	end = clock();

	print_time_used(start, end);
	printf("(result: %f\n", result);	

	return (0);
}
