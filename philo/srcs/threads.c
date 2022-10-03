/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:21:46 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/04 00:49:13 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_table **table)
{
	int		i;

	i = -1;
	if (pthread_mutex_init(&(*table)->print, NULL))
	{
		print_msg(SYS_ERR, MUTEX_ERR);
		free_table(*table);
		return (ERROR);
	}
	while (++i < (*table)->num)
	{
		if (pthread_mutex_init(&(*table)->mutex[i], NULL))
		{
			print_msg(SYS_ERR, MUTEX_ERR);
			free_table(*table);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	creat_threads(t_table **table)
{
	int		i;

	i = -1;
	(*table)->start_time = get_time();
	while (++i < (*table)->num)
	{
		if (pthread_create(&(*table)->threads[i],
				NULL, life_cycle, &(*table)->philo[i]))
		{
			print_msg(SYS_ERR, THREAD_ERR);
			free_table(*table);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	init_threads(t_table **table)
{
	if (init_mutex(table) == ERROR)
		return (ERROR);
	if (creat_threads(table) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static void	join_threads(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->num)
	{
		if (pthread_join((*table)->threads[i++], NULL))
			print_msg(SYS_ERR, JOIN_ERR);
	}
}

static void	destroy_mutex(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->num)
	{
		if (pthread_mutex_destroy(&(*table)->mutex[i++]))
			print_msg(SYS_ERR, DMUTEX_ERR);
	}
	if (pthread_mutex_destroy(&(*table)->print))
		print_msg(SYS_ERR, DMUTEX_ERR);
}

void	collect_philo(t_table **table)
{
	join_threads(table);
	destroy_mutex(table);
}
