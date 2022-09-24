/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:26:20 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/24 15:32:10 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*cycle_of_life(void *p)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)p;
	i = 0;
	while (!*philo->check_death)
	{
		if (philo->state == 4)
			if (!forkah(philo))
				break ;
		if (philo->state == 1)
		{
			if (!eat(philo))
				break ;
			i++;
		}
		if (philo->state == 2)
			if (!sleepah(philo))
				break ;
		if (philo->state == 3)
			if (!think(philo))
				break ;
		if (philo->repeat != -1)
			if (i == philo->repeat)
				break ;
	}
	return (NULL);
}

/*
 * where the party starts
 * gather the philos into the house
 */
int	get_the_philo(t_table **philo)
{
	if (!get_threads(philo))
		return (0);
	if (!join_threads(philo))
		return (0);
	if (!destroy_mutex(philo))
		return (0);
	return (1);
}

int	init_table(char **av, t_table **philo)
{
	if (!parser(av))
		return (0);
	if (!fill_struct(av, philo))
		return (0);
	if (!init_mutex(philo))
		return (0);
	if (!philo_struct(philo))
		return (0);
	return (1);
}

int	philo(char **av)
{
	t_table	*philo;

	philo = NULL;
	philo = (t_table *)malloc(sizeof(t_table));
	if (!philo)
		return (0);
	if (!init_table(av, &philo))
		return (0);
	// print_struct(*philo);
	get_the_philo(&philo);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1 || ac > 6
		|| (ac > 1 && ac < 5 && !ft_strfcmp(av[1], "--help")))
	{
		ft_putstr_fd("Error: run ./philo --help\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (ac == 2 && ft_strfcmp(av[1], "--help"))
		return (help());
	else if (!philo(av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
