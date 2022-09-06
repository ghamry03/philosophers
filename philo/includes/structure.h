/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:02:28 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/06 16:21:45 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# ifndef FORKS
# define FORKS 2
# endif
/*
**	i:			index of philo
**	status:		state of the philo
	 				-1: dead
					0: still didn't do anything yet
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
	int				fork[FORKS];
	int				death;
	int				eat;
	int				sleep;
	int				repeat;
	pthread_mutex_t	mutex[FORKS];
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
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	t_un			*un;
}	t_philo;

#endif
