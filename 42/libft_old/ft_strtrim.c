/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:43:56 by lgavalda          #+#    #+#             */
/*   Updated: 2018/01/13 18:29:19 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*from;
	char	*to;

	if (!s)
	{
		return (NULL);
	}
	from = (char *)s;
	while (*from && (*from == ' ' || *from == '\n' || *from == '\t'))
	{
		from++;
	}
	to = from;
	while (*to && *(to + 1))
	{
		to++;
	}
	while (*to && (*to == ' ' || *to == '\n' || *to == '\t'))
	{
		to--;
	}
	return (ft_strsub(s, (size_t)(from - s), (size_t)(to - from + 1)));
}
