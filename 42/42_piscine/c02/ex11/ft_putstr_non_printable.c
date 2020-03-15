/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:07:27 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/11 14:34:16 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	static const char	*base;

	base = "0123456789abcdef";
	while (*str)
	{
		if (*str < ' ' || *str > '~')
		{
			write(1, "\\", 1);
			write(1, base + ((unsigned char)*str / 16), 1);
			write(1, base + ((unsigned char)*str % 16), 1);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
