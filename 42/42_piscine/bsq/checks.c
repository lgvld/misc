/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:30:07 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 23:41:23 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	g_characters[3];

int		check_first_line(char *str)
{
	int		i;

	while (*str && *str >= '0' && *str <= '9')
		g_size[G_SIZE_ROWS] = g_size[G_SIZE_ROWS] * 10 + *str++ - '0';
	if (g_size[G_SIZE_ROWS] == 0)
		return (SOMETHING_IS_WRONG);
	i = 0;
	if (*str && *str != '\n')
		g_characters[i++] = *str++;
	if (*str && *str != '\n')
		g_characters[i++] = *str++;
	if (*str && *str != '\n')
		g_characters[i++] = *str++;
	if (*str != '\n')
		return (SOMETHING_IS_WRONG);
	return (check_characters());
}

int		check_characters(void)
{
	return (g_characters[0] != g_characters[1] &&
			g_characters[0] != g_characters[2] &&
			g_characters[1] != g_characters[2]);
}

void	print_state(int *state)
{
	int	i;

	i = 0;
	while (i < g_size[G_SIZE_COLS])
	{
		printf("%d ", state[i]);
		i++;
	}
	printf("\n");
}
