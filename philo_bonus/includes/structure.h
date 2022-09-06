/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:02:28 by ommohame          #+#    #+#             */
/*   Updated: 2022/08/27 02:07:06 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_philo
{
	size_t		philo;
	size_t		death;
	size_t		eat;
	size_t		sleep;	
	size_t		repeat;
}	t_philo;

#endif
