/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:56:15 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/25 20:54:41 by ommohame         ###   ########.fr       */
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

int	join_threads(t_table **table)
{
	int		i;
	int		num;

	num = (*table)->num;
	i = 0;
	while (i < num)
	{
		if (pthread_join((*table)->threads[i++], NULL))
		{
			ft_putstr_fd("philo: error: failed to join thread\n", 2);
			return (0);
		}
	}
	return (1);
}

int	init_mutex(t_table **table)
{
	int		i;
	int		num;

	num = (*table)->num;
	(*table)->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!(*table)->mutex)
		return (0);
	i = 0;
	while (i < num)
	{
		(*table)->i = (int *)malloc(sizeof(int));
		*(*table)->i = i;
		if (pthread_mutex_init(&(*table)->mutex[i++], NULL))
		{
			ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
			return (0);
		}
	}
	if (pthread_mutex_init(&(*table)->print, NULL)
		|| pthread_mutex_init(&(*table)->death_l, NULL))
	{
		ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
		return (0);
	}
	return (1);
}

int	destroy_mutex(t_table **table)
{
	int		i;
	int		num;

	i = 0;
	num = (*table)->num;
	while (i < num)
	{
		if (pthread_mutex_destroy(&(*table)->mutex[i++]))
		{
			ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
			return (0);
		}
	}
	if (pthread_mutex_destroy(&(*table)->print)
		|| pthread_mutex_destroy(&(*table)->death_l))
	{
		ft_putstr_fd("philo: error: creating a new mutex failed\n", 2);
		return (0);
	}
	return (1);
}
