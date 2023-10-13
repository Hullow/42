# Notes on C

## General concepts
### [Undefined behavior](https://www.geeksforgeeks.org/undefined-behavior-c-cpp/)
- When the result of an executing program is unpredictable, i.e. failing to compile, executing incorrectly, crashing or generating incorrect results, or do fortuitously exactly what the programmer intended, it is said to have undefined behavior

## Pointers
### Void Pointers
**Benefits and Applications**
- Memory allocation: used to allocate memory dynamically in conjunction with malloc and calloc without specifying the data type beforehand
- Generic data structures: allows the creation of data structures that can handle various data types, such as linked lists and queues
- Callback functions: have a use in implementing callback mechanisms effectively, to transfer both function pointers and related data.
- Interfacing with external libraries: allow to communicate with external libraries or functions of the system by allowing data to be passed without having to define its precise type.

### [Restrict keyword](https://www.geeksforgeeks.org/restrict-keyword-c/)
- Mainly used in pointer declarations as a type qualifier
- Tells the compiler a pointer is the only way to access the object pointed by it, i.e. that there is no other pointer pointing to the same object
- Doesn't add functionality, only there to optimize compilation
