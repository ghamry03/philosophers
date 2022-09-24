/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:40:30 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/24 15:23:12 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include "structure.h"

/***************** COLORS *****************/
# define RESET			"\033[0m"
# define BLACK			"\033[30m"	/* Black */
# define RED			"\033[31m"		 /* Red */
# define GREEN			"\033[32m"		 /* Green */
# define YELLOW			"\033[33m"		 /* Yellow */
# define BLUE			"\033[34m"		 /* Blue */
# define MAGENTA		"\033[35m"		 /* Magenta */
# define CYAN			"\033[36m"		 /* Cyan */
# define WHITE			"\033[37m"		 /* White */
# define BOLDBLACK		"\033[1m\033[30m"		 /* Bold Black */
# define BOLDRED		"\033[1m\033[31m"		 /* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"		 /* Bold Green */
# define BOLDYELLOW		"\033[1m\033[33m"		 /* Bold Yellow */
# define BOLDBLUE		"\033[1m\033[34m"		 /* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"		 /* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"		 /* Bold Cyan */
# define BOLDWHITE		"\033[1m\033[37m"		 /* Bold White */

/***************** PHILO *****************/
int		parser(char **av);
void	*cycle_of_life(void *p);
int		fill_struct(char **av, t_table **philo);
int		prepare_philo(t_table **philo);
int		forkah(t_philo *un);
int		sleepah(t_philo *un);
int		eat(t_philo *un);
int		think(t_philo *un);
int		philo_struct(t_table **philo);
void	print_state(t_philo *philo, int fork_n);
int		check_death(t_philo *philo);

/***************** THREADS *****************/
int		get_threads(t_table **philo);
int		join_threads(t_table **philo);
int		init_mutex(t_table **philo);
int		destroy_mutex(t_table **philo);

/***************** TIME *****************/
time_t	time_stamp(time_t start);
time_t	get_time(void);
void	mysleep(time_t duration);

/***************** UTILS *****************/
int		help(void);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strfcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_atox(const char *str);
void	print_struct(t_table philo);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(char *s1);

#endif
