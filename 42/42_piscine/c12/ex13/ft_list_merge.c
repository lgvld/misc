/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:48:27 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/25 17:50:46 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (*begin_list1)
	{
		current = *begin_list1;
		while (current->next)
			current = current->next;
		current->next = begin_list2;
		return ;
	}
	*begin_list1 = begin_list2;
}
