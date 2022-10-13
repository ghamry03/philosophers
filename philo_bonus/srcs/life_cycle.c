/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/13 11:15:36 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	dead_log(int n, size_t current)
{
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDRED, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET RED" is dead 💀\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	*check_death(void *p)
{
	size_t	current;
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		current = time_stamp(philo->last_eat);
		if (current > (unsigned int)philo->info->t_death
			&& philo->last_eat != 0)
		{
			sem_wait(philo->info->print_sem);
			dead_log(philo->id, time_stamp(*philo->start_time));
			sem_post(philo->info->death_sem);
			break ;
		}
		usleep(500);
	}
	return (NULL);
}

void	life_cycle(t_philo *philo)
{
	pthread_t	check_deatht;

	if (pthread_create(&check_deatht, NULL, &check_death, philo))
		print_msg(SYS_ERR, THREAD_ERR);
	if (philo->id % 2 == 0)
		mysleep(philo->info->t_eat);
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
