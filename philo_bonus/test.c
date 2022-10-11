#include "includes/philo.h"

int main()
{
	int		ret;
	sem_t	*test;
	pid_t	pid;

	sem_unlink("/print_sem");
	test =	sem_open("/print_sem", O_CREAT, 0644, 1);
	sem_wait(test);
	pid = fork();
	if (!pid)
	{
		printf("ret: %d\n", sem_post(test));
		printf("in the child\n");
	}
	else
		wait(NULL);
	return (1);
}