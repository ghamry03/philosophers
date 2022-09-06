/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommohame < ommohame@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 23:56:57 by ommohame          #+#    #+#             */
/*   Updated: 2022/09/03 22:35:39 by ommohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
* writes only one character
* uses the parameter fd to identify type of write return
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
* uses ft_put char to print out every character in string s
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*
* prints out every digit in n
*/
void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	tmp;

	i = 10;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (n >= i)
		i *= 10;
	while (i > 1)
	{
		i /= 10;
		tmp = (n / i) + 48;
		ft_putchar_fd(tmp, fd);
		n %= i;
	}
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
