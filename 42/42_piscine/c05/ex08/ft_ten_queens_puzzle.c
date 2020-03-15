/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:57:20 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/18 22:06:42 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_safe(int i, int j, char *c)
{
	int	column;

	column = 0;
	while (column < i)
	{
		if (c[column] - '0' == j ||
			c[column] - '0' - j == column - i ||
			j - (c[column] - '0') == column - i)
		{
			return (0);
		}
		column++;
	}
	return (1);
}

int		solver(int i, char *c, int *s)
{
	int	res;
	int	j;

	if (i == 10)
	{
		write(1, c, 11);
		(*s)++;
		return (1);
	}
	res = 0;
	j = 0;
	while (j < 10)
	{
		if (is_safe(i, j, c))
		{
			c[i] = '0' + j;
			res = solver(i + 1, c, s) || res;
			c[i] = '\0';
		}
		j++;
	}
	return (res);
}

int		ft_ten_queens_puzzle(void)
{
	char	config[10 + 1];
	int		solutions;

	config[10] = '\n';
	solutions = 0;
	solver(0, config, &solutions);
	return (solutions);
}
