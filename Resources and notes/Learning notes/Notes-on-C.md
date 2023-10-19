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

#### [Restrict keyword](https://www.geeksforgeeks.org/restrict-keyword-c/)
(*n.b.: check C standard (C99, C11, ...) because application may vary*)
- Mainly used in pointer declarations as a type qualifier
- Tells the compiler a pointer is the only way to access the object pointed by it, i.e. that there is no other pointer pointing to the same object
- Doesn't add functionality, only there to optimize compilation

### Other topics
**scanf()**
- Why does scanf () take a pointer?
To store input in a variable using scanf() , you need to pass the memory address of the variable as an argument to the function using the & (address of) operator. This is because scanf() expects pointers as arguments to store input values directly in memory locations.

## Functions
**need a return type** (`void`, `double`, `int`, `bool`, …)

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
- **Include Syntax** : `#include <file>` for system header files, `#include "file"` for header files of the program
- **Headers file location on OS X**:
/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/CoreFoundation.framework/Headers/CoreFoundation.h
