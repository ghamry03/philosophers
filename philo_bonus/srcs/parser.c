/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:53:52 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/27 01:49:53 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			ft_putstr_fd("philo: error: found negative sign\n", 2);
			return (0);
		}
		else if (!ft_isdigit(str[i++]))
		{
			ft_putstr_fd("philo: error: non-digit character\n", 2);
			return (0);
		}
		else if (i > INT_MAX)
		{
			ft_putstr_fd("philo: error: number is more than int max\n", 2);
			return (0);
		}
	}
	return (1);
}

int	parser(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!check_number(av[i++]))
			return (0);
	}
	return (1);
}
