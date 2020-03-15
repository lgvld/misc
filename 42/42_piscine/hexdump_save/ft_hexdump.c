/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:24:31 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/22 03:33:55 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

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
			if (same == 1 && !(same = 0))
				write(1, "*\n", 2);
		}
		else
		{
			same = 1;
			print_count(*count, hexascii);
			print_hexa(r, buffer, hexascii);
			if (hexascii)
				print_ascii(r, buffer);
		}
		write(1, "\n", same == 1 ? ((*count += r) || *count) : 0);
	}
	if (*count > 0)
		write(1, "\n", print_count(*count, hexascii));
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
