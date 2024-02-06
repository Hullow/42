# 1/2/24
- Started project:
	- read subject and took notes about concepts  (static variables, read & open functions, I/O system calls, EOF, the required preprocessor flag ...)
	- played with the open() and read() functions with examples borrowed from the web (see *read-open.c*) 
	- started writing an outline of the function and its components, including pseudocode

# 7/2/24
- Reading and taking notes about more concepts: system calls (because `open()` is referred to as a "BSD system call" in its manual), virtual memory, secondary and primary memory, userspace and kernel space, page table, file descriptors, ...
- Outline: trying to summarize how to do GNL
- Tests: playing with `open()`, `read()`, `close()`, and the buffer.
	- Segfault with my "example.txt" file, the first line has 24 characters before the first newline ("This is an example text."). `read(fd, buff, 24);` works perfectly. `read(fd, buff, 25);` prints a newline character followed by a "�" and `read(fd, buff, 26);` works but is followed by an "abort" error. So it seems `read()` or the buffer has a problem with newlines. The buffer `buff` is a simple array `buff[X]`.
	Strangely enough, it works even though buff has length 6=> probably because characters after string end are there, so
	Segfault definition:
	the software attempted to access a restricted area of memory ()
	Common in languages like C providing low-level memory access and few to no safety checks. They arise primarily due to errors in use of pointers for virtual memory 