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