/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:21:46 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/11 12:50:52 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_sem(t_table **table)
{
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
	sem_unlink("/death_sem");
	(*table)->info->forks_sem = sem_open("/forks_sem", O_CREAT, 0644,
			(*table)->info->num);
	(*table)->info->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	(*table)->info->death_sem = sem_open("/death_sem", O_CREAT, 0644, 1);
	if ((*table)->info->forks_sem == SEM_FAILED
		|| (*table)->info->print_sem == SEM_FAILED
		|| (*table)->info->death_sem == SEM_FAILED)
	{
		print_msg(SYS_ERR, SEMOPEN_ERR);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	create_process(t_table **table)
{
	int		i;

	i = -1;
	(*table)->start_time = get_time();
	while (++i < (*table)->info->num)
	{
		(*table)->philo_pid[i] = fork();
		if ((*table)->philo_pid[i] == -1)
		{
			print_msg(SYS_ERR, FORK_ERR);
			free_table(*table);
			return (ERROR);
		}
		else if (!(*table)->philo_pid[i])
		{
			life_cycle(&((*table)->philo[i]));
			free_table(*table);
			exit(SUCCESS);
		}
	}
	return (SUCCESS);
}

int	init_philo(t_table **table)
{
	if (init_sem(table) == ERROR)
		return (ERROR);
	if (create_process(table) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
