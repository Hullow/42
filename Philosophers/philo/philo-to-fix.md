# Post 1st push (28/1/25)

## To remove
- Remove grim_reaper => removes the "all philosophers have eaten" print
	=> also remove the option in print_status

- lock_single_fork_mutex (unused)
- Makefile comment

## To change
- Remove max_threads, replace with malloc based on parameters
- make constants point to t_table instead of filling them in each philo
- Add usleep in philo_routine ?
- remove memset, and unsigned char
- Add define or enum for fork status,
e.g. # define FREE 0 and # define EAT_ENOUGH 1 for use in attempt_to_eat

## Rename
- desired_sleep => desired_time
- check_died in checker_routine: mark_dead
- Is this allowed ?
	- define const char *messages
	
## Next eval:
3 is a good example
5 too


# Maybe change/fix
- dying too early with large numbers, like ./philo 200 800 200 200
- Mutex protection to prevent philo dying and eating at same time ?
- timestamps
