/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:56:15 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/24 15:18:29 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_threads(t_table **table)
{
	int		i;
	int		num;

	num = (*table)->num;
	(*table)->threads = (pthread_t *)malloc(sizeof(pthread_t) * num);
	i = 0;
	(*table)->start = get_time();
	while (i < num)
	{
		if (pthread_create(&(*table)->threads[i],
				NULL, &cycle_of_life, &(*table)->philo[i]))
		{
			ft_putstr_fd("philo: error: creating thread failed\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	join_threads(t_table **philo)
{
	int		i;
	int		num;

	num = (*philo)->num;
	i = 0;
	while (i < num)
	{
		if (pthread_join((*philo)->threads[i++], NULL))
		{
			ft_putstr_fd("philo: error: failed to join thread\n", 2);
			return (0);
		}
	}
	return (1);
}

int	init_mutex(t_table **philo)
{
	int		i;
	int		num;

	num = (*philo)->num;
	(*philo)->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!(*philo)->mutex)
		return (0);
	i = 0;
	while (i < num)
	{
		(*philo)->i = (int *)malloc(sizeof(int));
		*(*philo)->i = i;
		if (pthread_mutex_init(&(*philo)->mutex[i++], NULL))
		{
			ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
			return (0);
		}
	}
	if (pthread_mutex_init(&(*philo)->print, NULL))
	{
		ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
		return (0);
	}
	return (1);
}

int	destroy_mutex(t_table **philo)
{
	int		i;
	int		num;

	i = 0;
	num = (*philo)->num;
	while (i < num)
	{
		if (pthread_mutex_destroy(&(*philo)->mutex[i++]))
		{
			ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
			return (0);
		}
	}
	if (pthread_mutex_destroy(&(*philo)->print))
	{
		ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
		return (0);
	}
	return (1);
}
