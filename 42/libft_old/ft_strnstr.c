/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:55:33 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/06 00:01:57 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	if (!*n)
	{
		return (h);
	}
	if (!*h || len == 0 || ft_strlen(n) > len)
	{
		return (NULL);
	}
	if (ft_strncmp(h, n, ft_strlen(n)) == 0)
	{
		return (h);
	}
	return (ft_strnstr(h + 1, n, len - 1));
}
