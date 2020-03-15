/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:40:05 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/14 23:18:07 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	get_values(int i, int values[N])
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (j < N)
	{
		if (g_grid[i * N + j] != 0)
		{
			if (values)
			{
				values[count] = g_grid[i * N + j];
			}
			count++;
		}
		j++;
	}
	if (values)
	{
		values[count] = -1;
	}
	return (count);
}

int	grid_is_valid(void)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while (i < N * N)
	{
		n = get_values(i, NULL);
		if (n == 0)
			return (0);
		if (n == 1)
			j++;
		i++;
	}
	if (j == N * N)
		return (1);
	return (2);
}

int	in_case(int i, int value)
{
	int	values[N];
	int	k;

	get_values(i, values);
	k = 0;
	while (values[k] != -1)
	{
		if (values[k] == value)
		{
			return (1);
		}
		k++;
	}
	return (0);
}

int	occurences_in_row(int i, int value)
{
	int	count;
	int	i_save;
	int	j;

	count = 0;
	i_save = i;
	i = (i / N) * N;
	j = 0;
	while (j < N)
	{
		if (in_case(i + j, value))
			count++;
		j++;
	}
	return (count);
}

int	occurences_in_column(int i, int value)
{
	int	count;
	int	i_save;
	int	j;

	count = 0;
	i_save = i;
	i = i % N;
	j = 0;
	while (j < N)
	{
		if (in_case(i + j * N, value))
			count++;
		j++;
	}
	return (count);
}
