/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:32:51 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/04 01:19:52 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

// # include "philo.h"

/**
 * id: philosopher id
 * state: philosopher status
 * 			-1: dead
 * 			 0: didn't start yet / thinking
 * 			 1: picked forks
 * 			 2: eating
 * 			 3: sleeping
 * start_time: system time when the first thread was created
 * check_death: checks if any philosopher died
 * left_forkn: left fork number
 * right_forkn: right fork number
 * left_fork: fork on the left
 * right_fork: fork on the right
 * eat: time to eat
 * death: time to die
 * sleep: time to sleep
 * repeat: number of times each philosopher should eat
 * last_eat: last time philosopher ate
 * left_mutex: mutex for the left fork
 * right_mutex: mutex for the right fork
 * print: mutex that is shared between all philosophers to print
**/
typedef struct s_philo
{
	int				id;
	int				state;
	int				*check_death;
	size_t			*start_time;
	int				left_forkn;
	int				right_forkn;
	int				*left_fork;
	int				*right_fork;
	int				eat;
	int				death;
	int				sleep;
	ssize_t			repeat;
	size_t			last_eat;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	*print;
}	t_philo;

/**
 * num: number of philosophers
 * check_death: check if any philo died
 * 				0: no philosopher died
 * 				1: a philosopher died
 * start_time: system time when the first thread was created
 * eat: time to eat
 * death: time to die
 * sleep: time to sleep
 * repeat: number of times each philosopher should eat
 * fork: each fork status
 * threads: philosophers threads
 * mutex: mutex locks array
 * print: printing lock
 * philo: philosophers structure
**/
typedef struct s_table
{
	int				num;
	int				check_death;
	size_t			start_time;
	size_t			eat;
	size_t			death;
	size_t			sleep;
	ssize_t			repeat;
	int				*forks;
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_table;

#endif