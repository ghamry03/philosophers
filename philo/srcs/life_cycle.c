/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/09 15:45:34 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_philo(t_philo *philo)
{
	printf("id: %d\n", philo->id);
	printf("state: %d\n", philo->state);
	printf("check_death: %d\n", *philo->check_death);
	printf("start_time: %ld\n", *philo->start_time);
	printf("left_forkn: %d\n", philo->left_forkn);
	printf("left_fork: %d\n", *philo->left_fork);
	printf("right_forkn: %d\n", philo->right_forkn);
	printf("right_fork: %d\n", *philo->right_fork);
	printf("eat: %d\n", philo->info->t_eat);
	printf("death: %d\n", philo->info->t_death);
	printf("sleep: %d\n", philo->info->t_sleep);
	printf("repeat: %d\n", philo->info->repeat);
	printf("last_eat: %zu\n", philo->last_eat);
	usleep(100);
}

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
