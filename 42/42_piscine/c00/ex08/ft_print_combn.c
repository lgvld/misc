/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 23:19:09 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/04 17:06:17 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	digit_at_pos(int nb, int pos)
{
	if (pos == 0)
		return ('0' + nb % 10);
	return (digit_at_pos(nb / 10, pos - 1));
}

int		digits_are_increasing(int nb, int n)
{
	while (n > 0)
	{
		if (nb != 0 && digit_at_pos(nb, n) >= digit_at_pos(nb, n - 1))
			return (0);
		n--;
	}
	return (1);
}

int		power(int n, unsigned int p)
{
	if (n == 1 || p == 0)
		return (1);
	return (n * power(n, p - 1));
}

void	ft_print_combn(int n)
{
	int nb;
	int n_copy;

	if (n == 9)
	{
		write(1, "123456789", 9);
		return ;
	}
	nb = 0;
	while (1)
	{
		if (digits_are_increasing(nb, n))
		{
			n_copy = n;
			while (n_copy > 0)
				ft_putchar(digit_at_pos(nb, n_copy-- - 1));
			if (nb == 9 || nb == 89 || nb == 789 || nb == 6789 ||
				nb == 56789 || nb == 456789 || nb == 3456789 ||
				nb == 23456789 || nb == 12345678)
				break ;
			write(1, ", ", 2);
		}
		nb++;
	}
}
