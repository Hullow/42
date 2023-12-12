- 5/12/23: read man printf => should've done this immediately when trying to figure out what the function must do. P.S.: make sure it's the right printf you're reading about;
*man printf* refers to the bash function, whereas *man 3 printf* is the C function we're looking to replicate.

- 7/12/23: [Passing NULL to printf in C](https://www.geeksforgeeks.org/g-fact-44-passing-null-to-printf-in-c/) : "The print expects a ‘\0’ terminated array of characters (or string literal) whereas it receives a null pointer. Passing NULL to printf is undefined behavior."

- 8/12/23: passing the arg to ft_hex as unsigned int helps print the negative values in hex. But I don't know why, Ben gave the solution to Theo who gave it to me.

- 11/12/23:
Issue - Question to Github Copilot chat:
For reasons I don't understand, my ft_printf.c program, which seeks to emulate printf(), prints out a different hexadecimal value depending on the number of variables that are put in. ***If I use 8 variables***, then the `%X` in the sequence that corresponds to **"-995002516"** is initialized at line 191 by the code `hexvalue = va_arg(ap, signed long long);` which gives it the value **"3299964780"**. This value is the 10-digit decimal number to which **"-995002516"** corresponds in signed 2's complement notation. The program then uses my functions ft_hex and ft_print_hex to print the corresponding hex value of **"C4B1776C"**. This is the correct result to print out for the hex, corresponding to the printf() output using the same input.
***If I use 9 variables***, however, my line 191, i.e. the statement `hexvalue = va_arg(ap, signed long long);`, initializes hexvalue as **"7594932076"**, which is **"1C4B1776C"** in hexadecimal notation.
I do not understand why the va_arg macro yields a different return value depending on the number of other variables present in the sequence. And I would like to fix this so there isn't a "1" inserted before **"C4B1776C"**. Can you help me solve this issue by looking at it step by step ?