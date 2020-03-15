/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:23:29 by lgavalda          #+#    #+#             */
/*   Updated: 2017/12/21 17:27:49 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	*position;

	if ((char)c == '\0')
	{
		return (ft_strchr(s, '\0'));
	}
	last = NULL;
	position = (char *)s;
	while ((position = ft_strchr(position, c)))
	{
		last = position;
		position++;
	}
	return (last);
}
