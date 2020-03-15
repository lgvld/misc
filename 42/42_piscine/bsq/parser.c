/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:42:23 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 23:41:44 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	g_line_above[MAX_SIZE + 1];
char	g_line_current[MAX_SIZE + 1];
int		g_size[2];
char	g_characters[3];
int		g_max_pos[3];

int		init_parser(int fd)
{
	int	r;

	g_max_pos[0] = 0;
	g_max_pos[1] = 0;
	g_max_pos[2] = 0;
	g_size[G_SIZE_COLS] = 0;
	g_size[G_SIZE_ROWS] = 0;
	while ((r = read(fd, &g_line_above[g_size[G_SIZE_COLS]], 1)) > 0 &&
			g_line_above[g_size[G_SIZE_COLS]] != '\n')
		g_size[G_SIZE_COLS]++;
	if (r < 0 || g_size[G_SIZE_COLS] < 4 || !check_first_line(g_line_above))
		return (SOMETHING_IS_WRONG);
	g_size[G_SIZE_COLS] = 0;
	while ((read(fd, &g_line_current[g_size[G_SIZE_COLS]], 1)) &&
			g_line_current[g_size[G_SIZE_COLS]] != '\n')
		g_size[G_SIZE_COLS]++;
	parse_line(TRUE);
	return (EVERYTHING_IS_FINE);
}

int		min(int a, int b)
{
	return (a <= b ? a : b);
}

void	formula(int *state_above, int *state_current)
{
	int	i;

	i = 0;
	g_max_pos[1]++;
	while (i < g_size[G_SIZE_COLS])
	{
		if (g_line_current[i] == g_characters[1])
			state_current[i] = 0;
		else if (i == 0)
			state_current[i] = 1;
		else
		{
			state_current[i] = min(min(state_above[i],
										state_above[i - 1]),
										state_current[i - 1]) + 1;
		}
		if (state_current[i] > g_max_pos[0])
		{
			g_max_pos[0] = state_current[i];
			g_max_pos[2] = g_max_pos[1];
		}
		i++;
	}
}

int		parse_line(int init)
{
	static int	*state_above;
	static int	*state_current;
	int			i;

	if (init == TRUE)
	{
		state_above = malloc(sizeof(int) * (g_size[G_SIZE_COLS]));
		state_current = malloc(sizeof(int) * (g_size[G_SIZE_COLS]));
		i = 0;
		while (i < g_size[G_SIZE_COLS])
		{
			state_above[i] = 0;
			state_current[i] = 0;
			i++;
		}
	}
	formula(state_above, state_current);
	i = -1;
	if (init != TRUE)
	{
		while (++i < g_size[G_SIZE_COLS])
			state_above[i] = state_current[i];
		print_state(state_current);
	}
	return (EVERYTHING_IS_FINE);
}

int		parser(int fd)
{
	int		i;
	int		r;
	int		cols;

	i = 0;
	while (i < g_size[G_SIZE_ROWS] - 1)
	{
		parse_line((cols = 0));
		while ((r = read(fd, &g_line_current[cols], 1)) &&
				g_line_current[cols] != '\n')
		{
			ft_memcpy(g_line_above, g_line_current, MAX_SIZE);
			if (g_line_current[cols] != g_characters[0] &&
				g_line_current[cols] != g_characters[1] &&
				g_line_current[cols] != g_characters[2])
				return (SOMETHING_IS_WRONG);
			cols++;
		}
		if (cols != g_size[G_SIZE_COLS])
			return (SOMETHING_IS_WRONG);
		g_max_pos[2]++;
		i++;
	}
	return ((r = read(fd, &g_line_current[cols], 1) > 0) ? 0 : 1);
}
