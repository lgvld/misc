/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:01:02 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/11 17:08:39 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	pos_in_base(char c, char *base)
{
	char	*base_save;

	base_save = base;
	while (*base && *base != c)
		base++;
	return (*base == '\0' && c != '\0' ? -1 : base - base_save);
}

int	base_is_valid(char *base)
{
	char *base_save;

	base_save = base;
	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || is_space(*base))
			return (0);
		if (pos_in_base(*base, base + 1) != -1)
			return (0);
		base++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	value;
	int	base_length;
	int	pos;

	if (!base_is_valid(base))
		return (0);
	sign = 1;
	value = 0;
	base_length = pos_in_base('\0', base);
	while (*str && is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
		sign *= *str++ == '-' ? -1 : 1;
	while (*str)
	{
		if ((pos = pos_in_base(*str++, base)) == -1)
			break ;
		value = value * base_length + pos;
	}
	return (sign * value);
}
