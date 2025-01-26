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
- `./philo 4 310 200 100` => should die => but why ???
	=> Re-reading subject: because `last_eaten` is when the philosopher last *started* to eat, not when finished.
	=> Changed that, fixed!

## Done
- timestamp format: from start of program
- Added death checker thread
- Added wrapper on printf (`print_status`) to check global_death_status before printing (<* Rude-jes)
- edge cases:
	- time_to_eat > time_to_die => must die !!
		=> already works (Also with time_to_sleep)
	
## To do:
	- the `./philo 100 800 200 200` case is really problematic (see txt file): Philosopher 71 eats once, sleep, takes a fork at 402 ms, then dies at 812 ms without having taken a second fork (competition with 70 and 72). 73 is weird too: waits a very long time
		=> let's try taking two forks at same time, letting go otherwise. First,
		 need to implement helper function to take fork
		
		update: => actually, the problem only appears when get_time_stamp is used with start_time 
	- implement must_eat
		- input == 1 philo
		- input checking
	- ending simulation :
		- `grim_reaper`'s role:
			- seems to help, but unclear why
			- it's a `while(1)` in main that breaks if a death_status != 0
				=> after checking with pthread_self, it's run by the main thread only, while others are busy with their respective thread routines
			- if put at the end of run_simulation, doesn't stop the simulation after a death (!)
				=> unclear why. In main, it's right after run_simulation returns
		- end it cleanly (locking what are likely destroyed mutexes, etc.)
	- Correct the mutex(...)errors that occur sometimes, e.g. with `./philo 16 100 50 20`

## Issues solved:
- some take forks after dying, everything doesn't stop after one dies
	=> looks fixed, need to check more
- Rudejes:
	- idée: wrapper sur printf (si mort -> set variable à -> si variable est set à X, alors ne pas print)
		=> done

## Issues remaining:
- n.b.: with many philos and tight time, like `./philo 100 430 200 200`, delays and thus deaths happen
- Rudejes:
	- thinking: pas obligatoire mais algo qui sleep pendant le temps minimum de think (calculer ça), peut éviter de clog le système
	- perf sur M1 >> perf sur Mac école. Bien tester
	- philo visualizer: faire output épuré, et paste sur le site https://nafuka11.github.io/philosophers-visualizer/
	
# 25/1/25
- Changed get_time_stamp() back to basic version, solves the wrongly dying philosophers (e.g. with `./philo 100 800 200 200`)
- Must_eat: added shared finished_eating variable, which is incremented by 1 each time a philosopher reaches
the must_eat value. Wrote `edit_status_var` function to increments its' and death_status' (renamed) value by 1 (this replaces handle_philo_death).
	=> All this is to be used by grim_reaper function or other to stop the simulation when `finished_eating == nb_philo`. => not done yet.
	Update: seems to work. Will use debugger to see the exact behavior
- Mutex lock errors: sometimes happen at the end, e.g. with `./philo 200 1000 200 200` or `./philo 100 600 200 200`
- Single philo: implemented to eat with one fork, but that's mistake. There should be only one fork, and the philo should die. Works with `./philo 1 800 200 200`, but mutex_destroy_error => not clear why, because `end_simulation` which

- Doing preparation eval: it seems everything is okay. However, it remains to be checked if there's a mutex to prevent a philosopher from dying and starting eating at the same time. That 


# Tests:
## Clear failures
- `./philo 200 1000 200 200` => mutex unlock error, mutex lock error
- `valgrind --tool=helgrind ./philo 1 1000 200 200`
	=> 
	=> 
	=> thread #1 (root thread):
		- call to pthread_join failed with error 3 (no such process) (end_simulation)
		- unlocked an invalid lock (end_simulation 92, 95)
	=> #thread #2 (philo thread):
		- attempt to re-lock a non-recursive lock I already hold (lock_fork_mutexes called twice at forks.c lines 42 and 48)
		- exiting thread still holds 1 lock
		lock_fork_mutexes; fork:48
	=> #thread #3 (checker thread):

possible data race during read of size 4

## Of note
- `./philo 200 1000 200 200` => a philo dies, but not with `./philo 200 1500 200 200`
- `valgrind --tool=helgrind ./philo X 1000 200 200` => possible data race during read of size 4
- `valgrind --tool=helgrind ./philo 1 1000 200 200`
	
 
# 26/1/25
- Testing with valgrind --tool=helgrind
- Added lock ordering to avoid possible deadlocks