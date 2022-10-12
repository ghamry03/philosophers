/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/12 15:35:28 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	life_cycle(t_philo *philo)
{
	pthread_t	check_deatht;

	pthread_create(&check_deatht, NULL, &check_death, philo);
	if (philo->id % 2 == 0)
		mysleep(philo, philo->info->t_eat);
	while (1)
	{
		forks(philo);
		eat(philo);
		sleeep(philo);
		think(philo);
		if (philo->info->repeat != -1 && philo->neat == philo->info->repeat)
			break ;
	}
	sem_post(philo->info->death_sem);
}
