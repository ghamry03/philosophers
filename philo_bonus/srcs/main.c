/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:14:58 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/12 15:33:41 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo(int ac, char **av)
{
	t_table		*table;

	if (parser(ac, av) == ERROR)
		return (ERROR);
	table = init_struct(av);
	if (!table)
		return (ERROR);
	if (init_philo(&table) == ERROR)
		return (ERROR);
	collect_philo(&table);
	free_table(table);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (philo(ac, av) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
