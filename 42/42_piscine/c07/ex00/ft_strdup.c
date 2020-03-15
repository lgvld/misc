/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:51:07 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 16:05:14 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*src_save;
	char	*copy;

	src_save = src;
	while (*src)
		src++;
	if (!(copy = malloc(sizeof(char) * ((src - src_save) + 1))))
	{
		return (NULL);
	}
	copy[src - src_save] = '\0';
	src = src_save;
	while (*src)
	{
		*copy++ = *src++;
	}
	return (copy - (src - src_save));
}
