/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:42:55 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/13 11:15:51 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	terminate_proc(pid_t *pid, int num)
{
	int		i;

	i = -1;
	while (++i < num)
	{
		if (kill(pid[i], SIGKILL))
			print_msg(SYS_ERR, KILL_ERR);
	}
}

void	free_table(t_table *table)
{
	free(table->philo);
	free(table->info);
	free(table->philo_pid);
	free(table);
}

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
	terminate_proc((*table)->philo_pid, (*table)->info->num);
	wait_philo(table);
	close_sem(table);
}
