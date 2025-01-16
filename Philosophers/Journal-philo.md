# Journal - Philosophers

## 16/1/25
- Readded fork state variable, this time as `unsigned char *forks[MAX_THREADS]`, because
memset adds `int c` to the pointer given as parameter as an unsigned char
- To do:
	- add global death check mutex
	- design general loop (incl. starting order)
	- reorder code in files