/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:09:09 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/25 17:09:18 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	current = begin_list;
	if (!current)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		if (current->next)
			current = current->next;
		else
			return (NULL);
		i++;
	}
	return (current);
}
