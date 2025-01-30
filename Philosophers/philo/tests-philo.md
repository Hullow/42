# Philosophers - things to test
### KO
### OK

- No must_eat: just keep going
- Seg faults: if interrupted, when dying, 
- When deaths:
	- if simulation stops, deaths at right moment
- leaks: valgrind --leak-check=full 
- Helgrind: possible data races
- drd: possible data races

- `./philo 5 101 50 20` => one philo dies
- `./philo 4 310 200 100` => should die

`./philo 100 800 200 200`

./philo 200 800 200 200


## Potentially problematic
- `./philo 100 1000 200 200 2` causes a philo to DIE after what seems like all the other having eaten...
=> no apparent issue with smaller # philos, like `./philo 10 1000 200 200 2` or with 50
but appears with 80 philos at least
- ./philo 200 1200 200 200 7
1738169177321 182 has died
1738169177321 173 is sleeping
- `./philo 100 75 25 50` causes a death after "75ms without eating"!!!!
- `./philo 200 75 25 50` causes a death after 76ms without eating
- `./philo 200 75 25 50` causes a death after 94ms without eating*
./philo 4 75 75 20make
the `./philo 100 800 200 200` case is really problematic (see txt file): Philosopher 71 eats once, sleep, takes a fork at 402 ms, then dies at 812 ms without having taken a second fork (competition with 70 and 72). 73 is weird too: waits a very long time
- n.b.: with many philos and tight time, like `./philo 100 430 200 200`, delays and thus deaths happen
- `./philo 2 2000 500 20000` => dies and then thinks again
- must_eat doesn't work, e.g. `./philo 2 15000 4000 4000 2` => both continue to eat, or `./philo 3 15000 4000 4000 2` => one dies
	=> seems fixed by adding `done_eating` checker in `checker_routine` to return
- SEGFAULT on VM, commit 7983088c6 (27/1 11h45), with `./philo 5 800 200 200 7`
- SEGFAULT on Linux, commit c2b5365a3338 (26/1 19h50), with `./philo 2 400 250 100`
- `./philo 2 400 200 100` => don't die anymore. Why ????
- `./philo 200 1000 200 200` => mutex unlock error, mutex lock error

### Helgrind/drd
- helgrind `./philo 5 800 200 200 7` => possible data races, look at and try to fix
- `./philo 200 50 50 50` causes "Mutex lock errorlock_fork_mutexes: error locking left fork" or "Mutex destroy error"
- `./philo 15 75 25 50` : causes thread detach error
Philosophers: Thread detach error1737664058691 ms: Philosopher 15 died after spending 75 ms without eating !
Philosophers: Thread detach error1737664058691 ms: A philosopher died – end of simulation
- Mutex lock errors: sometimes happen at the end, e.g. with `./philo 200 1000 200 200` or `./philo 100 600 200 200`
- valgrind --tool=helgrind ./philo 1 1000 200 200


### Dying too early
- `./philo 150 500 200 200 > 150-500-200-200.txt` (6ms too early)
- ./philo 200 420 200 200 > tests/200-420-200-200.txt
- ./philo 80 600 200 200 > tests/80-600-200-200.txt

=> no apparent issue with smaller # philos, like `./philo 10 1000 200 200 2` or with 50
but appears with 80 philos at least

=> went back to 1st push commit, and bug is there :s

other to investigate: `./philo 200 1500 200 200 2 > out.txt && cat out.txt | wc -l`

X is thinking

X has taken a fork
X has taken a fork
X is eating
X is sleeping


X is thinking