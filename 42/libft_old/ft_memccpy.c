/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:21:16 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/05 23:44:19 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_copy;

	src_copy = (unsigned char *)src;
	while (n > 0)
	{
		if ((*(unsigned char *)dst++ = *src_copy++) == (unsigned char)c)
		{
			return (dst);
		}
		n--;
	}
	return (NULL);
}
