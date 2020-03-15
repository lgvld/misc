/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:24:31 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 15:44:12 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

#include <stdio.h>

int		repetition(char *buf)
{
	static char	previous[16];

	if (ft_strncmp_(buf, previous, 16) == 0)
	{
		return (1);
	}
	ft_memcpy(previous, buf, 16);
	return (0);
}

char	*u2hex(unsigned n, char *buf, unsigned buf_size)
{
	char	*buf_save;

	buf_save = buf;
	while (n != 0 && buf_size > 0)
	{
		*(buf + buf_size - 1) = BASE[n % (sizeof(BASE) - 1)];
		n /= 16;
		buf_size--;
	}
	while (buf_size > 0)
	{
		*(buf + buf_size - 1) = BASE[0];
		buf_size--;
	}
	return (buf_save);
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

void	print_chunk(unsigned r, char *buf, int hexascii)
{
	static char	buffer[16];
	unsigned	i;

	i += r;
	if (i > 16)
	{
		write(1, buffer, 16);
	}
	ft_memcpy(buffer, buf, (i %= 16));
}

void	ft_hexdump(int fd, unsigned *count, int hexascii, int last_file)
{
	static char	buffer[16];
	unsigned	r;

	(void)count;
	(void)hexascii;
	(void)last_file;
	r = 0;
	while ((r = read(fd, buffer, 16)))
	{
		print_chunk(r, buffer, hexascii);
	}
}

int		main(int ac, char **av)
{
	unsigned	count;
	int			hexascii;
	int			fd;
	int			i;

	hexascii = 0;
	if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'C')
	{
		hexascii = 1;
	}
	count = 0;
	i = 1;
	while (i + hexascii < ac)
	{
		fd = open(av[i + hexascii], O_RDONLY);
		if (fd == -1)
		{
			return (EXIT_FAILURE);
		}
		ft_hexdump(fd, &count, hexascii, i + hexascii == ac - 1);
		close(fd);
		i++;
	}
	// print_count(count, hexascii);
	write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
