#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_deposit
{
	pthread_mutex_t	mutex;
	int				deposit;
	int				balance;
};

int	read_balance(int balance)
{
	usleep(250000);
	return balance;
}

void	write_balance(struct s_deposit dep, int new_balance)
{
	usleep(250000);
	dep.balance = new_balance;
}

void	*deposit(void *deposit_struct);

int main()
{
	struct s_deposit dep;
	dep.balance = 0;
	int before = read_balance(dep.balance);
	printf("Before: %d\n", before);

	// write_balance(dep, balance);
	pthread_mutex_init(&dep.mutex, NULL);

	pthread_t thread1;
	pthread_t thread2;

	int deposit1 = 200;
	// int deposit2 = 300;
	dep.deposit = deposit1;
	printf("first deposit: %d\n", dep.deposit);

	pthread_create(&thread1, NULL, deposit, &dep);

	// dep.deposit = deposit2;
	printf("second deposit: %d\n", dep.deposit);
	pthread_create(&thread2, NULL, deposit, &dep);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&dep.mutex);

	int after = read_balance(dep.balance);
	printf("After: %d\n", after);

	return 0;
}

void	*deposit(void *deposit_struct)
{
	struct s_deposit *dep = (struct s_deposit *) deposit_struct;

	pthread_mutex_lock(&dep->mutex);

	printf("current balance: %d – next deposit: %d\n", dep->balance, dep->deposit);
	dep->balance += dep->deposit;
	dep->deposit += 100;
	pthread_mutex_unlock(&dep->mutex);

	return NULL;
}
