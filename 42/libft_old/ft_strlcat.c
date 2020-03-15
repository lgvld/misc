/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 14:58:30 by lgavalda          #+#    #+#             */
/*   Updated: 2017/12/30 20:22:44 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen((char *)src);
	if (size <= dst_length)
	{
		return (size + src_length);
	}
	while (*dst)
	{
		dst++;
		size--;
	}
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (dst_length + src_length);
}
