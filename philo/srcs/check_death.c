/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:07:07 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/24 15:30:00 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_philo *philo)
{
	time_t	current;

	current = get_time();
	if (philo->last_eat != -1 && current - philo->last_eat > philo->death)
	{
		philo->state = 0;
		*philo->check_death = 1;
		print_state(philo, -1);
		return (1);
	}
	else
		return (0);
}
