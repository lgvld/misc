/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:59:59 by mede-mas          #+#    #+#             */
/*   Updated: 2019/07/25 18:11:38 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size_(t_list *begin_list)
{
	int		size;
	t_list	*current;

	size = 0;
	current = begin_list;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

t_list	*ft_list_at_(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*list;

	list = begin_list;
	if (!list)
		return (0);
	i = 0;
	while (i < nbr)
	{
		if (list->next)
			list = list->next;
		else
			return (0);
		i++;
	}
	return (list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	void	*temp;

	if (!begin_list)
		return ;
	i = 0;
	size = ft_list_size_(begin_list) - 1;
	while (i <= size / 2)
	{
		temp = ft_list_at_(begin_list, i)->data;
		ft_list_at_(begin_list, i)->data =
			ft_list_at_(begin_list, size - i)->data;
		ft_list_at_(begin_list, size - i)->data = temp;
		i++;
	}
}
