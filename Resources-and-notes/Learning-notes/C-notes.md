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
### [Passing variables](https://chat.openai.com/share/5bb153a7-bba4-4daf-8608-9e02c8092f8a)
#### By value
- This copies the value of the variable to the stack. E.g. when a function is called, memory is automatically allocated on the stack for its local variables. When the function returns, this memory is automatically deallocated.
#### By pointer
- Passing a pointer to a function doesn't copy the variable. Variables allocated to the heap persist until they are explicitly freed, regardless of the scope. N.b.: you can create pointers to stack-allocated data. In general, passing value by pointer is more efficient in terms of memory usage, especially for large variables, but requires careful management of the memory to avoid leaks or invalid accesses.

### Data types
#### Type-casting
- A typecast explicitly causes an expression to be of a specific data type
- "A value of type `char` is automatically promoted into a value of type `int` when used as a parameter" (*GNU Libc Manual*, p. 98)

### Pointers
#### [Null Pointers](https://www.geeksforgeeks.org/null-pointer-in-c/)
- A null pointer, initialized e.g. as `type pointer_name = 0` or `type pointer_name = NULL`, points only towards `NULL`, or `O` in the memory. It is different from a pointer pointing to an empty memory address, e.g. an empty string `type pointer_name = ""`

#### [Constant Pointers](https://www.javatpoint.com/const-pointer-in-c)
- A pointer that cannot change the address of the variable to which it is pointing, i.e. the address will remain constant. The pointer is thus a read-only variable

#### Operations on pointers
##### Dereferencing
Using the "**indirection** operator" `*`, or array brackets `[]`, the act of referring to where the pointer points, instead of a memory address. For instance, we might refer to the first element of an array
##### Referencing
Using the "**address** operator" `&` to take the address of a given variable to set a pointer variable

##### Modifying where a pointer points
- Because function arguments in C are passed by value, i.e. the function receives a copy of the argument, to modify where a pointer is pointing to in a function, you need to pass a pointer to that pointer.

When you want to modify where a pointer is pointing in a function, you need to pass a pointer to that pointer. This is because in C, function arguments are passed by value, meaning the function receives a copy of the argument.

#### Void Pointers
**Benefits and Applications**
- Memory allocation: used to allocate memory dynamically in conjunction with malloc and calloc without specifying the data type beforehand
- Generic data structures: allows the creation of data structures that can handle various data types, such as linked lists and queues
- Callback functions: have a use in implementing callback mechanisms effectively, to transfer both function pointers and related data.
- Interfacing with external libraries: allow to communicate with external libraries or functions of the system by allowing data to be passed without having to define its precise type.

#### Type-casting a pointer
- Reason: for pointer arithmetic
- Syntax: `(data type *) pointer_name`. Me: reason is because the whole type needs to be precised inside the parenthesis

#### [Structs](https://abstractexpr.com/2023/06/29/structures-in-c-from-basics-to-memory-alignment/)
- Defined as
```c
struct s {
	int a;
	int b;
	char c;
	char d[10];
};
```
- Accessing elements: `s.element`
- To accessing elements using a pointer:
```c
struct s s1; // declare a variable s1 as struct of type s
struct s *sp = &s1;
```
we have: `sp->a == s1.a;`, `sp->d[0] == s1.d[0]`, etc.
- Comparison: needs to be done element by element; C does not support simple comparison of structs
(`struct s == struct t` will lead to a compile error)
- Nested structs are possible
- Self-referential structs: only are possible using pointers. Otherwise, they would lead to infinite recursion, taking up an infinite amount of memory. 


