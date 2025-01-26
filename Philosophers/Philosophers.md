# Philosophers - project notes

## Program components outline
### Philosopher initialization
- Each philosopher is a thread with a number ranging from 1 to nb_philos
	=> ?

	- pthread_t	tid;
	- int	id;
	- int	*ptr; /* or structure with thread_id, id, last_eaten, */

	- pthread_create(&tid, NULL, philo_routine, (void *)ptr);
	- if (pthread_detach(tid))
		error(detach_error);

```c
int
	pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```
> DESCRIPTION
>
> The pthread_create() function is used to create a new thread, with attributes specified by attr, within a process.  If attr is NULL, the default attributes are used. If the attributes specified by attr are modified later, the thread's attributes are not affected. Upon successful completion pthread_create() will store the ID of the created thread in the location specified by thread.<br><br>
> The thread is created executing `start_routine` with arg as its sole argument. If the `start_routine` returns, the effect is as if there was an implicit call to `pthread_exit()` using the return value of `start_routine` as the exit status. Note that the thread in which `main()` was originally invoked differs from this. When it returns from main(), the effect is as if there was an implicit call to `exit()` using the return value of `main()` as the exit status.<br><br>
> Upon thread exit the storage for the thread must be reclaimed by another thread via a call to `pthread_join()`. Alternatively, `pthread_detach()` may be called on the thread to indicate that the system may automatically reclaim the thread storage upon exit. The `pthread_attr_setdetachstate()` function may be used on the attr argument passed to `pthread_create()` in order to achieve the same effect as a call to `pthread_detach()` on the newly created thread.<br><br>

>     The signal state of the new thread is initialized as:
>    •   The signal mask is inherited from the creating thread.
>    •   The set of signals pending for the new thread is empty.

>RETURN VALUES
>     If successful, the pthread_create() function will return zero. Otherwise an error number will be returned to indicate the error.

	and philosopher n sits between n - 1 and philosopher n + 1
		=> ?

	set last_eaten = 0
		=> ?

### Forks initialization
#### Fork numbering
- Number of forks = number of philosophers
fork numbers:

philosopher X:
- left hand: (X - 1) % n (if 0, 0 % n = 0)
- right hand: X % n (if n, n % n = 0)

e.g. if n = 2,
X = 1: left hand is 0 % 2 == 0, right hand 1 % 2 == 1
X = 2: left hand is 1 % 2 == 1, right hand is 2 % 2 == 0

n.b. if n = 1: left hand is 0 % 1 == 0, right hand is 1 % 1 == 0

#### Fork and philosopher selection per eating round
	even vs uneven number of philosophers: 
	who takes turns eating to avoid forks conflicts?
	
	even example:
		f0 | f1 | f2 | f3 | f0
		  p1 	p2	 p3	  p4

	we start with:
		philo #1: f0-f1, philo #3: f2-f3
	then:
		philo #2: f1-f2, philo #4: f3-f0
	then:
		(repeat)


uneven example:
	f0 | f1 | f2 | f3 | f4 | f0
		p1	p2	 p3	  p4   p5

	we start with:
		philo #1: f0-f1, philo #3: f2-f3
	then:
		philo #2: f1-f2, philo #4: f3-f4
	then:
		philo #5: f4-f0, philo #3: f2-f3
	then:
		(repeat)

uneven example 2:
	f0 | f1 | f2 | f3 | f4 | f5 | f6 | f0
		p1	p2	 p3	  p4   p5	p6	 p7
	
	we start with:
		philo #1: f0-f1, philo #3: f2-f3, philo #5: f4-f5
	then:
		philo #2: f1-f2, philo #4: f3-f4, philo #6: f5-f6
	then:
		philo#7: f6-f0, philo #5: f4-f5, philo #3: f2-f3
	then:
		(repeat)

if uneven number of philosophers, alternate between:
	- even numbered philosophers are all the even numbered philos 
	- all uneven numbered philosophers except last philosopher
	- all uneven numbered philosophers except first philosopher

=> in practice, initialize all forks at value '0', then select philosophers to start eating

#### Fork protection with mutexes
- Protect forks state with a mutex to prevent philosophers (threads) from duplicating them
(n.b.: one on left-side, one on right-side)
	pthread_mutex_t		fork_mutex;
	if (pthread_mutex_init(&fork_mutex, NULL))
		print_error(mutex_init_error);

### Philosopher routine
```c
void	*philo_thread_routine(void *vargp)
{
	free(vargp);

	if (check_if_philo_alive)
	{
		/* modify some heap variable that is continuously checked by main thread */
		return (NULL);
	}
}
```

	- print state change: is thinking
	- attempt to eat by getting hold of two forks:
		- pthread_mutex_lock(left_fork)
		- print state change(has taken a fork)
		- pthread_mutex_lock(right_fork)
		- print state change(has taken a fork)
	- print state change(is eating)
	- eating for time_to_eat: usleep(time_to_eat)
	- put down two forks: pthread_mutex_unlock(left_fork), pthread_mutex_unlock(right_fork)
	- updated times_eaten and check against nb_times_philo_must_eat
		if ==, set has eaten enough
	- print state change: is sleeping
	- sleeping for time_to_sleep: usleep(time_to_sleep)
	- print state change: is thinking

N.b.: The `pthread_mutex_lock()` function locks mutex. If the mutex is already locked, the calling thread will block until the mutex becomes available.

- utils:
	- print_state_change: print(gettimeofday, X, CURRENT_STATE) nb sforster: printing needs mutex to execute correctly
	- check if alive: run it from main thread ?
	if (gettime - last_time_philosopher_eat > time_to_die)
		- pthread_join(tid)
		- print state change: has died
		- program stop
	- sleeping the correct time


- ending program:
	pthread_mutex_destroy
	pthread_join ?


- mutexes:
	- when printing
	- when reading (because it can be written to at the same time)

- other:
	- check fork value rather than relying only on mutex_init to prevent risk of deadlock
	- "global" variable that marks whether a philo has died or not

```c
int     pthread_join(pthread_t thread, void **value_ptr);
```

DESCRIPTION
     The `pthread_join()` function suspends execution of the calling thread until the target thread terminates unless the target thread has already terminated.

     On return from a successful pthread_join() call with a non-NULL value_ptr argument, the value passed to pthread_exit() by the terminating thread is stored in the location referenced by value_ptr.  When a pthread_join() returns successfully, the target thread has been terminated.  The results of multiple simultaneous calls to pthread_join() specifying the same target thread are undefined.  If the thread calling pthread_join() is cancelled, then the target thread is not detached.

RETURN VALUES
     If successful, the pthread_join() function will return zero.  Otherwise, an error number will be returned to indicate the error.

ERRORS
     The pthread_join() function will fail if:

     [EINVAL]           The implementation has detected that the value specified by thread does not refer to a joinable thread.

     [ESRCH]            No thread could be found corresponding to that specified by the given thread ID, thread.

     [EDEADLK]          A deadlock was detected or the value of thread specifies the calling thread.



## Simplified program
- Philosophers take steps eating, one by one