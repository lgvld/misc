/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:24:31 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/22 01:19:06 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

#include <stdio.h>

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

void	print_count(unsigned count, int hexascii)
{
	char	buffer[CHUNK_SIZE - 1 + hexascii];

	u2hex(count, buffer, CHUNK_SIZE - 1 + hexascii);
	write(1, buffer, CHUNK_SIZE - 1 + hexascii);
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
	print_spaces(2 * 2 * CHUNK_SIZE + 2 * (CHUNK_SIZE - 1) + hexascii - 2 * r - (r - 1) + (r <= CHUNK_SIZE));
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

int		same_as_previous(char *buf)
{
	static char	previous[2 * CHUNK_SIZE];

	if (ft_strncmp_(buf, previous, 2 * CHUNK_SIZE) == 0)
	{
		return (1);
	}
	ft_memcpy(previous, buf, 2 * CHUNK_SIZE);
	return (0);
}

unsigned	read_files(int ac, char **av, char **buf, int hexascii)
{
	unsigned	c;
	int			fd;
	unsigned	r;

	c = 1 + hexascii;
	while (c < ac)
	{
		if (!(fd = open(av[c], O_RDONLY)))
		{
			return(-1 * c);
		}

		close(fd);
		c++;
	}
}

void	ft_hexdump(int fd, int hexascii, unsigned *count)
{
	unsigned	r;
	static char	buffer[2 * CHUNK_SIZE];
	int			same;

	r = 0;
	same = 1;
	while ((r = read(fd, buffer, 2 * CHUNK_SIZE)))
	{
		if (r == 2 * CHUNK_SIZE && same_as_previous(buffer))
		{
			if (same == 1)
			{
				write(1, "*\n", 2);
				same = 0;
			}
		}
		else
		{
			same = 1;
			print_count(*count, hexascii);
			print_hexa(r, buffer, hexascii);
			if (hexascii)
			{
				print_ascii(r, buffer);
			}
		}
		write(1, "\n", same == 1 ? 1 : 0);
		*count += r;
	}
	if (*count > 0)
	{
		print_count(*count, hexascii);
		write(1, "\n", 1);
	}
}

int		main(int ac, char **av)
{
	unsigned	count;
	int			hexascii;
	int			fd;
	int			c;

	hexascii = 0;
	if (ac >= 2 && ft_strncmp_(av[1], "-C", 2) == 0)
	{
		hexascii = 1;
	}
	count = 0;
	c = 1;
	while (c + hexascii < ac)
	{
		fd = open(av[c + hexascii], O_RDONLY);
		if (fd == -1)
		{
			return (EXIT_FAILURE);
		}
		ft_hexdump(fd, hexascii, &count);
		close(fd);
		c++;
	}
	return (EXIT_SUCCESS);
}
