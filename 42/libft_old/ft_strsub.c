/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:16:07 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/05 23:58:17 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*substring;
	size_t	len_copy;

	if (!s1)
	{
		return (NULL);
	}
	substring = ft_strnew(len);
	if (!substring)
	{
		return (NULL);
	}
	while (start-- > 0)
	{
		s1++;
	}
	len_copy = len;
	while (len-- > 0)
	{
		*substring++ = *s1++;
	}
	return (substring - len_copy);
}
