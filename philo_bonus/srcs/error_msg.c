/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:50:49 by ommohame          #+#    #+#             */
/*   Updated: 2022/10/11 15:05:31 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sys_error(int num)
{
	if (num == MALLOC_ERR)
		ft_putendl_fd("philo: malloc fail", 2);
	else if (num == SEMOPEN_ERR)
		ft_putendl_fd("philo: opening semaphore fail", 2);
	else if (num == FORK_ERR)
		ft_putendl_fd("philo: fork fail", 2);

}

static void	parser_err(int num)
{
	if (num == INV_ARG)
		ft_putendl_fd("philo: error: invalid number of arguments", 2);
	else if (num == NDGT_ERR)
		ft_putendl_fd("philo: error: non-digit character", 2);
	else if (num == NMAX_ERR)
		ft_putendl_fd("philo: error: number is more than int max", 2);
	else if (num == ZERO_ERR)
		ft_putendl_fd("philo: error: argument is equal to zero", 2);
}

void	print_msg(int type, int num)
{
	ft_putstr_fd(BOLDRED, 2);
	if (type == SYS_ERR)
		sys_error(num);
	else if (type == PAR_ERR)
		parser_err(num);
	ft_putstr_fd(RESET, 2);
}
