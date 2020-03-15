/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:06:25 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/14 22:54:54 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			eliminate(int i, int value)
{
	int j;

	j = 0;
	while (j < N)
	{
		if (g_grid[i * N + j] == value)
		{
			g_grid[i * N + j] = 0;
			return (TRUE);
		}
		j++;
	}
	return (FALSE);
}

void		eliminate_rc(int i, int value, int preserve)
{
	int	i_save;
	int	j;

	i_save = i;
	i = (i % N) * N;
	j = 0;
	while (i < N * N * N)
	{
		if (j == 4 && !(j = 0))
			i += N * N;
		while (j < 4)
		{
			if (g_grid[i + j] == value && (i + j) / N != preserve)
				g_grid[i + j] = 0;
			j++;
		}
	}
	i = i_save;
	i = (i / N) * N * N;
	j = -1;
	while (++j < N * N)
	{
		if (g_grid[i + j] == value && (i + j) / N != preserve)
			g_grid[i + j] = 0;
	}
}

int			assign(int i, int value)
{
	int	j;

	j = 0;
	while (j < N && g_grid[i * N + j] != value)
	{
		j++;
	}
	if (j == N)
	{
		return (FALSE);
	}
	g_grid[i * N] = value;
	j = 1;
	while (j < N)
	{
		g_grid[i * N + j] = 0;
		j++;
	}
	eliminate_rc(i, value, i);
	return (TRUE);
}

void		iterate(int i, int clue, int step, int j)
{
	int	values[N];
	int	k;

	if (j == 0)
		return ;
	get_values(i, values);
	if (clue == 1 && j == N)
	{
		assign(i, N);
		return ;
	}
	k = 0;
	while (values[k] != -1)
	{
		if (values[k] - 1 > N - clue)
		{
			eliminate(i, values[k]);
		}
		k++;
	}
	if (get_values(i, values) == 1)
	{
		eliminate_rc(i, values[0], i);
	}
	iterate(i + step, clue - 1, step, j - 1);
}

void		apply_clues(void)
{
	int	i;
	int	step;
	int	c;

	i = 0;
	while (i < 4 * N)
	{
		step = -1;
		c = (N - 1) + (i % N) * N;
		if (i < 3 * N && (step = 1))
			c = N * (i % N);
		if (i < 2 * N)
		{
			step = -N;
			c = (N - 1) * N + i % N;
		}
		if (i < N)
		{
			step = N;
			c = i;
		}
		iterate(c, g_clues[i], step, N);
		i++;
	}
}
