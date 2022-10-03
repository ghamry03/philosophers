/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:27:47 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/04 01:39:43 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_forks(t_table **table)
{
	int		i;

	i = -1;
	(*table)->forks = (int *)malloc(sizeof(int) * ((*table)->num));
	if (!(*table)->forks)
	{
		free(*table);
		print_msg(SYS_ERR, MALLOC_ERR);
		return (ERROR);
	}
	while (++i < (*table)->num)
		(*table)->forks[i] = -1;
	return (SUCCESS);
}

static	void	init_table_values(t_table **table, char **av)
{
	(*table)->num = ft_atox(av[1]);
	(*table)->eat = ft_atox(av[2]);
	(*table)->death = ft_atox(av[3]);
	(*table)->sleep = ft_atox(av[4]);
	(*table)->check_death = 0;
	if (av[5])
		(*table)->repeat = ft_atox(av[5]);
	else
		(*table)->repeat = -1;
}

static t_table	*init_table_struct(char **av)
{
	t_table		*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	init_table_values(&table, av);
	table->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->num);
	table->threads = (pthread_t *)malloc(sizeof(pthread_t) * table->num);
	if (!table->mutex || !table->threads)
	{
		print_msg(SYS_ERR, MALLOC_ERR);
		if (table->mutex)
			free(table->mutex);
		if (table->threads)
			free(table->threads);
		free(table);
		return (NULL);
	}
	if (init_forks(&table) == ERROR)
		return (NULL);
	return (table);
}

static void	fill_philo_struct(t_table *table, t_philo *philo, int id)
{
	(*philo).id = id;
	(*philo).state = P_FORK;
	(*philo).check_death = &table->check_death;
	(*philo).start_time = &table->start_time;
	(*philo).left_forkn = id;
	(*philo).left_fork = &table->forks[id - 1];
	(*philo).left_mutex = &table->mutex[id - 1];
	if (id == table->num)
	{
		(*philo).left_forkn = 0;
		(*philo).left_fork = &table->forks[0];
	(*philo).left_mutex = &table->mutex[0];
	}
	else
	{
		(*philo).left_forkn = id;
		(*philo).left_fork = &table->forks[id - 1];
		(*philo).left_mutex = &table->mutex[id - 1];
	}
	(*philo).eat = table->eat;
	(*philo).death = table->death;
	(*philo).sleep = table->sleep;
	(*philo).repeat = table->sleep;
	(*philo).last_eat = 0;
	(*philo).print = &table->print;
}

static t_philo	*init_philo_struct(t_table *table)
{
	int			i;
	t_philo		*philo;

	i = -1;
	philo = (t_philo *)malloc(sizeof(t_philo) * (table->num));
	if (!philo)
	{
		free(table);
		print_msg(SYS_ERR, MALLOC_ERR);
		return (NULL);
	}
	while (++i < table->num)
		fill_philo_struct(table, &(philo[i]), i + 1);
	return (philo);
}

t_table	*init_struct(char **av)
{
	t_table	*table;

	table = init_table_struct(av);
	if (!table)
		return (NULL);
	table->philo = init_philo_struct(table);
	if (!table->philo)
	{
		free(table->forks);
		free(table);
		return (NULL);
	}
	return (table);
}
