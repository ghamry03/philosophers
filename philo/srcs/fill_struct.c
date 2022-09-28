/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:26:21 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/25 20:54:31 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	fill_struct(char **av, t_table **table)
{
	int		i;

	i = -1;
	(*table)->num = ft_atox(av[1]);
	(*table)->death = ft_atox(av[2]);
	(*table)->check_death = 0; 
	(*table)->eat = ft_atox(av[3]);
	(*table)->sleep = ft_atox(av[4]);
	if (av[5])
		(*table)->repeat = ft_atox(av[5]);
	else
		(*table)->repeat = 0;
	(*table)->fork = (int *)malloc(sizeof(int) * (*table)->num);
	if (!(*table)->fork)
		return (0);
	while (++i < (*table)->num)
		(*table)->fork[i] = -1;
	return (1);
}

static int	fill_philo(t_table **table, int i)
{
	(*table)->philo[i].i = i + 1;
	(*table)->philo[i].state = 4;
	(*table)->philo[i].start = &(*table)->start;
	(*table)->philo[i].death = (*table)->death;
	(*table)->philo[i].check_death = &(*table)->check_death;
	(*table)->philo[i].eat = (*table)->eat;
	(*table)->philo[i].sleep = (*table)->sleep;
	(*table)->philo[i].repeat = (*table)->repeat;
	(*table)->philo[i].left_mutex = &(*table)->mutex[i];
	(*table)->philo[i].death_l = &(*table)->death_l;
	(*table)->philo[i].print = &(*table)->print;
	(*table)->philo[i].left_fork = &(*table)->fork[i];
	(*table)->philo[i].left_forkn = i + 1;
	if (i == (*table)->num - 1)
	{
		(*table)->philo[i].right_fork = &(*table)->fork[0];
		(*table)->philo[i].right_mutex = &(*table)->mutex[0];
		(*table)->philo[i].right_forkn = 1;
	}
	else
	{
		(*table)->philo[i].right_fork = &(*table)->fork[i + 1];
		(*table)->philo[i].right_mutex = &(*table)->mutex[i + 1];
		(*table)->philo[i].right_forkn = i + 2;
	}
	return (1);
}

int	philo_struct(t_table **table)
{
	int		i;
	int		num;

	i = 0;
	num = (*table)->num;
	(*table)->start = -1;
	if (!(*table)->start)
		return (0);
	(*table)->philo = (t_philo *)malloc(sizeof(t_philo) * num);
	if (!(*table)->philo)
		return (0);
	while (i < num)
	{
		if (!fill_philo(table, i))
			return (0);
		i++;
	}
	return (1);
}