#### Typedefs
- Allow us to give a type a new name, e.g. `typedef unsigned char BYTE;` will allow us to declare an unsigned char like so: `BYTE b = 'r';`.
- By convention, uppercase letters are used for definitions, but lowercase letters work: `typedef unsigned char byte;`.
- [For structs](https://abstractexpr.com/2023/06/29/structures-in-c-from-basics-to-memory-alignment/), removes the need to write `struct` when declaring a variable, as in `struct s s1;`. If we typedef struct s as `str`: 
```c
struct Vector 2d{
	float	x;
	float	y;
};
typedef struct Vector2D Vector2D;
```
allowing to make declarations like `Vector 2D vector;` rather than `struct Vector2D vector;`
More succintly:
```c
typedef struct Vector2D{
	float	x;
	float	y;
} Vector2D;
```



### Data structures
#### Linked lists
- Syntax note: `->` takes precedence, as in `*lst->next = new;` is equivalent to `*(lst->next) = new;`. To dereference, you need to a parenthesis: `(*lst)->next = new;` (example from Libft/ft_lstadd_back_bonus.c)


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
#### Characters
##### Encoding conventions
- In C, implicit encoding is implementation specific:
> "The encoding used by the char is that of the environment under which it is executing, but the type also doubles as a type for working with any byte (octet) data. This is likely one of the sources of confusion that cause developers to assume that one character equals one byte. C99 defines char to have a range of either -127 to 127 or 0 to 255. That is, it is always 8 bits." (see [comparing character encoding in C, C#, Java, Python and Ruby](https://illegalargumentexception.blogspot.com/2010/04/i18n-comparing-character-encoding-in-c.html))


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
```c
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
```c
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
```c
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

#### [Variable arguments/Variadic functions](https://www.gnu.org/software/libc/manual/html_node/Receiving-Arguments.html)
Function arguments can vary in number and in type. To handle this, C doesn't have any built-in functionality, hence stdarg.h's special macros must be used. 
##### [Argument access macros](gnu.org/software/libc/manual/html_node/Argument-Macros.html):
- Data type: `va_list`. A type used for argument pointer variables
- Macro: `void va_start (va_list ap, last-required)`. This macro initializes the *argument pointer variable* `ap` to point to the first of the optional arguments of the current function; *last-required* must be the last required argument to the function.
- Macro: `type va_arg (va_list ap, type)`. This macro returns the value of the next optional argument, and modifies the value of `ap` to point to the subsequent argument. The type of the return value is specified in the call. 
- Macro: `void va_end(va_list ap)`. This macro ends the use of `ap`; after it, further va_arg calls with the same `ap` may not work. In the GNU C Library, `va_end` doesn't do anything and is only used for reasons of portability.
- Macro: `va_copy(va_list dest, va_list src)`. This macro allows copying of objects of type `va_list` even if this is not an integral type. The argument pointer in `dest` is initialized to point to the same argument as the pointer in `src`.
##### [Calling variadic functions](https://www.gnu.org/software/libc/manual/html_node/Calling-Variadics.html)
> Since the prototype doesn’t specify types for optional arguments, in a call to a variadic function the default argument promotions are performed on the optional argument values. This means the objects of type char or short int (whether signed or not) are promoted to either int or unsigned int, as appropriate; and that objects of type float are promoted to type double. So, if the caller passes a char as an optional argument, it is promoted to an int, and the function can access it with va_arg (ap, int).

## Compilers (gcc)
- gcc: GNU compiler collection (C, C++, Ada, Go)
- [Clang](https://clang.llvm.org/): compiler/frontend for LLVM for C, C++, Objective-C, CUDA, ...). Contains a gcc-compatible compiler driver
- ### Compiler flags
- `-I` : specifies to look in the current directory (.) for header files. Alternative: `INC_DIR = .`
- `-c`: generate the object file, i.e. compile and assemble, but do not link
- `-o` : write output to file

## Debugging
- GDB: GNU debugger
- lldb: low-level debugger, part of the LLVM project

### Debugging flags
- `-g` (or `-g3`) : generate debug information => n.b.; necessary to set breakpoints in source code !
- `-fsanitize` : [AddressSanitizer](https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html). With `=address`, `=leak`, ...
- adding compile instructions (e.g. `-L. -lft`) to the VSCode C/C++ debugger: in `tasks.json`

### CLI debugging
- lldb a.out, b 21 or b main (set breakpoint), run, gui, s to go to next step, esc. process restart to restart debugging.

## Common errors
initializing `char *` with an expression of type `const char *` discards qualifiers `[-Werror,-Wincompatible-pointer-types-discards-qualifiers]` => typecast the new pointer. E.g. `const char *s`, `char *search = (char *) s`; error without the `(char *)`. 
