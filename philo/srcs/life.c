/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:35:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/08 15:23:14 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(int n, int state, pthread_mutex_t *lock, time_t start)
{
	time_t	current;

	pthread_mutex_lock(lock);
	current = time_stamp(start);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo ", 1);
	ft_putnbr_fd(n, 1);
	if (state == 1 || state == 0)
		ft_putstr_fd(" has picked a fork\n", 1);
	else if (state == 2)
		ft_putstr_fd(" is eating\n", 1);
	else if (state == 3)
		ft_putstr_fd(" is sleeping\n", 1);
	else if (state == 4)
		ft_putstr_fd(" is thinking\n", 1);
	pthread_mutex_unlock(lock);
}

int	forkah(t_un *un)
{
	while (1)
	{
		pthread_mutex_lock(un->left_mutex);
		pthread_mutex_lock(un->right_mutex);
		if (!*un->left_fork && !*un->right_fork
			&& *un->left_fork != un->i
			&& *un->right_fork != un->i)
		{
			un->status = 1;
			print_state(un->i, un->status, un->print, *un->start);
			*un->left_fork = un->i;
			*un->right_fork = un->i;
			pthread_mutex_unlock(un->left_mutex);
			pthread_mutex_unlock(un->right_mutex);
			return (1);
		}
		pthread_mutex_unlock(un->left_mutex);
		pthread_mutex_unlock(un->right_mutex);
	}
	return (0);
}

int	eat(t_un *un)
{
	pthread_mutex_lock(un->left_mutex);
	pthread_mutex_lock(un->right_mutex);
	un->status = 2;
	print_state(un->i, un->status, un->print, *un->start);
	mysleep(un->eat);
	*un->left_fork = 0;
	*un->right_fork = 0;
	pthread_mutex_unlock(un->left_mutex);
	pthread_mutex_unlock(un->right_mutex);
	return (1);
}

int	sleepah(t_un *un)
{
	un->status = 3;
	print_state(un->i, un->status, un->print, *un->start);
	mysleep(un->sleep);
	return (1);
}

int	think(t_un *un)
{
	un->status = 4;
	print_state(un->i, un->status, un->print, *un->start);
	return (1);
}
