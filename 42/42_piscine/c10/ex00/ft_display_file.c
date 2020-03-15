/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:43:03 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 00:42:55 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

int		error_(int value, char *str)
{
	while (*str)
		write(2, str++, 1);
	return (value);
}

int		main(int ac, char **av)
{
	int		fd;
	int		r;
	char	c;

	if (ac <= 1)
	{
		return (error_(-1, "File name missing.\n"));
	}
	if (ac > 2)
	{
		return (error_(-1, "Too many arguments.\n"));
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		return (error_(-1, "Cannot read file.\n"));
	}
	while ((r = read(fd, &c, 1)))
	{
		write(1, &c, 1);
	}
	close(fd);
	return (0);
}
