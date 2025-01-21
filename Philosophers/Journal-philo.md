# Journal - Philosophers

## 16/1/25
- Readded fork state variable, this time as `unsigned char *forks[MAX_THREADS]`, because
memset adds `int c` to the pointer given as parameter as an unsigned char (n.b.: 1 byte according to [this page on data types](https://pontus.digipen.edu/~mmead/www/Courses/CS120/DataTypes-1.html), vs 4 bytes for int on 64-bit systems)
- To do:
	- add global death check mutex
	- design general loop (incl. starting order)
	- reorder code in files


P.S.:
- For more understanding:
	- Factorio video
	- https://dextutor.com/program-to-create-deadlock-using-c-in-linux/
	- Maybe watch this: https://www.youtube.com/watch?v=rFYYifVj5gs

# 19/1/25
- Back to work
- Issues:
	- Sleeping for 54 ms instead of 50ms

# 21/1/25
- Philosophers:
	- advancing: wrote the routine loop (`while (1)`), refactored, testing
	- added staggered start for when uneven number of philosophers
- Issues:
	- Tasks still executed too slowly (eating and sleeping for 1-5 ms more than required)
