/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:14:22 by mede-mas          #+#    #+#             */
/*   Updated: 2019/07/25 18:19:59 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

void	ft_list_sort_(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	void	*temp;

	if (begin_list == NULL || (current = *begin_list) == NULL)
		return ;
	while (current->next)
	{
		while (cmp(current->data, current->next->data) > 0)
		{
			temp = current->data;
			current->data = current->next->data;
			current->next->data = temp;
			current = *begin_list;
		}
		current = current->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*current;

	if (begin_list1 == NULL)
	{
		begin_list1 = &begin_list2;
		return ;
	}
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		ft_list_sort_(begin_list1, cmp);
		return ;
	}
	current = *begin_list1;
	while (current->next)
		current = current->next;
	current->next = begin_list2;
	ft_list_sort_(begin_list1, cmp);
}
