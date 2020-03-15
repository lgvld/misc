/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:20:16 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/14 23:41:44 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		pre_solve_row(void)
{
	int	i;
	int	values[N];
	int	k;

	i = 0;
	while (i < N * N)
	{
		if (get_values(i, values) > 1)
		{
			k = 0;
			while (values[k] != -1)
			{
				if (occurences_in_row(i, values[k]) == 1)
				{
					assign(i, values[k]);
				}
				k++;
			}
		}
		i++;
	}
	return (FALSE);
}

int		pre_solve_column(void)
{
	int	i;
	int	values[N];
	int	k;

	i = 0;
	while (i < N * N)
	{
		if (get_values(i, values) > 1)
		{
			k = 0;
			while (values[k] != -1)
			{
				if (occurences_in_column(i, values[k]) == 1)
				{
					assign(i, values[k]);
				}
				k++;
			}
		}
		i++;
	}
	return (FALSE);
}

void	pre_solve(void)
{
	pre_solve_row();
	pre_solve_column();
}
