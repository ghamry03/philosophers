/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:07:07 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/29 00:21:00 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	dead_log(t_philo *philo)
{
	time_t	current;

	current = time_stamp(*philo->start);
	pthread_mutex_lock(philo->print);
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDRED, 1);
	ft_putnbr_fd(philo->i, 1);
	ft_putstr_fd(RESET RED" is dead 💀\n", 1);
	ft_putstr_fd(RESET, 1);
	pthread_mutex_unlock(philo->print);
}

int	check_death(t_philo *philo)
{
	time_t	current;

	current = get_time();
	pthread_mutex_lock(philo->death_l);
	if (philo->last_eat != -1 && current - philo->last_eat > philo->death)
	{
		philo->state = 0;
		*philo->check_death = 1;
		dead_log(philo);
		pthread_mutex_unlock(philo->death_l);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo->death_l);
		return (0);
	}
}
