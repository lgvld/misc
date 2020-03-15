/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:04:02 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/05 23:57:51 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	if (!*n)
	{
		return (h);
	}
	if (!*h)
	{
		return (NULL);
	}
	if (ft_strncmp(h, n, ft_strlen(needle)) == 0)
	{
		return (h);
	}
	return (ft_strstr(h + 1, n));
}
