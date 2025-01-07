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


- (In the train):
From [42 Minitalk Explained – Oduwole Dare](https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24), how to handle multiple terminals
```c
void sig_handler(int signum, siginfo_t* info, void* context)
{
  /**
  * create static int variable for pid and i and static char for c
  * void unused arg
  * set the details of the pid you are receiving from to the pid by using
  * info->pid
  * send the signal number and address of c to the bin_to_char function
  * if (++i == 8) // for every 8 bit read c
     {
      initialize i to 0
      if (!c) // this if block prepares the server for new feed of strings
      {
         kill(pid, SIGUSR1);
         // initialize pid to zero, so that you can handle multiple terminals
         // return
      }
      // since we have read 8 bits we can now read c and then initalise it back
      // back to null
     }
     kill(pid, SIGUSR2);
  */
}
```

What is max size of command line argument ? [Stack Overflow](https://stackoverflow.com/a/7499490/21457978): 
> "no individual limit on the number of arguments or argument's length. Only [a] limit on total size required to store all the arguments and environment variables."
To find it: `getconf ARG_MAX` => returns 1048576

Testing ASCII characters one by one:
- problem with `\` => `dquote>`
- problem with "\`"  => `dquote bquote>`

Be careful to restart server if issues when sending strings
sample strings of length 100:

>s9DACTNXq;}j*.MhbrenRQ/^bi9;1%{>rJ9~o>JFMx}N5z]JY:(BW>xHd4Pz*(mus1U_qB3B=/kMcg>$R>(~*(R)e4&o35J&<b)
;lTF_SIf:,^4TRu@Dy%A$Nme*QTk3-@)jN5_9Gkq+}fx]T=WB5st[2PR=kZ^*&ndc;-M*I(NCX=O3MlFFqD@cy4M5Q5/.nfRex+7
l.FT&1s~_:q@2^-2<*i)CCk;a%3>~_3mSr1Qu*qm}NLrm,Wn#&S@dmZ~#U=bHWwdiGDxYCm$&|=7w#^q2+i0bfxmS.m}0C:Ep=k,
3u/Ys0rAL:d49{wFXi<]E0/M;q$XHV/Eba9YfFk*:]DRdmvW);)3/~Q&.zVL%{7hdsdY[?YHJu[Q]$bqQI{a(mhr5Q-MXSHo(_pJ
-weFi/N:vIe|2,PDcXw5PmLH<iSM9_@_<2/+:,]|<k/865A+D,^=KO4E2?HV^N+_D,w9L)~Fs*{sf+qb|6RcHMA%n{3x(e@Zh*G[
2Kz0fJ<5/vUdCNx9dveu}S{E_L3a2HP6y*RV2--M~cJx$F1hD?*TbL73UiT?ZF+0p7^7Pivp<{K6J?x?t|LC4HX,z*=ZQaZ?w=ae
9-MNt0^Ul~Q]citr)>4;j:G%64?~3#0_nd7vQ7r2Y&n=lSS;dx$45Qd(gMekRB+VuEcqB#kdAu}Y9~T;DdaKO>~:I5(A$ZQq?;%8
l*?_?_/4[(@5puEhG_YoN9WHCQ|eV0Z<kb~?_(>+OTx[HL[JWmTEK3aWUBa=?4#qpVnkO5[L:p;zpNbkerR$A{FbP2LDk;nsAPFI
[A]J)<3/^(|u#%caY2md3nps?M@=W&H4w]gX[_zgTfUuDxd_*BWm)#m4v@8eO/]i8zolk]*o=~1Eg)4_9_/U&/|b)b_3sdn8FwN%
7Ms^G-%vaT3a^Plu9Y+rG2H_QX?Qdtv[T|XpT7I@JU++Bu8g7cpCZ^2f=G,Bu&[z5Z)Ax}_C#kr@eP7qG,DuHBI##-_w.F:7kE<F

- Got correction but it broke on ASCII < 32, such as tab, as planned. 
Fixed it by sending additional 0s (SIGUSR1) for each fewer bit (e.g. if ASCII value is 9, i.e. tab, 
that is 1001 in binary, i.e. 4 bits, so we send 3 0's before sending 1001, ending with 7 bits as planned)

Also, went from 7 bits to 8, just in case (to protect our `write(1, &byte, 1)` among other things)

- Began to work on bonus: sending signal back to client, with sigaction flag SA_SIGINFO but couldn't make it work so far