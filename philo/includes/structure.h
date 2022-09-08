/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:02:28 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/08 15:08:47 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
**	i:			index of philo
**	status:		state of the philo
	 				0: dead
					1: picked forks
					2: ate food
					3: slept
					4:thinking
**	eat:		time to eat
**	death:		time to die
**	sleep:		time to sleep
**	repeat:		how many time to repeat the cycle
**	mutex:		philo own mutex lock
*/
typedef struct s_un
{
	int				i;
	int				status;
	int				*left_fork;
	int				*right_fork;
	int				death;
	int				eat;
	int				sleep;
	int				repeat;
	time_t			delay;
	time_t			*start;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	*print;
}	t_un;

/*
**	num:		number of philos
**	eat:		time to eat
**	death:		time to die
**	sleep:		time to sleep
**	repeat:		how many time to repeat the cycle
					-1: repeat it until a philo die
**	fork:		has the fork status that the philo gonna use to ear
					0: available
					1: taken
**	threads:	an array that has all threads id
**	mutex:		an array with all the mutex locks
**	philo:		a structure for each philospher
*/
typedef struct s_philo
{
	int				*i;
	int				num;
	int				death;
	int				eat;
	int				sleep;
	int				repeat;
	int				*fork;
	time_t			start;
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	t_un			*un;
}	t_philo;

#endif
