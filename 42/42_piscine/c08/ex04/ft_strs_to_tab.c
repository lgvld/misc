/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:05:46 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/22 17:26:31 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

char				*ft_strdup(char *src)
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;

	if (!(tab = malloc(sizeof(struct s_stock_str) * (ac + 1))))
	{
		return (NULL);
	}
	tab[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (tab[i].copy == NULL)
		{
			return (NULL);
		}
		i++;
	}
	return (tab);
}
