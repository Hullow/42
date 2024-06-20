# Functions

# Running two executables at the same time
From Copilot:
> Yes, it is possible to run two executables simultaneously in both C and Bash.
In Bash, you can use the `&` operator to run a command in the background, allowing the next command to run without waiting for the first one to finish. Here's an example:
`./executable1 & ./executable2`
In this example, `executable1` will run in the background, and `executable2` will run immediately after, without waiting for `executable1` to finish.

# sleep
`man 3 sleep`: 
> "suspend thread execution for an interval measured in seconds"<br>
`unsigned int sleep(unsigned int seconds);`

DESCRIPTION
	The sleep() function suspends execution of the calling thread until either seconds seconds have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching function or to terminate the thread or process.
	System activity may lengthen the sleep by an indeterminate amount.

	This function is implemented using nanosleep(2) by pausing for seconds seconds or until a signal occurs.  Consequently,	in this implementation, sleeping has no effect on the state of process timers, and there is no special handling for	SIGALRM.

RETURN VALUES
	If the sleep() function returns because the requested time has elapsed, the value returned will be zero.  If the sleep() function returns due to the delivery of a signal, the value returned will be the unslept amount (the requested time	minus the time actually slept) in seconds.

# getpid
> "get parent or calling process identification"<br>
`pid_t getpid(void);`
DESCRIPTION
	getpid() returns the process ID of the calling process.  The ID is guaranteed to be unique and is useful for constructing temporary file names.
ERRORS
	The getpid() and getppid() functions are always successful, and no return value is reserved to indicate an error.

# sigaction
sigaction – software signal facilities
> The system defines a set of signals that may be delivered to a process.  Signal delivery resembles the occurrence of a hardware interrupt: the signal is normally blocked from further occurrence, the current process context is saved, and a new one is built.  A process may specify a handler to which a signal is delivered, or specify that a signal is to be ignored.  A process may also specify that a default action is to be taken by the system when a signal occurs.  A signal may also be blocked, in which case its delivery is postponed until it is unblocked.

```c
struct  sigaction {
			union __sigaction_u __sigaction_u;  /* signal handler */
			sigset_t sa_mask;               /* signal mask to apply */
			int     sa_flags;               /* see signal options below */
     };

     union __sigaction_u {
			void    (*__sa_handler)(int);
			void    (*__sa_sigaction)(int, siginfo_t *,
						void *);
     };

     #define sa_handler      __sigaction_u.__sa_handler
     #define sa_sigaction    __sigaction_u.__sa_sigaction

int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```

# signal
signal – simplified software signal facilities

Signals allow the manipulation of a process from outside its domain, as well as allowing the process to manipulate itself or copies of itself (children). There are two general types of signals: those that cause termination of a process and those that do not. Signals which cause termination of a program might result from an irrecoverable error or might be the result of a user at a terminal typing the 'interrupt' character. Signals are used when a process is stopped because it wishes to access its control terminal while in the background. Most signals result in the termination of the process receiving them, if no action is taken; some signals instead cause the process receiving them to be stopped, or are simply discard if the process has not requested otherwise. Except for the SIGKILL or SIGSTOP signals, the signal() function allows for a signal to be caught, to be ignored, or to generate an interrupt. These signals are defined in the file <signal.h>:


	   Name             Default Action       Description
-----------------------------------------------------------
1     SIGHUP           terminate process    terminal line hangup
2     SIGINT           terminate process    interrupt program
3     SIGQUIT          create core image    quit program
4     SIGILL           create core image    illegal instruction
5     SIGTRAP          create core image    trace trap
6     SIGABRT          create core image    abort program (formerly SIGIOT)
7     SIGEMT           create core image    emulate instruction executed
8     SIGFPE           create core image    floating-point exception
9     SIGKILL          terminate process    kill program
10    SIGBUS           create core image    bus error
11    SIGSEGV          create core image    segmentation violation
12    SIGSYS           create core image    non-existent system call invoked
13    SIGPIPE          terminate process    write on a pipe with no reader
14    SIGALRM          terminate process    real-time timer expired
15    SIGTERM          terminate process    software termination signal
16    SIGURG           discard signal       urgent condition present on socket
17    SIGSTOP          stop process         stop (cannot be caught or ignored)
18    SIGTSTP          stop process         stop signal generated from keyboard
19    SIGCONT          discard signal       continue after stop
20    SIGCHLD          discard signal       child status has changed
21    SIGTTIN          stop process         background read attempted from control terminal
22    SIGTTOU          stop process         background write attempted to control terminal
23    SIGIO            discard signal       I/O is possible on a descriptor (see fcntl(2))
24    SIGXCPU          terminate process    cpu time limit exceeded (see setrlimit(2))
25    SIGXFSZ          terminate process    file size limit exceeded (see setrlimit(2))
26    SIGVTALRM        terminate process    virtual time alarm (see setitimer(2))
27    SIGPROF          terminate process    profiling timer alarm (see setitimer(2))
28    SIGWINCH         discard signal       Window size change
29    SIGINFO          discard signal       status request from keyboard
30    SIGUSR1          terminate process    User defined signal 1
31    SIGUSR2          terminate process    User defined signal 2	 
```c
void (* signal(int sig, void (*func)(int));)(int);

or in the equivalent but easier to read typedef'd version:
typedef void (*sig_t) (int);

sig_t signal(int sig, sig_t func);
```

# Safe functions to invoke from signal-catching functions
(From `man sigaction`)

 Base Interfaces:

     _exit(), access(), alarm(), cfgetispeed(), cfgetospeed(), cfsetispeed(), cfsetospeed(), chdir(), chmod(), chown(), close(), creat(), dup(), dup2(), execle(), execve(), fcntl(), fork(), fpathconf(), fstat(), fsync(), getegid(), geteuid(), getgid(), getgroups(), getpgrp(), getpid(), getppid(), getuid(), kill(), link(), lseek(), mkdir(), mkfifo(), open(), pathconf(), pause(), pipe(), raise(), read(), rename(), rmdir(), setgid(), setpgid(), setsid(), setuid(), sigaction(), sigaddset(), sigdelset(), sigemptyset(), sigfillset(), sigismember(), signal(), sigpending(), sigprocmask(), sigsuspend(), sleep(), stat(), sysconf(), tcdrain(), tcflow(), tcflush(), tcgetattr(), tcgetpgrp(), tcsendbreak(), tcsetattr(), tcsetpgrp(), time(), times(), umask(), uname(), unlink(), utime(), wait(), waitpid(), write().

Realtime Interfaces: aio_error(), sigpause(), aio_return(), aio_suspend(), sem_post(), sigset().

ANSI C Interfaces: strcpy(), strcat(), strncpy(), strncat(), and perhaps some others.

Extension Interfaces: strlcpy(), strlcat().

All functions not in the above lists are considered to be unsafe with respect to signals.  That is to say, the behaviour of such functions when called from a signal handler is undefined.  In general though, signal handlers should do little more than set a flag; most other actions are not safe.