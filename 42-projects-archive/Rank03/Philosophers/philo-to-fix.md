# Post 1st push (28/1/25) - Changes and checks to make

## To remove
### done
- Remove grim_reaper => removes the "all philosophers have eaten" print
	=> also remove the option in print_status => kept, moved call to checker
- lock_single_fork_mutex (unused)
- Makefile comment

## To change
- make constants point to t_table instead of filling them in each philo
- Add usleep in philo_routine ?

### done
- Remove max_threads, replace with malloc based on parameters
- Add define or enum for fork status,
e.g. # define FREE 0 and # define EAT_ENOUGH 1 for use in attempt_to_eat

## Is this allowed ?
	- define const char *messages with initialization

## Rename
- check_died in checker_routine: mark_dead => don't
### done
- desired_sleep => desired_time

# Maybe change/fix
- dying too early with large numbers, like ./philo 200 800 200 200
- Mutex protection to prevent philo dying and eating at same time ?
- timestamps
- remove memset, and unsigned char

	
## Next eval:
3 is a good example
5 too

## Discussion Mguyot
### To check
- Mutex sur les print (print_mutex)

### To do
- print_status: put simulkation stop in each printf + mutex