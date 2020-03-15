/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 00:59:35 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 23:00:02 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
	{
		str++;
	}
	return (str - str_save);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_atoi(char *str)
{
	int sign;
	int	value;

	sign = 1;
	value = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		sign *= *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		value = value * 10 + *str++ - '0';
	return (sign * value);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	void	*dest_save;

	dest_save = dest;
	while (n > 0)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		n--;
	}
	return (dest_save);
}

void	print_solved(char *filepath)
{
	int		fd;
	int		r;
	char	c;

	fd = open(filepath, O_RDONLY);
	while ((r = read(fd, &c, 1)) && c != '\n')
		;
	while ((r = read(fd, &c, 1)))
	{
		write(1, &c, 1);
	}
	close(fd);
}
