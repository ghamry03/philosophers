/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:26:20 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/08 14:49:24 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*cycle_of_life(void *p)
{
	int		i;
	t_un	*un;

	un = (t_un *)p;
	i = 0;
	while (*un->start == -1)
		;
	while (1)
	{
		if (un->status == 4)
			forkah(un);
		if (un->status == 1)
		{
			eat(un);
			i++;
		}
		if (un->status == 2)
			sleepah(un);
		if (un->status == 3)
			think(un);
		if (un->status == 0)
			break ;
		if (un->repeat != -1)
			if (i == un->repeat)
				break ;
	}
	return (NULL);
}

/*
 * where the party starts
 * gather the philos into the house
 */
int	get_the_philo(t_philo **philo)
{
	if (!get_threads(philo))
		return (0);
	if (!join_threads(philo))
		return (0);
	if (!destroy_mutex(philo))
		return (0);
	return (1);
}

int	init_philo(char **av, t_philo **philo)
{
	if (!parser(av))
		return (0);
	if (!fill_struct(av, philo))
		return (0);
	if (!init_mutex(philo))
		return (0);
	if (!un_struct(philo))
		return (0);
	return (1);
}

int	philo(char **av)
{
	t_philo	*philo;

	philo = NULL;
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	if (!init_philo(av, &philo))
		return (0);
	print_struct(*philo);
	get_the_philo(&philo);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1 || ac > 6 || (ac > 1 && ac < 5 && !ft_strtcmp(av[1], "--help")))
	{
		ft_putstr_fd("Error: run ./philo --help\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (ac == 2 && ft_strtcmp(av[1], "--help"))
		return (help());
	else if (!philo(av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
