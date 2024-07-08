# 27/4/24
- Started project in Prague in a bar along the Vltava
- Not clear how to send a signal. Maybe using write? Then catch PID ? Then 

# 28/4/24
- More reading of the manual, trying to use getpid()

# 18/6/24
- Passed fdf and pushed push_swap, now back to this
- Managed to get and print out a PID using `getpid();`

# 19/6/24
- With some help from Copilot on concepts, managed to generate a signal with kill
- Working on sending stuff from one process to another

# 24/6/24
- Back to topic
- Reading [42 Minitalk Explained – Oduwole Dare](https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24) together with `man sigaction` and things make a tiny bit more sense. Testing the code with SIGINT-test.c and commands like `kill -9 $(pgrep a.out)` => ok.
- Still don't understand how to catch a signal from another executable but it seems like maybe some lines of Oduwole Dare make sense, e.g.
```c
kill(pid, SIGUSR1);
         // initialize pid to zero, so that you can handle multiple terminals
         // return
```

# 26/6/24
- Reading [Envoyer et intercepter un signal en C](https://www.codequoi.com/envoyer-et-intercepter-un-signal-en-c/)

# 27/6/24
- Test strace: "intercepts and records the system calls which are called by a process and the signals which are received by a process.  The name of each system call, its arguments and its return value are printed on standard error or to the file specified with the -o option. strace is a useful diagnostic, instructional, and debugging tool."

# 28/6/24
- No need to run server and client with one command ! Run server, get PID, then 
run client...time wasted: 1-2 days
- weird compile bug with ft_strlen in ft_printf, checked and didn't see the issue,
so just added ft_strlen directly in ft_print_string.c.
Error was:
```bash
gcc -Wall -Wextra -Werror server.o -L./lib -lft -lftprintf -o server
/usr/bin/ld: ./lib/libftprintf.a(ft_print_string.o): in function `ft_print_string':
ft_print_string.c:(.text+0x88): undefined reference to `ft_strlen'
collect2: error: ld returned 1 exit status
make: *** [Makefile:56: server] Error 1
```
- managed to start server with ./server&, then sent signal with kill without error. pause() works too, but the process stops right after, nothing is printed out.

# 1/7/24
- Fixed Makefile (clean, fclean)
- Re-read `man 7 signal` to understand whether sigemptyset and sigaddset are necessary; according to Thenguye, not really. Also learned about real-time signals, but they're not really accessible because they need specific functions like rt_sigaction
- Started working on text to binary signal protocol
- Rewrote makefile a bit
- Tested sigaddset but removed, don't see the use for now

# 2/7/24
- Fixed issue with characters not appearing by showing code of "server.c" to Copilot which suggested adding some timing between signals, because things might be sent too fast; went down to usleep(100). Works real fast even with like 100 characters
- Now, how to reconvert binary signals to characters
- We have a working version. but bugs for non alphabetical characters .
    - buggy sequences:
        - ; => argument not recognised
        - ";" => blank
        - ababbaddddd; => ; doesn't appear
        - "abbjffv;" => wCEEUMMm

# 3/7/24
- Took a brief look at the Makefile to try to fix the relink, also an issue in push_swap, where there are multiple executables to compile. Still not very clear.

# 6/7/24
- Fixed Makefile while talking to Copilot, which didn't give me the solution but made me relook at the file multiple times:
    => not remaking without "all" issue : put "all" target first and reorder targets
    => relinking: paths of libraries
- Worked a bit on binary decoding but still no success (tried int instead of unsigned int, created a file "input_test.c" to see)
- Okay, issue is when binary numbers have <7 binary digits, i.e. when less than 100 (@ in ascii). Looked at discord discussion and someone mentions [bitshifting](https://en.m.wikipedia.org/w/index.php?title=Bitwise_operation&diffonly=true#Bit_shifts). Also, someone mentioned sending ascii 6 and 21 instead of usleep, following the concept of an [acknowledgment](https://en.m.wikipedia.org/wiki/Acknowledgement_(data_networks)).
=> I wanna avoid a malloc !!

# 8/7/24
- Midnight reading Wikipedia ([Endianness](https://en.wikipedia.org/wiki/Endianness), [Bit numbering](https://en.wikipedia.org/wiki/Bit_numbering), [Bitwise operators in C, C++ - GeeksforGeeks](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/), [Bit array](https://en.wikipedia.org/wiki/Bit_array), [Bit fields in C - GeeksforGeeks](https://www.geeksforgeeks.org/bit-fields-c/) => to optimise with a struct if a number uses fewer bits than it can store)
- Send 3 bits before each word to say if 1,2,3,4,5,6, or 7 bits number ? 7 == 111
e.g. ! is 33 == 100001, 6 bits. 64 is 1000000, 7 bits.
if 7, shift 0 bits to right
if 6 bits, i.e. 32 <= char < 64, shift 1 bit to right
if 5 bits, i.e. 16 <= char < 32, shift 1 bit to right
=> but [ASCII printable characters](https://www.ascii-code.com/characters/printable-characters) are 32 to 126, so 6 or 7 bits. Hence if character is only 6 bits,
just send a 0 before calling the function
	=> It works ! But issue with `;`, not recognized as an argument. Works between parentheses, but then "!;" has a bug "bash: !: event not found"
		=> Issue due to `!` being interpreted as a special character for history expansion, and can be avoided either with an escape character `\` or with single quotes
	=> Issue with "é" => check locale and unicode encoding on 42 iMacs ?
		=> Unicode is bonus

- Time optimisation: 100 characters without " or ' inside the sequence is too long.
	- Also, tried to make the program usleep modulo X but didn't solve the issue.
	- Reduced write to write 1 byte instead of 4. Still issue
	- Looking at ACK (6 in ASCII) => but this involves sending a signal back no ? Or if we just send a signal to the process itself, maybe it slows things down ? Probably not the right idea. Instead, look into sending PID of client to server, then send 

- Nb "Une fois la chaîne **entièrement** reçue" => must malloc

generate random ASCII with selected characters: https://onlinetools.com/ascii/generate-random-ascii
