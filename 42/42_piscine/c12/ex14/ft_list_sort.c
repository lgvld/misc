/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-mas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:55:44 by mede-mas          #+#    #+#             */
/*   Updated: 2019/07/24 11:27:20 by mede-mas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*i;
	t_list	*j;
	t_list	*next;

	i = *begin_list;
	while (i)
	{
		j = *begin_list;
		while (j->next)
		{
			if ((*cmp)(j->data, j->next->data) > 0)
			{
				next = j->data;
				j->data = j->next->data;
				j->next->data = next;
			}
			j = j->next;
		}
		i = i->next;
	}
}
