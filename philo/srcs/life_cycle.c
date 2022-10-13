/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:29:18 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/13 16:55:28 by ommohame         ###   ########.fr       */
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
			return (NULL);
	}
	return (NULL);
}
