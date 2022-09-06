/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:26:20 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/27 03:13:42 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo(char **av)
{
	t_philo		*philo;

	philo = NULL;
	if (parser(av) == 0)
		return (EXIT_FAILURE);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (EXIT_FAILURE);
	if (fill_struct(av, &philo) == 0)
		return (EXIT_FAILURE);
	print_struct(*philo);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac == 1 || ac > 6 || (ac > 1 && ac < 5 && !ft_strtcmp(av[1], "--help")))
	{
		ft_putstr_fd("Error: run ./philo --help\n", 2);
		exit (EXIT_FAILURE);
	}
	else if (ac == 2 && ft_strtcmp(av[1], "--help"))
		return (help());
	else
		if (philo(av) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
