/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:39:29 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/12 02:11:58 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*check_death(void *p)
{
	size_t	current;
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		current = time_stamp(philo->last_eat);
		if (current > (unsigned int)philo->info->t_death && philo->last_eat != 0)
		{
			sem_wait(philo->info->print_sem);
			dead_log(philo->id, current);
			sem_post(philo->info->death_sem);
			break ;
		}
		usleep(10);
	}
	return (NULL);
}

void	dead_log(int n, size_t current)
{
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDRED, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET RED" is dead 💀\n", 1);
	ft_putstr_fd(RESET, 1);
}

void	kill_the_childs(pid_t *pid, int num)
{
	int		i;

	i = 0;
	printf("children killer\n");
	while (i < num)
		kill(pid[i], SIGKILL);
}
