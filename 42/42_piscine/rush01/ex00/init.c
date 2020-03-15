/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:42:38 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/14 23:45:44 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		init_clues(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			g_clues[i] = *str - '0';
			i++;
		}
		str++;
	}
	return (i == 4 * N);
}

void	init_grid(void)
{
	int	i;

	i = 0;
	while (i < N * N * N)
	{
		g_grid[i] = i % N + 1;
		i++;
	}
}
