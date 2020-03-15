/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:28:42 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/25 17:39:58 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*list;

	if (!*begin_list || !((*begin_list)->next))
		return ;
	list = *begin_list;
	temp1 = list->next;
	temp2 = temp1->next;
	list->next = NULL;
	temp1->next = list;
	while (temp2)
	{
		list = temp1;
		temp1 = temp2;
		temp2 = temp2->next;
		temp1->next = list;
	}
	*begin_list = temp1;
}
