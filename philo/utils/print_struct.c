/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:52:40 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/22 03:41:28 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_struct(t_table philo)
{
	printf("philo num: %d\n", philo.num);
	printf("death time: %d\n", philo.death);
	printf("eat time: %d\n", philo.eat);
	printf("sleep time: %d\n", philo.sleep);
	printf("repeat: %d\n", philo.repeat);
}
