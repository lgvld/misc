/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 00:40:18 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/05 23:51:59 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		return ((void)write(1, "2147483648", 10));
	}
	c = n % 10 + '0';
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-1 * n));
	}
	if (n / 10 != 0)
	{
		ft_putnbr(n / 10);
	}
	write(1, &c, 1);
}
