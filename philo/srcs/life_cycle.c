/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/17 21:36:43 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	dead_log(int n, int current)
{
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDRED, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET RED" is dead 💀\n", 1);
	ft_putstr_fd(RESET, 1);
}

int	check_death(size_t last_eat, size_t death_time)
{
	size_t	current;

	current = get_time();
	if (current - last_eat > death_time && last_eat != 0)
		return (DEAD);
	else
		return (SUCCESS);
}

int	print_state(t_philo *philo, int fork_n)
{
	size_t	current;

	pthread_mutex_lock(philo->print);
	current = time_stamp(*philo->start_time);
	if (*philo->check_death == DEAD
		|| check_death(philo->last_eat, philo->info->t_death) == DEAD)
	{
		if (*philo->check_death != DEAD)
			dead_log(philo->id, current);
		*philo->check_death = DEAD;
		pthread_mutex_unlock(philo->print);
		return (DEAD);
	}
	else if (*philo->check_death != DEAD && fork_n != DEAD)
		pick_log(philo, current, fork_n);
	pthread_mutex_unlock(philo->print);
	return (SUCCESS);
}

void	*life_cycle(void *p)
{
	t_philo		*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (forks(philo) == DEAD)
			break ;
		if (eat(philo) == DEAD)
			break ;
		if (sleeep(philo) == DEAD)
			break ;
		if (think(philo) == DEAD)
			break ;
		if (philo->info->repeat != -1 && philo->neat == philo->info->repeat)
			break ;
	}
	return (NULL);
}
