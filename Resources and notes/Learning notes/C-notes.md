# Notes on C

## General concepts
### [Undefined behavior](https://www.geeksforgeeks.org/undefined-behavior-c-cpp/)
- When the result of an executing program is unpredictable, i.e. failing to compile, executing incorrectly, crashing or generating incorrect results, or do fortuitously exactly what the programmer intended, it is said to have undefined behavior

## Syntax
### Escape characters and sequences:
- Escape character for `%` in `printf` or `scanf`: `%%`, e.g.:
- To represent a double quotation mark in a string literal, use the escape sequence \". The single quotation mark (') can be represented without an escape sequence:
```
  char c = 'A';
printf("Here is a char printed using %%c format specifier: %c\n", c);
```

## Memory management
### [Dynamic memory allocation](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- A procedure in which the size of a data structure (like an array) is changed during runtime.

## Variables
- Constant variables: in CAPITALS by convention
### Data types
#### Type-casting
- A typecast explicitly causes an expression to be of a specific data type
- "A value of type `char` is automatically promoted into a value of type `int` when used as a parameter" (*GNU Libc Manual*, p. 98)

### Pointers
#### [Null Pointers](https://www.geeksforgeeks.org/null-pointer-in-c/)
- A null pointer, initialized e.g. as `type pointer_name = 0` or `type pointer_name = NULL`, points only towards `NULL`, or `O` in the memory. It is different from a pointer pointing to an empty memory address, e.g. an empty string `type pointer_name = ""`

#### [Constant Pointers](https://www.javatpoint.com/const-pointer-in-c)
- A pointer that cannot change the address of the variable to which it is pointing, i.e. the address will remain constant. The pointer is thus a read-only variable
 
#### Void Pointers
**Benefits and Applications**
- Memory allocation: used to allocate memory dynamically in conjunction with malloc and calloc without specifying the data type beforehand
- Generic data structures: allows the creation of data structures that can handle various data types, such as linked lists and queues
- Callback functions: have a use in implementing callback mechanisms effectively, to transfer both function pointers and related data.
- Interfacing with external libraries: allow to communicate with external libraries or functions of the system by allowing data to be passed without having to define its precise type.

#### Type-casting a pointer
- Reason: for pointer arithmetic
- Syntax: `(data type *) pointer_name`. Me: reason is because the whole type needs to be precised inside the parenthesis

### Specificities of types
#### [size_t](https://www.geeksforgeeks.org/size_t-data-type-c-language/)
- An unsigned integer type used to represent the size of objects in bytes. 
- Never negative. Depends on the compiler, guaranteed to be the maximum permissible size which the system can handle. If compiler is 32 bit, is a `typedef` (alias) for **unsigned long** (32 bit); if 64 bit, for **unsigned long long**

#### `SIZE_MAX`: the maximum size of size_t (2^(#bits - 1))

### Data operations
#### Incrementation/Decrementation
- Pre-increment (`++variable`) and post-increment (`variable++`) have an effect on the *expression*, and this includes `while` loops, e.g. 
	- `while (variable++ > 0)` evaluates the expression, then increments the variable, then runs the loop
	- `while (++variable > 0)` increments the variable, evaluates the expression, then runs the loop
	(see *Increments and while loops.c*)

#### [Restrict keyword](https://www.geeksforgeeks.org/restrict-keyword-c/)
(*n.b.: check C standard (C99, C11, ...) because application may vary*)
- Mainly used in pointer declarations as a type qualifier
- Tells the compiler a pointer is the only way to access the object pointed by it, i.e. that there is no other pointer pointing to the same object
- Doesn't add functionality, only there to optimize compilation

