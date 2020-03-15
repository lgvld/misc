/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:14:42 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/14 15:16:57 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_clues(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < N * N)
	{
		if (i && i % N == 0)
		{
			write(1, " ", 1);
		}
		c = '0' + g_clues[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n\n", 2);
}

int		print_case(int i)
{
	static int	values[N];
	int			j;

	get_values(i, values);
	j = 0;
	while (values[j] != -1)
	{
		write(1, &("0123456789"[values[j]]), 1);
		j++;
	}
	return (j);
}

void	print_grid(void)
{
	int	i;

	i = 0;
	while (i < N * N * N)
	{
		if (i && i % N == 0 && i % (N * N) != 0)
		{
			write(1, " ", 1);
		}
		if (i && i % (N * N) == 0)
		{
			write(1, "\n", 1);
		}
		write(1, &("0123456789"[g_grid[i]]), 1);
		i++;
	}
	write(1, "\n", 1);
}
