/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:35:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/27 20:22:35 by ommohame         ###   ########.fr       */
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
	if (!*fork || (*fork == -1 && philo->i % 2 != 0))
	{
		*fork = philo->i;
		print_state(philo, forkn);
		ret = 1;
	}
	else
		ret = 0;
	pthread_mutex_unlock(lock);
	return (ret);
}

int	forkah(t_philo *philo)
{
	int		fork_check;

	fork_check = 0;
	philo->state = 1;
	while (fork_check < 2)
	{
		if (fork_check == 0)
			philo->last_eat = get_time();
		if (*philo->check_death || check_death(philo))
			return (0);
		if (check_fork(philo, philo->left_mutex, 0))
			fork_check++;
		if (*philo->check_death || check_death(philo))
			return (0);
		if (check_fork(philo, philo->right_mutex, 1))
			fork_check++;
	}
	return (1);
}

int	eat(t_philo *philo)
{	
	philo->state = 2;
	print_state(philo, -1);
	mysleep(philo->eat);
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = 0;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = 0;
	pthread_mutex_unlock(philo->right_mutex);
	if (*philo->check_death || check_death(philo))
		return (0);
	philo->last_eat = get_time();
	return (1);
}

int	sleepah(t_philo *philo)
{
	philo->state = 3;
	if (*philo->check_death || check_death(philo))
		return (0);
	print_state(philo, -1);
	mysleep(philo->sleep);
	return (1);
}

int	think(t_philo *philo)
{
	philo->state = 4;
	if (*philo->check_death || check_death(philo))
		return (0);
	print_state(philo, -1);
	return (1);
}
