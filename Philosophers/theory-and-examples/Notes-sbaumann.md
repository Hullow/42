# Philosophers
Cf. discussion tel Discord 14/1/25

## Input
- Check input: no negative numbers (print out)

		if (!is_only_digits(av[i]))
			return(error_msg(INVALID_INPUT "only give positive numbers as arguments.", 0));
		num = ft_atol(av[i]);
		if (i == 1 && (num <= 0 || num > MAX_PHILO))
			return(error_msg(INVALID_INPUT "<number_of_philosophers> must be between 1 and " MAX_STR_PHILO ".", 0));
		if (i != 1 && num == -1)
			return(error_msg(INVALID_INPUT "integer outside of range 0 - 2147483647 detected.", 0));
- Utilise homemade atol au lieu d'atoi

- Si un philosopher, il faut qu'il meure => il prend une fourchette, puis il meurt parce qu'il en faut 2 pour manger

- check each argument:
```c
int	valid_input(int ac, char **av)
{
	int 	i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (!is_only_digits(av[i]))

```

### Initialization error checking
	if (init_all(ac, av, &table))
	{
		destroy_mutexes(&table);
		free_dynamic_memory(&table);
		return (1);
	}


### Mallocs and set to 0
```c
int	malloc_philosophers(t_table *table)
{
	table->philosophers = malloc(sizeof(t_philosophers) *
		table->number_of_philosophers);	
	if (!table->philosophers)
		return(error_msg(MALLOC_ERR, 1));
	memset(table->philosophers, 0, sizeof(t_philosophers) *
		table->number_of_philosophers);
	return (0);
}
```


forks: create them in table, and then point to them from each philosopher (copy)
```c
static int	init_philosophers(t_table *table)
{
	unsigned int i;

	if (malloc_philosophers(table))
	{
		free(table->philosophers);
		return (1);
	}
	i = 0;
	while (i < table->number_of_philosophers)
	{
		table->philosophers[i].id = i + 1;
		table->philosophers[i].number_of_philosophers = table->number_of_philosophers;
		table->philosophers[i].times_eaten = 0;
		table->philosophers[i].times_must_eat = table->times_must_eat;
		table->philosophers[i].last_meal_time = 0;
		table->philosophers[i].table = table;
		table->philosophers[i].forks = table->forks;
		i++;
	}
	return (0);
}
```

## Extreme parameter values (== 0)
if (philosopher->times_must_eat == 0)
	return (NULL);

if (philosopher->table->time_to_die == 0)
	return (NULL);

## Check if dead or alive
```c
int	dead_or_alive(t_time_ms waiting_time, t_philosophers *philosopher)
{
	t_time_ms start;

	if (grim_reaper(philosopher))
		return (1);
	start = get_time_in_ms();
	while (get_time_in_ms() < (start + waiting_time))
	{
		usleep(MONITOR_INTERVAL);
		if (grim_reaper(philosopher))
			return (1);
	}	
	return (0);
}
```

- Une autre approche: créer thread pour grim reaper



## Fork taking
Pairs prennent d'abord à droite, impairs d'abord à gauche

```c
int	assign_forks(t_philosophers *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		if (grab_a_fork(philosopher, philosopher->id % philosopher->number_of_philosophers) != 0)
			return (1);
		if (grab_a_fork(philosopher, (philosopher->id - 1) % philosopher->number_of_philosophers) != 0)
		{
			pthread_mutex_unlock(&philosopher->forks[philosopher->id % philosopher->number_of_philosophers]);
			return (1);	
		}
```

=> si tu peux pas prendre ta 2e fork, tu dois lacher ta 1ere 

- Plusieurs manières d'éviter deadlock: une est de faire commencer les pairs légèrement avant impairs


## Global stop
memset(&table->stop_mutex, 0, sizeof(pthread_mutex_t));

Remarks:
- usleep at initialization to wait for prints =>
- il mange => non il pense



## Notes to myself
Implement barrier: count how many threads are active, then when that == nb_philo, start