/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:16:05 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/12 00:02:34 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	fork_log(int n, int current)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "BOLDYELLOW, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET YELLOW" has picked a fork ", 1);
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
	ft_putstr_fd(CYAN, 1);
	ft_putnbr_fd(current, 1);
	ft_putstr_fd(": philo "CYAN, 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd(RESET CYAN" is thinking 💭\n", 1);
	ft_putstr_fd(RESET, 1);
}

int	print_state(t_philo *philo, int f)
{
	time_t	current;

	// if (check_death(philo->last_eat, philo->info->t_death) == DEAD)
	// {
	// 	if (*philo->check_death != DEAD)
	// 		dead_log(philo->id, current);
	// 	*philo->check_death = DEAD;
	// 	pthread_mutex_unlock(philo->print);
	// 	return (DEAD);
	// }
	// else if (*philo->check_death != DEAD && fork_n != DEAD)
	// {
	// sem_getvalue(philo->info->print_sem, &value);
	(void)f;
	sem_wait(philo->info->print_sem);
	current = time_stamp(*philo->start_time);
	if (philo->state == P_FORK)
		fork_log(philo->id, current);
	else if (philo->state == EAT)
		eating_log(philo->id, current);
	else if (philo->state == SLEEP)
			sleeping_log(philo->id, current);
	else if (philo->state == THINK)
			thinking_log(philo->id, current);
	sem_post(philo->info->print_sem);
	return (SUCCESS);
}
