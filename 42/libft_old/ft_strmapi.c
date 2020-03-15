/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:41:34 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/06 00:03:57 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_length;
	char	*new_s;
	int		i;

	if (!f)
	{
		return (NULL);
	}
	s_length = ft_strlen((char *)s);
	new_s = ft_strnew(s_length);
	if (!new_s)
	{
		return (NULL);
	}
	i = 0;
	while (*s)
	{
		*new_s++ = f(i++, *s++);
	}
	return (new_s - s_length);
}
