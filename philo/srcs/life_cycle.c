/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/04 01:42:06 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_fork(t_philo *philo, pthread_mutex_t *lock, int f)
{
	int		*fork;
	int		forkn;
	int		ret;

	pthread_mutex_lock(lock);
	if (!f)
	{
		fork = philo->left_fork;
		forkn = philo->left_forkn;
	}
	else
	{
		fork = philo->right_fork;
		forkn = philo->right_forkn;
	}
	if (!*fork || (*fork == -1 && philo->id % 2 != 0))
	{
		*fork = philo->id;
		ret = print_state(philo, forkn);
	}
	else
		ret = ERROR;
	pthread_mutex_unlock(lock);
	return (ret);
}

static int	forks(t_philo *philo)
{
	int			ret;
	int			fork_check;
	static int	flag = 0;

	fork_check = 0;
	philo->state = THINK;
	while (fork_check < 2)
	{
		if (flag == 0)
		{
			philo->last_eat = get_time();
			flag = 1;
		}
		ret = check_fork(philo, philo->left_mutex, 0);
		if (ret == SUCCESS)
			fork_check++;
		else if (ret == DEAD)
			return (DEAD);
		check_fork(philo, philo->right_mutex, 1);
		if (ret == SUCCESS)
			fork_check++;
		else if (ret == DEAD)
			return (DEAD);
	}
	return (SUCCESS);
}

static int	eat(t_philo *philo)
{
	int		ret;

	philo->state = EAT;
	ret = print_state(philo, -1);
	mysleep(philo->eat);
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = 0;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = 0;
	pthread_mutex_unlock(philo->right_mutex);
	philo->last_eat = get_time();
	return (ret);
}

static int	sleeep(t_philo *philo)
{
	int		ret;

	philo->state = SLEEP;
	ret = print_state(philo, -1);
	mysleep(philo->sleep);
	return (ret);
}

static int	think(t_philo *philo)
{
	int		ret;

	philo->state = 4;
	ret = print_state(philo, -1);
	return (ret);
}

void	*life_cycle(void *p)
{
	ssize_t		counter;
	t_philo		*philo;

	counter = 0;
	philo = (t_philo *)p;
	while (*philo->check_death != DEAD)
	{
		if (philo->state == P_FORK)
			forks(philo);
		if (philo->state == EAT && counter++)
			eat(philo);
		if (philo->state == SLEEP)
			sleeep(philo);
		if (philo->state == THINK)
			think(philo);
		if (counter != -1 && counter == philo->repeat)
			break ;
	}
	return (NULL);
}
