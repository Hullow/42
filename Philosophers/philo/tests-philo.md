# Philosophers - things to test
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
- helgrind `./philo 5 800 200 200 7` => possible data races, look at and try to fix

### Dying too early
- `./philo 150 500 200 200 > 150-500-200-200.txt` (6ms too early)
- ./philo 200 420 200 200 > tests/200-420-200-200.txt
- ./philo 80 600 200 200 > tests/80-600-200-200.txt

=> no apparent issue with smaller # philos, like `./philo 10 1000 200 200 2` or with 50
but appears with 80 philos at least

=> went back to 1st push commit, and bug is there :s

other to investigate: `./philo 200 1500 200 200 2 > out.txt && cat out.txt | wc -l`

9 lines for each philo if must_eat == 2
is thinking
has taken a fork
has taken a fork
is eating
is sleeping
is thinking
has taken a fork
has taken a fork
is eating