/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:05:53 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 11:07:05 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *new;

	i = 0;
	if (!(new = malloc(sizeof(int) * length)))
		return (NULL);
	while (i < length)
	{
		new[i] = f(tab[i]);
		i++;
	}
	return (new);
}
