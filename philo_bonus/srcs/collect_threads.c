/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:42:55 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/12 10:00:02 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	wait_philo(t_table **table)
{
	int		i;

	i = -1;
	while (++i < (*table)->info->num)
		waitpid((*table)->philo_pid[i], NULL, 0);
}

void	close_sem(t_table **table)
{
	sem_close((*table)->info->forks_sem);
	sem_close((*table)->info->print_sem);
	sem_close((*table)->info->death_sem);
}

void	collect_philo(t_table **table)
{
	wait_philo(table);
	close_sem(table);
}
