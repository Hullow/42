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
