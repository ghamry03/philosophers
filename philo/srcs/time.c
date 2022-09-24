/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:15:38 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/08 19:54:46 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	get_time(void)
{
	time_t			ret;
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
	{
		ft_putstr_fd("philo: getting the time failed\n", 2);
		return (-1);
	}
	ret = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (ret);
}

time_t	time_stamp(time_t start)
{
	return (get_time() - start);
}

void	mysleep(time_t duration)
{
	time_t	time;

	time = get_time();
	while (get_time () < time + duration)
		usleep(10);
}
