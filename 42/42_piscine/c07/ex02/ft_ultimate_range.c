/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:20:37 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 19:06:53 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(*range = malloc(sizeof(int) * (max - min))))
	{
		return (-1);
	}
	i = min;
	while (i < max)
	{
		**range = i;
		(*range)++;
		i++;
	}
	*range -= max - min;
	return (max - min);
}
