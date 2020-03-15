/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:43:03 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/19 15:24:55 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int		ft_strlen(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
		str++;
	return (str - str_save);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		return_(int value, char *str)
{
	ft_putstr(str);
	return (value);
}

int		main(int ac, char **av)
{
	int		fd;
	int		r;
	char	buffer[BUFFER_SIZE + 1];

	if (ac <= 1)
	{
		return (return_(-1, "File name missing.\n"));
	}
	if (ac > 2)
	{
		return (return_(-1, "Too many arguments.\n"));
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		return (return_(-1, "Cannot read file.\n"));
	}
	while ((r = read(fd, buffer, BUFFER_SIZE)))
	{
		ft_putstr(buffer);
		buffer[BUFFER_SIZE] = '\0';
	}
	close(fd);
	return (0);
}
