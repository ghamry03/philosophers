/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:52:40 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/27 02:56:12 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_struct(t_philo philo)
{
	printf("philo num: %zu\n", philo.philo);
	printf("death time: %zu\n", philo.death);
	printf("eat time: %zu\n", philo.eat);
	printf("sleep time: %zu\n", philo.sleep);
	printf("repeat: %zu\n", philo.repeat);
}
