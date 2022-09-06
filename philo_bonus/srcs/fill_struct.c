/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:26:21 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/27 03:13:26 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	fill_struct(char **av, t_philo **philo)
{
	(*philo)->philo = ft_atox(av[1]);
	(*philo)->death = ft_atox(av[2]);
	(*philo)->eat = ft_atox(av[3]);
	(*philo)->sleep = ft_atox(av[4]);
	if (av[5])
		(*philo)->repeat = ft_atox(av[5]);
	else
		(*philo)->repeat = 0;
	return (1);
}
