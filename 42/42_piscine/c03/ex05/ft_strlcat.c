/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:42:08 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/10 15:56:19 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*dest_save;
	char			*src_save;

	dest_save = dest;
	src_save = src;
	while (*src)
		src++;
	if (size == 0)
		return (src - src_save);
	while (*dest)
		dest++;
	if (size <= dest - dest_save)
		return ((src - src_save) + size);
	size -= dest - dest_save;
	while (size > 1 && *src_save)
	{
		*dest++ = *src_save++;
		size--;
	}
	*dest = '\0';
	return ((dest - dest_save) + (src - src_save));
}
