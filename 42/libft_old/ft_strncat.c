/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:31:20 by lgavalda          #+#    #+#             */
/*   Updated: 2017/12/28 15:03:33 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_copy;

	if (!*s2)
	{
		return (s1);
	}
	s1_copy = s1;
	while (*s1)
	{
		s1++;
	}
	while (n-- > 0 && *s2)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return (s1_copy);
}
