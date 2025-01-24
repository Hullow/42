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

# 22/1/25
- Working on a more precise sleep function (for eating or sleeping); more precise than usleep

# 23/1/25
- More precise sleep function (for eating or sleeping) => made some progress, than got what seemed like a deadlock. Solved by adding a usleep(50) after unlocking mutex in case fork is taken. It works with tight cases like `./philo 4 75 50 25`
- Remaining issues:
	- death case(s): death detected but simulation not ended properly (e.g. `./philo 4 75 75 25`)
 		=> use detach for that (cf. trgoel)
			=> fixed
	- check uneven philos
	- check edge cases: single philo, 0 philos
(later)
- rewrote input validity checker (to be finished)
- added global death checker for each philo, but unclear if need to use detach, since we return, which 
exits threads, then the main reaps the threads, then returns 0

=> seems like pthread_detach could be called from each thread, which allows the system to reclaim memory when that thread ends
- Slightly different behavior (from print output) whether threads are reaped in main with `pthread_join`, not reaped, detached but reaped, ..
- Added timestamp for death declaration in main
- Maybe change memset to add the # of the philosopher who died (unsigned char < 256, nb_philo <= 200), to print it in main
- With prints, death seems to be detected very fast by the main thread (same ms as it happens)
- Atoi fix `./philo 4 75 75 20make` worked when it shouldn't => fixed. Remark: thought of implementing ft_atoi to return a long instead of int, but gave up because of complexity. Need to check before correcting


- Errors:
	- `./philo 100 75 25 50` causes a death after "75ms without eating"!!!!
	- `./philo 200 75 25 50` causes a death after 76ms without eating
	- `./philo 200 75 25 50` causes a death after 94ms without eating*
	- `./philo 200 50 50 50` causes "Mutex lock errorlock_fork_mutexes: error locking left fork" or "Mutex destroy error"

*: `./philo 100 75 25 50` => everything wrong!
1737657675320 ms: Philosopher 24 is sleeping
1737657675370 ms: Philosopher 24 is thinking
1737657675370 ms: Philosopher 24 is eating   (left fork 23, right fork 24)
1737657675398 ms: Philosopher 24 is sleeping
1737657675451 ms: Philosopher 24 is thinking
1737657675452 ms: Philosopher 24 is eating   (left fork 23, right fork 24)
1737657675477 ms: Philosopher 24 is sleeping
1737657675571 ms: Philosopher 24 is thinking
1737657675571 ms: Philosopher 24 died after spending 94 ms without eating !

other trial of `./philo 100 75 25 50` => print error. Maybe use ft_putstr_fd ?
1737658101144 ms: Philosopher 32 is thi1737658101169 ms: Philo 34 marked dead

	- `./philo 15 75 25 50` : causes thread detach error
	Philosophers: Thread detach error1737664058691 ms: Philosopher 15 died after spending 75 ms without eating !
	Philosophers: Thread detach error1737664058691 ms: A philosopher died – end of simulation

- `./philo 50 75 25 50`
Selection:
1737664796747 ms: Philosopher 1 is thinking   (waiting for left fork 0, right fork 1)
1737664796747 ms: Philosopher 1  is eating   (left fork 0, right fork 1)
1737664796772 ms: Philosopher 1  is sleeping
1737664796822 ms: Philosopher 1 is thinking   (waiting for left fork 0, right fork 1)
1737664796822 ms: Philosopher 1  is eating   (left fork 0, right fork 1)
1737664796847 ms: Philosopher 1  is sleeping
(...)
Full end: 
1737664796901 ms: Philosopher 33 is thinking   (waiting for left fork 32, right fork 33)
1737664796901 ms: Philosopher 33  is eating   (left fork 32, right fork 33)
1737664796907 ms: Philosopher 19 is thinking   (waiting for left fork 18, right fork 19)
1737664796907 ms: Philosopher 19  is eating   (left fork 18, right fork 19)
1737664796907 ms: Philosopher 1 is thinking   (waiting for left fork 0, right fork 1)
1737664796923 ms: Philosopher 1 died after spending 76 ms without eating !
1737664796924 ms: Philosopher 1 marked dead
1737664796910 ms: Philosopher 31 is thinking   (waiting for left fork 30, right fork 31)
1737664796924 ms: A philosopher died – end of simulation

Uneven nb_philo – alternating sequence should look like: 
- nb_philo = 5:
3 5

4 2

1

3 5

4 2

1


To do:
- Think through detach, what happens and why
- Fork taking: correct method ?
- Check uneven philos
- Check if must_eat works
- Re-read subject
- Think of edge cases, write my own tests
- Error handling + leaks
- Norm
- Redo tests
- Mock evals

Correction checks:
- \> INT_MAX or \< INT_MIN inputs
- ./philo 5 100 50 X => one should die no ? given that two rounds wof eating happen without them (round 1: 50ms, round 2: 50ms => 100ms have passed, you die)
> `time_to_die` (in milliseconds):<br>
> If a philosopher didn’t start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

0ms: start
100ms: philosopher will start to eat hasn't started to eat
=> dies

# 24/1/25
- Worked on uneven numbers
- Implemented individual fork taking
- `./philo 5 101 50 20` => one philo dies