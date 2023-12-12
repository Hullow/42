Requirements:
// •Your function has to handle the following conversions: cspdiuxX%
//
// c: The int argument is converted to an unsigned char, and the resulting character is written.
//
// s: The char * argument is expected to be a pointer to an array of character type (pointer to a string).
//		Characters from the array are written up to (but not including) a terminating NUL character;
//		if a precision is specified, no more than the number specified are written.  If a precision is given, 
//		no null character need be present; if the precision is not specified, or is greater
//	    than the size of the array, the array must contain a terminating NUL character.
//
// p: The void * pointer argument is printed in hexadecimal (as if by `%#x' or `%#lx').
//
// %: A `%' is written.  No argument is converted.  The complete conversion specification is `%%'.
//
// diuxX : The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation.  The letters
//  		``abcdef'' are used for x conversions; the letters ``ABCDEF'' are used for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if the converted value
//  		requires fewer digits, it is padded on the left with zeros.


- 5/12/23: read man printf => should've done this immediately when trying to figure out what the function must do. P.S.: make sure it's the right printf you're reading about;
*man printf* refers to the bash function, whereas *man 3 printf* is the C function we're looking to replicate.

- 7/12/23: [Passing NULL to printf in C](https://www.geeksforgeeks.org/g-fact-44-passing-null-to-printf-in-c/) : "The print expects a ‘\0’ terminated array of characters (or string literal) whereas it receives a null pointer. Passing NULL to printf is undefined behavior."

- 8/12/23: passing the arg to ft_hex as unsigned int helps print the negative values in hex. But I don't know why, Ben gave the solution to Theo who gave it to me.

- 11/12/23:
Issue - Random sequence francinette test error* - Question to Github Copilot chat:
For reasons I don't understand, my ft_printf.c program, which seeks to emulate printf(), prints out a different hexadecimal value depending on the number of variables that are put in. ***If I use 8 variables***, then the `%X` in the sequence that corresponds to **"-995002516"** is initialized at line 191 by the code `hexvalue = va_arg(ap, signed long long);` which gives it the value **"3299964780"**. This value is the 10-digit decimal number to which **"-995002516"** corresponds in signed 2's complement notation. The program then uses my functions ft_hex and ft_print_hex to print the corresponding hex value of **"C4B1776C"**. This is the correct result to print out for the hex, corresponding to the printf() output using the same input.
***If I use 9 variables***, however, my line 191, i.e. the statement `hexvalue = va_arg(ap, signed long long);`, initializes hexvalue as **"7594932076"**, which is **"1C4B1776C"** in hexadecimal notation.
I do not understand why the va_arg macro yields a different return value depending on the number of other variables present in the sequence. And I would like to fix this so there isn't a "1" inserted before **"C4B1776C"**. Can you help me solve this issue by looking at it step by step ?
==> wasted 3-4 hours trying to understand instead of moving on and fixing other issues. It got fixed on its own fixing my %X and %p issues !

- ft_hex(unsigned long long) (vs ft_hex(signed long long)) solves the %p francinette issues (but not my %x/%X francinette issues) => used separate functions in the end




* Random sequence error testing sample:
// the entire sequence: error (ft prints "1C4B1776C" au lieu de "1C4B1776C" pour "%X,  -995002516")
// pf_res =    printf("printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, -995002516, 1475840544, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420,1314672812, ",I^U?p{@y[!", 1387750149, 14284835, -995002516, 1475840544, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);

// modify the problematic variable (-995517 rather than -995002516): error
// pf_res =    printf("printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, -995517, 1475840544, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420,1314672812, ",I^U?p{@y[!", 1387750149, 14284835, -995517, 1475840544, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);

// modify the problematic variable (-1 rather than -995002516): error
// pf_res =    printf("printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, -1, 1475840544, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420,1314672812, ",I^U?p{@y[!", 1387750149, 14284835, -1, 1475840544, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);

// modify the problematic variable (125 rather than -995002516): error (not just an additional "1" this time, but 1000000)
// pf_res =    printf("printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 125, 1475840544, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 125, 1475840544, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);

// modify the problematic variable and remove one other variable: no error
// pf_res =    printf("printf:\n_{\t=>R4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 125, 1475840544, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R4MadvfeQ%d%s\7KL%X%xa1G7%XO,A$O7a$K%uUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 125, 1475840544, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);

// change the order of format specifiers (our problematic '%X' after '%u'): no error
// pf_res =    printf("printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7,A$O7a$K%uUQC%XOCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 125, 1475840544, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7,A$O7a$K%uUQC%XOCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 125, 1475840544, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);

// change the order of format specifiers (our problematic '%X' after '%u') AND their original values ("-995002516, 1475840544" becomes "1475840544, -995002516"): no error
// pf_res =    printf("printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%uO,A$O7a$K%XUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420, 1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 1475840544, -995002516, 1988102481, 45130549);
// printf("\npf_res = %d\n", pf_res);
// ft_res = ft_printf("\nft_printf:\n_{\t=>R%d4MadvfeQ%d%s\7KL%X%xa1G7%uO,A$O7a$K%XUQCCw<g-=E%X-*=M!r\CoC%d)*_RoVrbgZ", 68420,1314672812, ",I^U?p{@y[!", 1387750149, 14284835, 1475840544, -995002516, 1988102481, 45130549);
// ft_printf("\nft_res = %d\n", ft_res);