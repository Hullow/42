# Notes on C

## General concepts
### [Undefined behavior](https://www.geeksforgeeks.org/undefined-behavior-c-cpp/)
- When the result of an executing program is unpredictable, i.e. failing to compile, executing incorrectly, crashing or generating incorrect results, or do fortuitously exactly what the programmer intended, it is said to have undefined behavior

## Memory management
### [Dynamic memory allocation}(https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- A procedure in which the size of a data structure (like an array) is changed during runtime.

## Data types
### Type-casting
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
- Mainly used in pointer declarations as a type qualifier
- Tells the compiler a pointer is the only way to access the object pointed by it, i.e. that there is no other pointer pointing to the same object
- Doesn't add functionality, only there to optimize compilation
