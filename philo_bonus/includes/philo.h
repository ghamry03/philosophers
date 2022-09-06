/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:40:30 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/27 03:01:09 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "structure.h"

size_t	ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strtcmp(char *s1, char *s2);
int		ft_isdigit(int c);
size_t	ft_atox(const char *str);
void	print_struct(t_philo philo);

int		help(void);
int		parser(char **av);
int		fill_struct(char **av, t_philo **philo);

#endif
