/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 03:28:04 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/22 03:51:04 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*u2hex(unsigned n, char *buf, unsigned buf_size)
{
	char	*buf_save;

	buf_save = buf;
	while (n != 0 && buf_size > 0)
	{
		*(buf + buf_size - 1) = HEXA_BASE[n % (sizeof(HEXA_BASE) - 1)];
		n /= 16;
		buf_size--;
	}
	while (buf_size > 0)
	{
		*(buf + buf_size - 1) = HEXA_BASE[0];
		buf_size--;
	}
	return (buf_save);
}

void	print_spaces(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

int		print_count(unsigned count, int hexascii)
{
	char	buffer[CHUNK_SIZE - 1 + hexascii];

	u2hex(count, buffer, CHUNK_SIZE - 1 + hexascii);
	write(1, buffer, CHUNK_SIZE - 1 + hexascii);
	return (1);
}

void	print_hexa(unsigned r, char *buf, int hexascii)
{
	static char	buffer[2];
	unsigned	c;

	c = 0;
	while (c < r)
	{
		print_spaces(hexascii && (c % CHUNK_SIZE == 0) ? 2 : 1);
		u2hex(buf[c], buffer, 2);
		write(1, buffer, 2);
		c++;
	}
	print_spaces(2 * 2 * CHUNK_SIZE + 2 * (CHUNK_SIZE - 1) -
					2 * r - (r - 1) + (r <= 2 * CHUNK_SIZE));
}

void	print_ascii(unsigned r, char *buf)
{
	write(1, "  |", 3);
	while (r > 0)
	{
		if (*buf >= ' ' && *buf <= '~')
		{
			write(1, buf, 1);
		}
		else
		{
			write(1, ".", 1);
		}
		buf++;
		r--;
	}
	write(1, "|", 1);
}
