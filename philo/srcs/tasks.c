/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:18:00 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/11 13:02:56 by ommohame         ###   ########.fr       */
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
	if ((*fork == FREE && *fork != -1)
		|| (*fork == -1 && philo->id % 2 != 0))
	{
			*fork = USED;
			ret = print_state(philo, forkn);
	}
	else
		ret = ERROR;
	pthread_mutex_unlock(lock);
	return (ret);
}

static void	which_fork(t_philo *philo, int *side, pthread_mutex_t **lock, int f)
{
	if (f == 0)
	{
		if (philo->id % 2 == 0)
		{
			*side = LEFT;
			*lock = philo->left_mutex;
		}
		else
		{
			*side = RIGHT;
			*lock = philo->right_mutex;
		}
		return ;
	}
	if (philo->id % 2 == 0)
	{
		*side = RIGHT;
		*lock = philo->right_mutex;
	}
	else
	{
		*side = LEFT;
		*lock = philo->left_mutex;
	}
}

int	forks(t_philo *philo)
{
	int				ret;
	int				side;
	int				fork_check;
	pthread_mutex_t	*lock;

	fork_check = 0;
	which_fork(philo, &side, &lock, fork_check);
	while (fork_check < 2)
	{
		if (philo->neat == 0 && fork_check == 0)
			philo->last_eat = get_time();
		ret = check_fork(philo, lock, side);
		if (ret == SUCCESS)
		{
			fork_check++;
			which_fork(philo, &side, &lock, fork_check);
		}
		else if (ret == DEAD)
			return (DEAD);
		if (print_state(philo, DEAD) == DEAD)
			return (DEAD);
	}
	philo->state = EAT;
	return (SUCCESS);
}

int	eat(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	if (ret == DEAD)
		return (DEAD);
	if (mysleep(philo, philo->info->t_eat))
		ret = DEAD;
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = FREE;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = FREE;
	pthread_mutex_unlock(philo->right_mutex);
	philo->last_eat = get_time();
	philo->neat++;
	philo->state = SLEEP;
	return (ret);
}

int	sleeep(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	if (ret == DEAD)
		return (DEAD);
	if (mysleep(philo, philo->info->t_sleep) == DEAD)
		return (DEAD);
	ret = print_state(philo, DEAD);
	philo->state = THINK;
	return (ret);
}

int	think(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	philo->state = P_FORK;
	return (ret);
}
