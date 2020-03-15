/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:41:03 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 23:38:31 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	g_size[2];

int	main(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac < 2)
	{
		g_size[G_SIZE_COLS] = init_parser(0);
		if (g_size[G_SIZE_COLS] <= 0)
			write(2, "map error\n", 10);
		parser(0);
	}
	i = 1;
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDWR)) <= 0)
			write(2, "map error\n", 10);
		if (!init_parser(fd) || !parser(fd))
			write(2, "map error\n", 10);
		else
			print_solved(av[i]);
		close(fd);
		i++;
	}
	return (EXIT_SUCCESS);
}
