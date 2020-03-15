/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 23:04:14 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 21:20:04 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

#include "ft_tail.h"

int		live_stdin(char **av)
{
	char	*buffer;
	char	c;
	int		bytes;
	int		r;
	int		count;

	if (errno == EISDIR)
		return (return_dir_error(av));
	bytes = ft_atoi(av[2]);
	if (bytes == 0 && errno != EISDIR)
	{
		while ((r = read(0, &c, 1)) && c != EOF)
			;
		return (1);
	}
	if (!(buffer = malloc(sizeof(char) * bytes)))
		return (1);
	count = 0;
	while ((r = read(0, buffer + count % bytes, 1)) &&
			buffer[count % bytes] != EOF)
		count++;
	if (count >= bytes)
		write(1, buffer + count % bytes, bytes - count % bytes);
	write(1, buffer, count % bytes);
	return (0);
}

int		printed_previously(int error)
{
	static int	printed;

	if (error == 0)
		printed = 1;
	return (printed);
}

int		ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
}

int		ft_error(char *av0, int ac, char *arg)
{
	if (errno == EACCES)
	{
		return_permission_error(av0, arg);
		return (1);
	}
	if (errno == EISDIR)
	{
		if (ac > 4)
		{
			if (printed_previously(999))
				write(1, "\n==> ", 5);
			else
				write(1, "==> ", 4);
			ft_putstr_error(arg);
			write(1, " <==\n", 5);
			return (0);
		}
	}
	if (errno == ENOENT)
	{
		return_404_error(av0, arg);
		return (1);
	}
	return (0);
}
