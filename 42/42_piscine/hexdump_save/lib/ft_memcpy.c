/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:31:53 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/21 17:38:11 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_hexdump.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	void	*dest_save;

	dest_save = dest;
	while (n > 0)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		n--;
	}
	return (dest_save);
}
