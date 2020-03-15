/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:38:36 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/07 21:51:32 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char *src_save;

	src_save = src;
	while (*src && size > 1)
	{
		*dest++ = *src++;
		size--;
	}
	if (size > 0)
	{
		*dest = '\0';
	}
	size = 0;
	while (*src_save++)
	{
		size++;
	}
	return (size);
}
