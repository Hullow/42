# 1/2/24
- Started project:
	- read subject and took notes about concepts  (static variables, read & open functions, I/O system calls, EOF, the required preprocessor flag ...)
	- played with the open() and read() functions with examples borrowed from the web (see *read-open.c*) 
	- started writing an outline of the function and its components, including pseudocode

# 6/2/24
- Reading and taking notes about more concepts: system calls (because `open()` is referred to as a "BSD system call" in its manual), virtual memory, secondary and primary memory, userspace and kernel space, page table, file descriptors, ...
- Outline: trying to summarize how to do GNL
- Tests: playing with `open()`, `read()`, `close()`, and the buffer.
	- Segfault with my "example.txt" file, the first line has 24 characters before the first newline ("This is an example text."). `read(fd, buff, 24);` works perfectly. `read(fd, buff, 25);` prints a newline character followed by a "�" and `read(fd, buff, 26);` works but is followed by an "abort" error. So it seems `read()` or the buffer has a problem with newlines. The buffer `buff` is a simple array `buff[X]`.
	Strangely enough, it works even though buff has length 6=> probably because characters after string end are there, so
	Segfault definition:
	the software attempted to access a restricted area of memory ()
	Common in languages like C providing low-level memory access and few to no safety checks. They arise primarily due to errors in use of pointers for virtual memory


# 8/2/24
- Still reading and taking notes. Watched video on [Memory Layout of C program](https://www.youtube.com/watch?v=0jhQBQcGnuM), [chatted with ChatGPT](https://chat.openai.com/c/ba5844cd-c83f-4e95-aa7c-fa5d01b90ffd#:~:text=Can%20you%20explain%20how%20a%20static%20variable) about Memory layout and concepts associated (stack, heap, call stack, memory segments, tools to visualize all this, etc.)
- Started coding

(...)

# 13/2/24
- Actually we do need a static variable
- Early working version. Now need to work on memory handling, exceptions, and Norm
- Next time: continue writing outline in comments of utils (in **ft_next_lines**)

# 15/2/24
- Working on issues with "temp"
- EOF handling

# 19/2/24
- Worked on issues caused by lack of EOF awareness
- After having removed EOF handling, brought it back. It solves some issues
- N.b.: might need read error handling, when read returns -1

# 22/2/24
- Back to work
- Seems like we have a working version for many buffer sizes
- To do :
	- test different inputs (texts and file descriptors)
	- return NULL when nothing to read or in case of error
	- write a test program (compare desired output to actual output)
	- handle read() errors
	- Memory management
	- Norm
	- not read all the file ?
	- hhh
	- check if it is correct: 

# 23/2/24
- Continued work on norm and memory management, cutting the gnl function into smaller pieces to fit 25 lines. Removed the temp variable, it works


ERROR Copilot:

> GitHub Copilot
The const char * type in C means that the function promises not to change the contents of the string pointed to by the pointer. It doesn't mean that the string itself can't be changed by other parts of your program, or that the string can't be a null pointer.

If you're getting a "EXC_BAD_ACCESS (code=EXC_I386_GPFLT)" error when calling ft_strlen(), it's likely because you're passing a null pointer (NULL) to ft_strlen(). Your implementation of ft_strlen() correctly checks if str is NULL before trying to access it, so the error must be happening somewhere else.

Without seeing the rest of your code, it's hard to say exactly where the error is occurring. However, here are a few things you could check:

Make sure you're not calling ft_strlen() with a null pointer elsewhere in your code.

Make sure you're not freeing a string and then trying to access it. Once a string has been freed, you can't access it anymore.

Make sure you're not going out of bounds of your strings. If you try to access a character beyond the end of a string, you'll get a "EXC_BAD_ACCESS" error.

Make sure you're not trying to modify a string that was declared as a string literal. String literals are read-only, and trying to modify them will result in a "EXC_BAD_ACCESS" error.

Hullow
I added

c if (!str) return (0); to my ft_strlen function in get_next_line.c, as you can see. Still the problem persists. Can you help me understand why ?

GitHub Copilot
The check you added in ft_strlen is a good step, it prevents the function from trying to access memory through a null pointer. However, the "EXC_BAD_ACCESS (code=EXC_I386_GPFLT)" error means that your program is trying to access memory that it doesn't have permission to access. This can happen for a variety of reasons, not just null pointers.

Here are a few other possibilities:

Accessing freed memory: If you're trying to access memory that has already been freed, you'll get this error. Make sure you're not freeing any strings that ft_strlen might be trying to access.

Buffer overflow: If you're trying to access memory beyond the end of an allocated block, you'll get this error. Make sure you're not going past the end of any strings.

Modifying a string literal: In C, string literals are read-only. If you're trying to modify a string literal, you'll get this error. Make sure any strings you're trying to modify are not string literals.

Without seeing the rest of your code, it's hard to say exactly what's causing the error. However, you can use a debugger to help find the issue. If you're using a debugger like gdb, you can run your program until it crashes, then use the backtrace command to see what function the program was in when it crashed. This should give you a clue as to where the problem is.

# 27/2/24
- Works on ARM/M1 (all buffer sizes) but not Intel iMac (segfaults). Why could that be ? Copilot:

> Different architectures have different ways of handling memory, and what causes a segmentation fault on one might not cause a segmentation fault on another. Here are a few reasons why this might be happening:

> Differences in memory alignment requirements: Some architectures require certain types of data to be aligned on specific boundaries in memory. If your code violates these requirements, it could cause a segmentation fault on one architecture but not on another.

> Differences in how out-of-bounds memory access is handled: Some architectures might allow you to access memory slightly beyond the end of an allocated block, while others will immediately cause a segmentation fault.

> Differences in the default value of uninitialized memory: On some architectures, newly allocated memory is automatically set to zero, while on others it's filled with arbitrary data. If your code relies on memory being initialized to zero, it might work on one architecture but not on another.

> Differences in the size of certain data types: The size of data types like int and long can vary between architectures. If your code makes assumptions about these sizes, it could cause issues on different architectures.

> Without seeing your code, it's hard to say exactly why it's causing a segmentation fault on an Intel machine but not on an M1/ARM machine. However, these are some possible explanations. To debug this, you could use a tool like Valgrind or AddressSanitizer to check for memory errors in your code.

- Discussion with Copilot on memory errors and good practices (to copy in Computing Notes/C notes)

- **The memory problems seem to arise from using return_array[2] `` => asked Copilot for a solution to return two values of different types from a function, suggested the struct, so I use a struct ! It works now**, but still issues when using -fsanitize=address.

- Doesn't work actually; problems seem to come from my ft_fill_char with buf (see ft_fill_line comment line 29
ft_strlen