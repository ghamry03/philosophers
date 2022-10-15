/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:32:51 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/15 16:43:58 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_info
{
	int			num;
	int			t_eat;
	int			t_death;
	int			t_sleep;
	int			repeat;
	size_t		total_meals;
	sem_t		*forks_sem;
	sem_t		*print_sem;
	sem_t		*death_sem;
	sem_t		*meals_sem;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				state;
	size_t			*start_time;
	int				neat;
	size_t			last_eat;
	t_info			*info;
}	t_philo;

typedef struct s_table
{
	pid_t	*philo_pid;
	size_t	start_time;
	t_info	*info;
	t_philo	*philo;
}	t_table;

#endif