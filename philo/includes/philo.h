/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:15:42 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/04 01:30:50 by ommohame         ###   ########.fr       */
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

/********************* DEFINES *********************/
# define SUCCESS 0
# define ERROR	-1

//	PHILOSOPHER STATE
# define DEAD	-1
# define THINK	0
# define P_FORK	1 // picking fork
# define EAT	2
# define SLEEP	3

//	ERROR TYPE
# define SYS_ERR 0
# define PAR_ERR 1
# define LOG_MSG 2

//	SYSTEM ERROR
# define MALLOC_ERR	0
# define MUTEX_ERR	1
# define THREAD_ERR 2
# define JOIN_ERR	3
# define DMUTEX_ERR	4

//	PARSER ERROR
# define INV_ARG	0
# define NDGT_ERR	1
# define NMAX_ERR	2

/*********************  COLORS  *********************/
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

/*********************  PHILO *********************/
int		parser(int ac, char **av);

t_table	*init_struct(char **av);

void	print_msg(int type, int num);
int		print_state(t_philo *philo, int fork_n);

void	free_table(t_table *table);

int		init_threads(t_table **table);
void	collect_philo(t_table **table);

void	*life_cycle(void *p);

size_t	get_time(void);
size_t	time_stamp(time_t start);
void	mysleep(size_t duration);

/*********************  UTILS  *********************/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
size_t	ft_atox(const char *str);

#endif