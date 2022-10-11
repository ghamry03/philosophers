/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/10 00:50:12 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*life_cycle(void *p)
{
	t_philo		*philo;

	philo = (t_philo *)p;
	while (*philo->check_death != DEAD)
	{
		if (philo->state == P_FORK)
			if (forks(philo) == DEAD)
				break ;
		if (philo->state == EAT)
			if (eat(philo) == DEAD)
				break ;
		if (philo->state == SLEEP)
			if (sleeep(philo) == DEAD)
				break ;
		if (philo->state == THINK)
			if (think(philo) == DEAD)
				break ;
		if (philo->info->repeat != -1 && philo->neat == philo->info->repeat)
			return (NULL);
	}
	return (NULL);
}
