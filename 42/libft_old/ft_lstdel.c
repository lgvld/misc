/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:33:52 by lgavalda          #+#    #+#             */
/*   Updated: 2018/01/11 23:12:41 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*previous;

	current = *alst;
	while (current)
	{
		del(current->content, current->content_size);
		previous = current;
		current = current->next;
		free(previous);
	}
	*alst = NULL;
}
