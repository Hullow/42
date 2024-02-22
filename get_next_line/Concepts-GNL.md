References:

https://epitech-2022-technical-documentation.readthedocs.io/en/latest/valgrind.html

# Concepts
## [Static variables](https://en.wikipedia.org/wiki/Static_variable)
A variable with a lifetime of the entire run of the program. Its memory allocation is static. In contrast stand shorter-lived **automatic variables**, whose storage is stack allocated and deallocated on the call stack, and **objects**, whose storage is dynamically allocated and deallocated in heap memory

Lifetime is contrasted with **scope**, which can be global or local, although scope often implies lifetime. In many languages, global variables are always static, but in some they are dynamic, while local variables are generally automatic, but may be static.

A static local variable is different from a local variable as a static local variable is initialized only once no matter how many times the function in which it resides is called and its value is retained and accessible through many calls to the function in which it is declared, e.g. to be used as a count variable.  This persistent state allows them to be used for maintaining state information across function calls.

[Visibility](https://chat.openai.com/c/ba5844cd-c83f-4e95-aa7c-fa5d01b90ffd#:~:text=The%20scope%20or,as%20extern.): The scope or visibility of a static variable is limited to the block (usually a function) where it is defined if declared inside a function. If declared outside of any function (globally), its visibility is limited to the file in which it is declared, due to internal linkage, unless explicitly declared as `extern`.

Initialization: Static variables are automatically initialized to zero (for arithmetic types) or NULL (for pointers) if not explicitly initialized by the programmer.

In general, static memory allocation is the allocation of memory at compile time, before the associated program is executed, unlike dynamic memory allocation or automatic memory allocation where memory is allocated as required at run time.


## Example
An example of a static local variable in C:

```c
#include <stdio.h>

void Func() {
  static int x = 0;
  // |x| is initialized only once across five calls of |Func| and the variable
  // will get incremented five times after these calls. The final value of |x|
  // will be 5.
  x++;
  printf("%d\n", x);  // outputs the value of |x|
}

int main() {
  Func();  // prints 1
  Func();  // prints 2
  Func();  // prints 3
  Func();  // prints 4
  Func();  // prints 5

  return 0;
}
```

## Buffer size
If it is an array, the [max length of an array is constrained by multiple factors](https://www.geeksforgeeks.org/maximum-size-of-an-array-in-c/)

4. Maximum range index
Another factor is the maximum index value that can be used to access elements in an array. This value depends on the data type used for indexing, and using a signed integer, for instance, will limit the maximum index value to 2^31 – 1.

## File descriptor
- [Wikipedia](https://en.wikipedia.org/wiki/File_descriptor):
>In Unix and Unix-like computer operating systems, a file descriptor (FD, less frequently fildes) is a process-unique identifier (handle) for a file or other input/output resource, such as a pipe or network socket.
- A file descriptor is an unsigned integer used by a process to uniquely identify an open file.

- [42 Gitbook](https://42-cursus.gitbook.io/guide/useful-tools/file-descriptors-fd):
Now, every process in Unix starts out with three file descriptors predefined, i.e. there are 3 standards file descriptors that are automatically added to the file descriptor table. These file descriptors are the standard input/output file descriptor and always have these values :
0 : this file descriptor represents the stdin (=> standard input, the terminal). This is the file descriptor used when reading user input from the terminal.
1 : this file descriptor represents the stdout (=> standard output, the terminal). This is the file descriptor used when writing to the terminal.
2 : this file descriptor represents the stderr (=> standard error output, the terminal). This is the file descriptor used when writing an error to the terminal, the information is written the same way, but a program which logs errors to a file can redirect everything written to the stderr file descriptor to a file. It's managed in another way by the operating system.
([Unix system calls - CS360 UTK](https://web.eecs.utk.edu/~huangj/cs360/360/notes/Syscall-Intro/lecture.html))

Example: a [simple version](https://web.eecs.utk.edu/~huangj/cs360/360/notes/Syscall-Intro/simpcat.c) of **cat** can be written as:
```c
main()
{
	char c;

	while ((read(0, &c, 1) == 1) write(1, &c, 1);
}
```

### Terminology
- File Descriptor: the index of the File Table Entry in the file descriptor table.
- File Descriptor Table: an array of File Table Entry, each process gets its own File Descriptor Table.
- File Table Entry: a structure that contains informations about a file.
- Global File Table: a system wide table containing all files. (It can't contain all files at once but the operating system will automatically update the table if you request a file that's not in this table).

### How it works
When you read bytes from a file descriptor, it remembers where in the file it was last time.
This means, if you read 20 bytes from a file, next time you'll read from the same file descriptor, it will start reading from byte 21. Take a look at the example below.


## Functions
### System calls
The "tool" used by a software in the userspace to request a "service" to the kernel.
Modern OSes generally divide the virtual memory into user space and kernel space.

Read the rest of [I/O Syscalls intro - CS360](https://web.eecs.utk.edu/~huangj/cs360/360/notes/Syscall-Intro/lecture.html) if interest

#### open
`man 2 open`: The file name specified by *path* is opened for reading and/or writing, as specified by the argument *oflag*; the file descriptor is returned to the calling process.
The flags of the *oflag* argument must include exactly one of:
- O_RDONLY        open for reading only
- O_WRONLY        open for writing only
- O_RDWR          open for reading and writing


#### read
`man 2 read`: read input. Standard C library/libc.

`ssize_t read(int fildes, void *buf, size_t nbyte);`

     #include <sys/types.h>
     #include <sys/uio.h>
     #include <unistd.h>

>**read** attempts to read *nbyte* bytes from the object referenced by the descriptor *fildes* into the buffer pointed to by *buf*.<br>
>On objects capable of seeking, the **read**() starts at a position given by the pointer associated with **fildes** (see lseek(2)). Upon return from **read**(), the pointer is incremented by the number of bytes actually read.<br>
>Objects that are not capable of seeking always read from the current position. The value of the pointer associated with such an object is undefined.<br>
>Upon successful completion, **read**() returns the number of bytes actually read and placed in the buffer. The system guarantees to read the number of bytes requested if the descriptor references a normal file that has that many bytes left before the end-of-file, but in no other case. **read**() will fail if the parameter *nbyte* exceeds INT_MAX, and does not attempt a partial read<br>
>Return values:
If successful, the number of bytes actually read is returned. Upon reading end-of-file, zero is returned. Otherwise, a -1 is returned and the global variable *errno* is set to indicate the error.

Important Points (from [geeksforgeeks](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/))
- buf needs to point to a valid memory location with a length not smaller than the specified size because of overflow.
- fd should be a valid file descriptor returned from open() to perform the read operation because if fd is NULL then the read should generate an error.
- nbytes is the requested number of bytes read, while the return value is the actual number of bytes read. Also, some times read system call should read fewer bytes than nbytes.


[Linux Hints](https://linuxhint.com/posix-read-functioning-in-c-programming/):
>If the read() function returns successfully, it returns the number of bytes read. A result that is equal to 0 means that the file is read to the end, and -1 means that an error occurs

On the buffer used by `read()`, Copilot says:
>In the context of the `read()` system call, a buffer is a block of memory used for temporary storage of data. 
When you call `read(int fildes, void *buf, size_t nbyte);`, you're asking the system to read `nbyte` bytes of data from the file or device represented by `fildes`, and store that data in the memory area pointed to by `buf`. 
This buffer must be large enough to hold at least `nbyte` bytes. The data can then be processed from this buffer as needed. This is a common pattern in I/O operations, as it allows for efficient reading and writing of data.



# [EOF](https://stackoverflow.com/a/7622741/21457978)
EOF (as defined in the C language) is not a character/not an ASCII value. That's why getc returns an int and not an unsigned char - because the character read could have any value in the range of unsigned char, and the return value of getc also needs to be able to represent the non-character value EOF (which is necessarily negative).
– answered Oct 1, 2011 at 20:23

The actual value of EOF is system defined and not part of the standard.
EOF is an int with negative value and if you want to print it you should use the %d format string. Note that this will only tell you its value on your system. You should not care what its value is.
– edited Oct 1, 2011 at 20:50

# Compile options
>Votre programme doit compiler avec l’option : `-D BUFFER_SIZE=n`
Cette macro définie à l’invocation du compilateur servira à spécifier la taille du
buffer lors de vos appels à read() dans votre fonction get_next_line().
Cette valeur sera modifiée lors de la peer-evaluation et par la Moulinette dans le
but de tester votre rendu.
We must be able to compile this project with and without the -D
BUFFER_SIZE flag in addition to the usual flags. You can choose the
default value of your choice.

GCC Manual:
>[3.13 Options Controlling the Preprocessor](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Preprocessor-Options.html)
These options control the C preprocessor, which is run on each C source file before actual compilation.

>`-D name` : Predefine name as a macro, with definition 1.

`-D name=definition`
>The contents of definition are tokenized and processed as if they appeared during translation phase three in a ‘#define’ directive. In particular, the definition is truncated by embedded newline characters.

[#define directive (C/C++) (Microsoft Learn)](https://learn.microsoft.com/en-us/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170)
Syntax: `#define identifier token-string`

>The #define directive causes the compiler to substitute token-string for each occurrence of identifier in the source file. The identifier is replaced only when it forms a token. That is, identifier is not replaced if it appears in a comment, in a string, or as part of a longer identifier.

[Object-like macros (IBM)](https://www.ibm.com/docs/en/zos/2.3.0?topic=directives-define-directive)
>An object-like macro definition replaces a single identifier with the specified replacement tokens. For example, the following object-like definition causes the preprocessor to replace all subsequent instances of the identifier COUNT with the constant 1000 :
```c
#define COUNT 1000
```