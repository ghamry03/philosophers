/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:18:00 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/13 12:42:25 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	// int		ret;

	philo->last_eat = get_time();
	print_state(philo, -1);
	mysleep(philo, philo->info->t_eat);
		// ret = DEAD;
	pthread_mutex_lock(philo->left_mutex);
	*philo->left_fork = FREE;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*philo->right_fork = FREE;
	pthread_mutex_unlock(philo->right_mutex);
	philo->neat++;
	philo->state = SLEEP;
	return (SUCCESS);
}

int	sleeep(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	if (ret == DEAD)
		return (DEAD);
	if (mysleep(philo, philo->info->t_sleep) == DEAD)
		return (DEAD);
	ret = print_state(philo, DEAD);
	philo->state = THINK;
	return (ret);
}

int	think(t_philo *philo)
{
	int		ret;

	ret = print_state(philo, -1);
	philo->state = P_FORK;
	return (ret);
}
