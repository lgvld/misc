/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:23:46 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/11 19:06:21 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

int		appears_only_once(char c, char *str)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
		{
			count++;
		}
		str++;
	}
	return (count == 1 ? 1 : 0);
}

int		base_is_valid(char *str)
{
	char *str_save;

	str_save = str;
	if (*str == '\0' || *(str + 1) == '\0')
	{
		return (0);
	}
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			return (0);
		}
		if (!appears_only_once(*str, str_save))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

void	ft_putnbr_base_rev(unsigned int nbr, char *base,
							unsigned int base_length)
{
	if (nbr / base_length != 0)
	{
		ft_putnbr_base_rev(nbr / base_length, base, base_length);
	}
	write(1, base + (nbr % base_length), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_length;

	if (!base_is_valid(base))
	{
		return ;
	}
	base_length = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_rev(-1 * nbr, base, base_length);
	}
	else
	{
		ft_putnbr_base_rev(nbr, base, base_length);
	}
}
