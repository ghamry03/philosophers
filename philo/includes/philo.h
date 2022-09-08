/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:40:30 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/08 15:14:12 by ommohame         ###   ########.fr       */
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

int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strtcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_atox(const char *str);
void	print_struct(t_philo philo);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(char *s1);

int		help(void);
int		parser(char **av);
void	*cycle_of_life(void *p);
int		fill_struct(char **av, t_philo **philo);
int		get_threads(t_philo **philo);
int		join_threads(t_philo **philo);
int		init_mutex(t_philo **philo);
int		destroy_mutex(t_philo **philo);
int		prepare_philo(t_philo **philo);
int		forkah(t_un *un);
int		eat(t_un *un);
int		sleepah(t_un *un);
int		think(t_un *un);
int		un_struct(t_philo **philo);
time_t	time_stamp(time_t start);
time_t	get_time(void);
void	mysleep(time_t duration);

#endif
