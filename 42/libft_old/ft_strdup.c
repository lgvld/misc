/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:30:19 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/05 23:50:15 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_length;
	char	*s1_copy;

	s1_length = ft_strlen(s1);
	s1_copy = (char *)malloc(sizeof(char) * (s1_length + 1));
	if (!s1_copy)
	{
		return (NULL);
	}
	while (*s1)
	{
		*s1_copy++ = *s1++;
	}
	*s1_copy = '\0';
	return (s1_copy - s1_length);
}
