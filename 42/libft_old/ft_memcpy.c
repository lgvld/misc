/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:00:47 by lgavalda          #+#    #+#             */
/*   Updated: 2018/01/11 22:15:41 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_copy;

	if (n == 0 || dst == src)
	{
		return (dst);
	}
	dst_copy = (char *)dst;
	while (n > 0)
	{
		*(char *)dst++ = *(char *)src++;
		n--;
	}
	return (dst_copy);
}
