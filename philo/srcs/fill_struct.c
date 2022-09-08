/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:26:21 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/08 15:08:38 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	fill_struct(char **av, t_philo **philo)
{
	(*philo)->num = ft_atox(av[1]);
	(*philo)->death = ft_atox(av[2]);
	(*philo)->eat = ft_atox(av[3]);
	(*philo)->sleep = ft_atox(av[4]);
	if (av[5])
		(*philo)->repeat = ft_atox(av[5]);
	else
		(*philo)->repeat = 0;
	(*philo)->fork = (int *)malloc(sizeof(int) * ft_atox(av[1]));
	if (!(*philo)->fork)
		return (0);
	return (1);
}

static int	fill_un(t_philo **philo, int i)
{
	(*philo)->un[i].i = i + 1;
	(*philo)->un[i].status = 4;
	(*philo)->un[i].left_fork = &(*philo)->fork[i];
	(*philo)->un[i].start = &(*philo)->start;
	if (i == (*philo)->num - 1)
		(*philo)->un[i].right_fork = &(*philo)->fork[0];
	else
		(*philo)->un[i].right_fork = &(*philo)->fork[i + 1];
	(*philo)->un[i].death = (*philo)->death;
	(*philo)->un[i].eat = (*philo)->eat;
	(*philo)->un[i].sleep = (*philo)->sleep;
	(*philo)->un[i].repeat = (*philo)->repeat;
	(*philo)->un[i].left_mutex = &(*philo)->mutex[i];
	if (i == (*philo)->num - 1)
		(*philo)->un[i].right_mutex = &(*philo)->mutex[0];
	else
		(*philo)->un[i].right_mutex = &(*philo)->mutex[i + 1];
	(*philo)->un[i].print = &(*philo)->print;
	(*philo)->un[i].delay = 0;
	return (1);
}

int	un_struct(t_philo **philo)
{
	int		i;
	int		num;

	i = 0;
	num = (*philo)->num;
	(*philo)->start = -1;
	if (!(*philo)->start)
		return (0);
	(*philo)->un = (t_un *)malloc(sizeof(t_un) * num);
	if (!(*philo)->un)
		return (0);
	while (i < num)
	{
		if (!fill_un(philo, i))
			return (0);
		i++;
	}
	return (1);
}
