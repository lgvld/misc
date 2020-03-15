/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:06:35 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 16:20:23 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max || !(array = malloc(sizeof(int) * (max - min))))
	{
		return (NULL);
	}
	i = min;
	while (i < max)
	{
		*array++ = i++;
	}
	return (array - (max - min));
}
