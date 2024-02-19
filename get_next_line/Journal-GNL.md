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