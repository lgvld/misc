/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 01:37:08 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 20:13:01 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_read(int fd, char *buffer)
{
	int r;

	while ((r = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[r] = '\0';
		ft_putstr(buffer);
	}
}

int		ft_error(char *av0, char *arg)
{
	if (errno == EACCES)
	{
		ft_putstr_error(av0);
		ft_putstr_error(": ");
		ft_putstr_error(arg);
		ft_putstr_error(": Permission denied\n");
		return (1);
	}
	if (errno == EISDIR)
	{
		ft_putstr_error(av0);
		ft_putstr_error(": ");
		ft_putstr_error(arg);
		ft_putstr_error(": Is a directory\n");
		return (1);
	}
	if (errno == ENOENT)
	{
		ft_putstr_error(av0);
		ft_putstr_error(": ");
		ft_putstr_error(arg);
		ft_putstr_error(": No such file or directory\n");
		return (1);
	}
	return (0);
}

void	ft_display_file(char *av0, char *arg)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];

	errno = 0;
	fd = open(arg, O_RDWR);
	if (fd == -1)
	{
		if (arg[0] == '-' && arg[1] == '\0')
			ft_cat();
		else
			ft_error(av0, arg);
	}
	else
		ft_read(fd, buffer);
	if (close(fd) == -1)
		ft_putstr("");
}

void	ft_cat(void)
{
	int		r;
	char	buffer[BUFFER_SIZE + 1];

	r = 0;
	while ((r = read(0, buffer, BUFFER_SIZE)))
	{
		buffer[r] = '\0';
		ft_putstr(buffer);
	}
}

int		main(int ac, char *av[])
{
	int i;

	i = 1;
	if (ac < 2)
		ft_cat();
	else
	{
		while (i < ac)
		{
			ft_display_file(basename(av[0]), av[i]);
			i++;
		}
	}
	return (0);
}
