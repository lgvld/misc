/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:46:14 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/20 21:10:34 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_is_valid(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_strlen(char *str)
{
	char *str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

int		nbr_length_(long nbr, char *base)
{
	int	count;
	int	base_length;

	if (nbr == 0)
	{
		return (1);
	}
	count = 1;
	if (nbr < 0)
	{
		count++;
	}
	base_length = ft_strlen(base);
	while ((nbr /= base_length) != 0)
	{
		count++;
	}
	return (count);
}

char	*rev(char *str, int str_length)
{
	int		i;
	char	temp;

	i = 0;
	while (i < str_length / 2)
	{
		temp = str[i];
		str[i] = str[str_length - 1 - i];
		str[str_length - 1 - i] = temp;
		i++;
	}
	return (str);
}

char	*itoa_base_rev(long nbr, char *base)
{
	int		nbr_length;
	int		base_length;
	char	*buffer;
	int		sign;

	nbr_length = nbr_length_(nbr, base);
	if (!(buffer = malloc(sizeof(char) * (nbr_length + 1))))
		return (NULL);
	buffer[nbr_length] = '\0';
	base_length = ft_strlen(base);
	if (nbr == 0 && (*buffer = base[0]))
		return (buffer);
	sign = 1;
	if (nbr < 0 && (sign = -1))
		nbr *= -1;
	while (nbr != 0)
	{
		*buffer = base[nbr % base_length];
		nbr /= base_length;
		buffer++;
	}
	if (sign == -1)
		*buffer++ = '-';
	return (rev(buffer - nbr_length, nbr_length));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	value;
	char	*buffer;

	if (!base_is_valid(base_from) || !base_is_valid(base_to))
	{
		return (NULL);
	}
	value = ft_atoi_base(nbr, base_from);
	buffer = itoa_base_rev(value, base_to);
	return (buffer);
}
