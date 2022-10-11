#include "includes/philo.h"

int main()
{
	int		ret;
	sem_t	*test;

	sem_unlink("/print_sem");
	test =	sem_open("/print_sem", O_CREAT, 0644, 1);
	printf("ret: %d\n", sem_getvalue(test, &ret));
	printf("philo print sem: %d\n\n", ret);
	return (1);
}