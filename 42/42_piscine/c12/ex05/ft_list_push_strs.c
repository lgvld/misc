/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:08:00 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/25 17:08:19 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

t_list		*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*current;
	t_list	*new;

	i = 0;
	current = NULL;
	while (i < size)
	{
		new = ft_create_elem(strs[i]);
		new->next = current;
		current = new;
		i++;
	}
	return (current);
}
