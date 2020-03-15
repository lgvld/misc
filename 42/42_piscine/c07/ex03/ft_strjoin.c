/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:08:11 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/17 22:29:10 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		str_length;
	int		i;
	char	*str;
	char	*sep_save;

	str_length = (size > 0) * (size - 1) * ft_strlen(sep);
	i = 0;
	while (i < size)
		str_length += ft_strlen(strs[i++]);
	if (!(str = malloc(sizeof(char) * (str_length + 1))))
		return (NULL);
	str[str_length] = '\0';
	if (size == 0)
		return (str);
	sep_save = sep;
	i = 0;
	while (i < size)
	{
		while (*strs[i])
			*str++ = *strs[i]++;
		if (i++ < size - 1 && (sep = sep_save))
			while (*sep)
				*str++ = *sep++;
	}
	return (str - str_length);
}
