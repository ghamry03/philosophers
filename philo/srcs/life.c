/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:35:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/06 16:52:35 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_state(int n, int state)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	ft_putnbr_fd(time.tv_sec, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(time.tv_usec, 1);
	ft_putstr_fd(": philo ", 1);
	ft_putnbr_fd(n + 1, 1);
	if (state == 1 || state == 0)
		ft_putstr_fd(" picked a fork\n", 1);
	else if (state == 2)
		ft_putstr_fd(" is eating\n", 1);
	else if (state == 3)
		ft_putstr_fd(" is sleeping\n", 1);
	else if (state == 4)
		ft_putstr_fd(" is thinking\n", 1);
}

int	forkah(t_un **un)
{
	while (1)
	{
		if (!(*un)->fork[0] && !(*un)->fork[1])
		{
			pthread_mutex_lock(&(*un)->mutex[0]);
			(*un)->fork[0] = 1;
			pthread_mutex_unlock(&(*un)->mutex[0]);
			pthread_mutex_lock(&(*un)->mutex[1]);
			(*un)->fork[1] = 1;
			pthread_mutex_unlock(&(*un)->mutex[1]);
			pthread_mutex_lock((*un)->print);
			print_state((*un)->i, (*un)->status);
			pthread_mutex_unlock((*un)->print);
			(*un)->status = 1;
			return (1);
		}
	}
	return (0);
}

int	eat(t_un **un)
{
	pthread_mutex_lock(&(*un)->mutex[0]);
	(*un)->fork[0] = 0;
	pthread_mutex_unlock(&(*un)->mutex[0]);
	pthread_mutex_lock(&(*un)->mutex[1]);
	(*un)->fork[1] = 0;
	pthread_mutex_unlock(&(*un)->mutex[1]);
	pthread_mutex_lock((*un)->print);
	print_state((*un)->i, (*un)->status);
	pthread_mutex_unlock((*un)->print);
	usleep((*un)->eat);
	(*un)->status = 2;
	return (1);
}

int	sleepah(t_un **un)
{
	usleep((*un)->sleep);
	pthread_mutex_lock((*un)->print);
	print_state((*un)->i, (*un)->status);
	pthread_mutex_unlock((*un)->print);
	(*un)->status = 3;
	return (1);
}

int	think(t_un **un)
{
	pthread_mutex_lock((*un)->print);
	print_state((*un)->i, (*un)->status);
	pthread_mutex_unlock((*un)->print);
	(*un)->status = 4;
	return (1);
}
