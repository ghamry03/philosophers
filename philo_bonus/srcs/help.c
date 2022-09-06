/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:54:33 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/26 20:14:22 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	help(void)
{
	printf("Program should have the following arguments\n");
	printf("example:\v%s %s\n\n",
		"./philo number_of_philosophers time_to_die time_to_eat",
		"time_to_sleep[number_of_times_each_philosopher_must_eat]");
	printf("number_of_philosophers: %s\n\n",
		"The number of philosophers and also the numberof forks");
	printf("time_to_die(in milliseconds): %s%s%s\n\n",
		"If a philosopher didn’t start eatingtime_to_diemilliseconds ",
		"since the beginning of their last meal or ",
		"the beginning of the sim-ulation, they die.");
	printf("time_to_eat(in milliseconds): The time it takes for a philo%s\n\n",
		"sopher to eat.During that time, they will need to hold two forks.");
	printf("time_to_sleep(in milliseconds): %s\n\n",
		"The time a philosopher will spend sleeping.");
	printf("number_of_times_each_philosopher_must_eat%s%s%s\n\n",
		"(optional argument): If allphilosophers have eaten "
		"at leastnumber_of_times_each_philosopher_must_eattimes,",
		" the simulation stops.",
		"  If not specified, the simulation stops when aphilosopher dies.");
	return (EXIT_SUCCESS);
}
