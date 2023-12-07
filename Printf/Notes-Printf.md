- 5/12/23: read man printf => should've done this immediately when trying to figure out what the function must do. P.S.: make sure it's the right printf you're reading about;
*man printf* refers to the bash function, whereas *man 3 printf* is the C function we're looking to replicate.

- 7/12/23: [Passing NULL to printf in C](https://www.geeksforgeeks.org/g-fact-44-passing-null-to-printf-in-c/) : "The print expects a ‘\0’ terminated array of characters (or string literal) whereas it receives a null pointer. Passing NULL to printf is undefined behavior."