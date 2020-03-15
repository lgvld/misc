/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:17:08 by lgavalda          #+#    #+#             */
/*   Updated: 2017/12/13 18:14:50 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (n-- > 0 && *(unsigned char *)s1++ == *(unsigned char *)s2++)
	{
	}
	return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
}
