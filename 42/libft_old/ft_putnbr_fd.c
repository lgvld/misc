/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 00:40:18 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/05 23:52:07 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		return ((void)write(fd, "2147483648", 10));
	}
	c = n % 10 + '0';
	if (n < 0)
	{
		write(fd, "-", 1);
		return (ft_putnbr_fd(-1 * n, fd));
	}
	if (n / 10 != 0)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	write(fd, &c, 1);
}