### Strings
- A string is ....
- A `NULL` string is an empty char array, i.e. a pointer with an address that doesn't have any elements. For example, when declared, `char null[5]` doesn't contain any element and is a null string (see [ref](https://c-for-dummies.com/blog/?p=2641)). Strlen has undefined behavior since it doesn't contain any element.
- An `empty` string is a char array that contains a single element, the `\0` element. It has a length of zero although it contains a character. For example, `char empty[5] = {'\0'}` is an empty string. Strlen returns a length of 0 (see [ref](https://c-for-dummies.com/blog/?p=2641))
- `strlen`:
	- On a NULL string, undefined behavior due to the string not containing any element
	- On an empty string, length of zero
	- On other strings: only as long as non-null characters
- **String literals**: immutable by default and stored in a read-only section of memory (ROM) for safety reasons (prevent accidental modification by the program) and security (prevent alteration of essential data, including also constants and code). Also, it is harder to handle in general, so most data is better off being constant. (See [StackExchange](https://softwareengineering.stackexchange.com/questions/294748/why-are-c-string-literals-read-only?newreg=0d8085bd75304612b414bf5e01daba16))
- Creating a string with bracket notation, i.e. char array[1], creates a **non-null-terminated char array with one byte**. For a char array of length 1, declare `char array[2] = {'a', '\0'}` 

### Other topics
**scanf()**
- Why does scanf () take a pointer?
To store input in a variable using scanf() , you need to pass the memory address of the variable as an argument to the function using the & (address of) operator. This is because scanf() expects pointers as arguments to store input values directly in memory locations.

## Functions
**need a return type** : `void`, `double`, `int`, `bool`, …

### Ordering functions
The order of functions inside a file is arbitrary. It does not matter if you put function one at the top of the file and function two at the bottom, or vice versa. Caveat: In order for one function to "see" (use) another function, the "prototype" of the function must be seen in the file before the usage.

### Function parameters
When functions are called, parameters can be called by a different name (provided they are defined in the scope), but they have to be mentioned in the right order, i.e. the order of invocation.
Example:
```
 void birthday(char x[], int y) {
  printf("\nHappy Birthday dear %s!", x);
  printf("\nYo	u are %d years old!", y);
  }

int main() {
 char name[] = "Bro";
 int age = 25;
 birthday(name, age);
 }
```

### Function prototypes ###
- Cause the compiler to flag an error if arguments are missing, as many C compilers don’t check for parameter matching, thus helping us avoid unexpected behavior.
Advantages of using prototypes: helps navigate program with main at the top

## Header files

A header file is a file containing C declarations and macro definitions to be shared between several source files. It is requested by *including* it with the C prepocessing directive `#include`
- **Include Syntax** : `#include <file>` for system header files, `#include "file"` for header files of the program
- [**Include guards**](https://www.oreilly.com/library/view/c-cookbook/0596007612/ch02s02.html) (**`#ifndef` wrapper**):
  - [an `#ifndef` directive](https://www.educative.io/answers/what-is-the--sharpifndef-directive-in-c) allows conditional compilation, by asking the preprocessor to determine if any provided macros exist before any subsequent code is included. Example:
```
#include <stdio.h>

// we define a variable 
#define xyz 32

int main()
{
   // now we use #ifndef to see if xyz is defined or not in this example, it is defined, we'll move to the #else part of the code.
   #ifndef xyz
   printf("Error printing lottery number");
   #else
   printf("Your lottery number is %d", xyz);
   #endif

   return 0;
}
``` 
   - [Header files often use](https://gcc.gnu.org/onlinedocs/cpp/Once-Only-Headers.html) an #ifndef wrapper to prevent them being processed twice by the compiler, which is very likely to cause an error, e.g. when the compiler sees the same structure definition twice. Example:
```
#ifndef FILE_FOO_SEEN
#define FILE_FOO_SEEN

[the entire file]

#endif
```
`FILE_FOO_SEEN` is called the *controlling macro* or *guard macro*
- **Headers file location on OS X**:
/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/CoreFoundation.framework/Headers/CoreFoundation.h

## [Macros](https://gcc.gnu.org/onlinedocs/cpp/Macros.html)
A fragment of code which has been given a name. Using the name replaces it with the code. Two kinds: ***object-like***: resemble data objects and ***function-like***: resemble function calls

## Compilers (gcc)

## Debugging flags
- `-g` : generate debug information
- `-fsanitize` : [AddressSanitizer](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html). With `=address`, `=leak`, ...
- adding compile instructions (e.g. `-L. -lft`) to the VSCode C/C++ debugger: in `tasks.json`

## Common errors
`initializing 'char *' with an expression of type 'const char *' discards qualifiers [-Werror,-Wincompatible-pointer-types-discards-qualifiers]` => typecast the new pointer. E.g. `const char *s`, `char *search = (char *) s`; error without the `(char *)`. 