/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:29:41 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/06 00:06:19 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	new_length;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	new_length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = ft_strnew(new_length);
	if (!new)
	{
		return (NULL);
	}
	while (*s1)
	{
		*new++ = *s1++;
	}
	while (*s2)
	{
		*new++ = *s2++;
	}
	return (new - new_length);
}
