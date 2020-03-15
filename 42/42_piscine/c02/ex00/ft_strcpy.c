/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:48:44 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/08 16:15:32 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_save;

	dest_save = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_save);
}
