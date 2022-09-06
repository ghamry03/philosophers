/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:52:40 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/31 21:59:26 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_struct(t_philo philo)
{
	printf("philo num: %d\n", philo.num);
	printf("death time: %d\n", philo.death);
	printf("eat time: %d\n", philo.eat);
	printf("sleep time: %d\n", philo.sleep);
	printf("repeat: %d\n", philo.repeat);
}
