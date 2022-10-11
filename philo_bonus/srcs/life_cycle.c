/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/12 01:40:05 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	life_cycle(t_philo *philo)
{
	pthread_t	check_deatht;

	pthread_create(&check_deatht, NULL, &check_death, &philo);
	if (philo->id % 2 == 0)
		mysleep(philo, philo->info->t_eat);
	while (1)
	{
		if (philo->state == P_FORK)
			if (forks(philo) == DEAD)
				return ;
		if (philo->state == EAT)
			if (eat(philo) == DEAD)
				return ;
		if (philo->state == SLEEP)
			if (sleeep(philo) == DEAD)
				return ;
		if (philo->state == THINK)
			if (think(philo) == DEAD)
				return ;
		if (philo->info->repeat != -1 && philo->neat == philo->info->repeat)
			return ;
	}
}
