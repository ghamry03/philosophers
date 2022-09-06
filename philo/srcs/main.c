/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:26:20 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/06 15:41:52 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*cycle_of_life(void *p)
{
	int		i;
	t_un	*un;

	i = 0;
	un = (t_un *)p;
	while (i < un->repeat)
	{
		if (un->status == 0 || un->status == 4)
			forkah(&un);
		else if (un->status == 1)
			eat(&un);
		else if (un->status == 2)
			sleepah(&un);
		else if (un->status == 3)
			think(&un);
		else if (un->status == -1)
			exit (0);
		i++;
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
	destroy_mutex(&philo);
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
