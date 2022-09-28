/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:07:28 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/29 00:20:02 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	fork_log(int n, int fork_n, int current)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDYELLOW, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET YELLOW" has picked fork ", 1);
	ft_putnbr_fd(fork_n, 1);
	ft_putstr_fd(" 🥢\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	eating_log(int n, int current)
{
	ft_putstr_fd(GREEN, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDGREEN, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET GREEN" is eating 🍝\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	sleeping_log(int n, int current)
{
	ft_putstr_fd(BLUE, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDBLUE, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET BLUE" is sleeping 😴\n", 1);
	ft_putstr_fd(RESET, 1);
}

static void	thinking_log(int n, int current)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDYELLOW, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET YELLOW" is thinking 💭\n", 1);
	ft_putstr_fd(RESET, 1);
}

void	print_state(t_philo *philo, int fork_n)
{
	time_t	current;

	current = time_stamp(*philo->start);
	pthread_mutex_lock(philo->print);
	if (philo->state == 1 && !*philo->check_death)
		fork_log(philo->i, fork_n, current);
	else if (philo->state == 2 && !*philo->check_death)
		eating_log(philo->i, current);
	else if (philo->state == 3 && !*philo->check_death)
		sleeping_log(philo->i, current);
	else if (philo->state == 4 && !*philo->check_death)
		thinking_log(philo->i, current);
	pthread_mutex_unlock(philo->print);
}
