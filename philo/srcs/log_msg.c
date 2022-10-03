/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:16:05 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/04 01:41:53 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_death(size_t last_eat, size_t current, size_t death_time)
{
	if (current - last_eat > death_time)
		return (DEAD);
	else
		return (SUCCESS);
}

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

static void	dead_log(int n, int current)
{
	ft_putstr_fd(RED, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDRED, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET RED" is dead 💀\n", 1);
	ft_putstr_fd(RESET, 1);
}

int	print_state(t_philo *philo, int fork_n)
{
	time_t	current;

	pthread_mutex_lock(philo->print);
	current = time_stamp(*philo->start_time);
	if (check_death(philo->last_eat, current, philo->death) == DEAD)
	{
		printf("HERE\n");
		*philo->check_death = DEAD;
		pthread_mutex_unlock(philo->print);
		dead_log(philo->id, current);
		return (DEAD);
	}
	else if (*philo->check_death != DEAD)
	{
		if (philo->state == P_FORK)
			fork_log(philo->id, fork_n, current);
		else if (philo->state == EAT)
			eating_log(philo->id, current);
		else if (philo->state == SLEEP)
			sleeping_log(philo->id, current);
		else if (philo->state == THINK)
			thinking_log(philo->id, current);
	}
	pthread_mutex_unlock(philo->print);
	return (SUCCESS);
}
