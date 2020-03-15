/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:01:16 by lgavalda          #+#    #+#             */
/*   Updated: 2017/12/30 21:23:12 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dst_copy;

	dst_copy = dst;
	while (len-- > 0)
	{
		if (*src)
		{
			*dst++ = *src++;
		}
		else
		{
			*dst++ = '\0';
		}
	}
	return (dst_copy);
}
