/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:43:13 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/06 00:03:34 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	s_length;
	char	*new_s;

	if (!f)
	{
		return (NULL);
	}
	s_length = ft_strlen(s);
	new_s = ft_strnew(s_length);
	if (!new_s)
	{
		return (NULL);
	}
	while (*s)
	{
		*new_s++ = f(*s++);
	}
	return (new_s - s_length);
}
