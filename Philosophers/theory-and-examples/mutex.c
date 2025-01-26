#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_mutex
{
	pthread_mutex_t	*mutex1;
	pthread_mutex_t	*mutex2;
	int				variable;
};

void	*thread_routine_1(void *vargp);

int main()
{
	pthread_t		thread1;
	// pthread_t		*thread2;
	pthread_mutex_t	*mutex1;
	// pthread_mutex_t	mutex2;
	struct s_mutex	*mut;
	int				variable = 0;

	mutex1 = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t));
	mut = (struct s_mutex *) malloc (sizeof(struct s_mutex));
	pthread_mutex_init(mutex1, NULL);
	// pthread_mutex_init(&mutex2, NULL);

	mut->mutex1 = mutex1;
	// mut->mutex2 = &mutex2;
	mut->variable = variable;

	write(2, "Seg check 1\n", 13);
	pthread_create(&thread1, NULL, thread_routine_1, (void *) mut);
	write(2, "Seg check 2\n", 13);
	// pthread_create(thread2, NULL, thread_routine_2, mut);
	// printf("mut->variable: %d - variable: %d\n", mut->variable, variable);
	return (0);
}

void	*thread_routine_1(void *vargp)
{
	write(2, "Seg check 3\n", 13);
	int integer = -1;
	struct s_mutex	*mutex = (struct s_mutex *) vargp;

	write(2, "Seg check 4\n", 13);
	// pthread_mutex_lock(mut->mutex1);
	// variable = 1;
	// pthread_mutex_unlock(mut->mutex1);
	(void)mutex;
	(void)integer;
	// sleep(1);
	return (NULL);
}
