/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:44:54 by lgavalda          #+#    #+#             */
/*   Updated: 2018/01/11 23:53:10 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2 && ft_strcmp(s1, s2) == 0)
	{
		return (1);
	}
	return (0);
}
