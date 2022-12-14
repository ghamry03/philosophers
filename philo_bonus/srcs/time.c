/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:35:56 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/13 08:44:19 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_time(void)
{
	size_t			ret;
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
	{
		ft_putstr_fd("philo: getting the time failed\n", 2);
		return (-1);
	}
	ret = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (ret);
}

size_t	time_stamp(size_t start)
{
	return (get_time() - start);
}

void	mysleep(size_t duration)
{
	size_t	time;

	time = get_time();
	while (get_time () < time + duration)
		usleep(500);
}
