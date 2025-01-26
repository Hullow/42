- getpid() to get the PID of the calling process => OK
- kill(PID, sig) to send a signal to the process => OK
- check if kill sent the signal with return value (0 if success, -1 otherwise + errno) => OK

- The client takes the PID of the server as a parameter: how to do this ?

To do:
- define specific signals to send