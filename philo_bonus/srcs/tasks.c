/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:18:00 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/13 11:03:45 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	forks(t_philo *philo)
{
	sem_wait(philo->info->forks_sem);
	if (philo->neat == 0)
		philo->last_eat = get_time();
	print_state(philo);
	sem_wait(philo->info->forks_sem);
	print_state(philo);
	philo->state = EAT;
	return (SUCCESS);
}

int	eat(t_philo *philo)
{
	print_state(philo);
	mysleep(philo->info->t_eat);
	philo->last_eat = get_time();
	sem_post(philo->info->forks_sem);
	sem_post(philo->info->forks_sem);
	philo->neat++;
	philo->state = SLEEP;
	return (SUCCESS);
}

int	sleeep(t_philo *philo)
{
	print_state(philo);
	mysleep(philo->info->t_sleep);
	philo->state = THINK;
	return (SUCCESS);
}

int	think(t_philo *philo)
{
	print_state(philo);
	philo->state = P_FORK;
	return (SUCCESS);
}
