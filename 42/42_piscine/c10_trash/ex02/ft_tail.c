/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 02:15:09 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 21:19:19 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_tail.h"

int		ft_atoi(char *str)
{
	int sign;
	int value;

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

void	display_names(int i, int ac, char **av)
{
	int			j;
	static int	fail;

	j = 0;
	fail = 0;
	if (ac > 4)
	{
		if (printed_previously(999))
			write(1, "\n==> ", 5);
		else
			write(1, "==> ", 4);
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, " <==\n", 5);
	}
}

int		filesize(int i, char **av)
{
	int		fd;
	char	buffer;
	int		size;

	size = 0;
	fd = open(av[i], O_RDONLY);
	while (read(fd, &buffer, 1))
		size++;
	close(fd);
	return (size);
}

void	display_file(int i, int fd, int ac, char **av)
{
	char	buffer;
	long	bytes;
	int		count;
	int		size;

	size = filesize(i, av);
	count = 0;
	bytes = ft_atoi(av[2]);
	display_names(i, ac, av);
	if (av[2][0] == '+')
	{
		while (count != bytes - 1)
			count += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
	else
	{
		while (count < (size - bytes))
			count += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	int		err;

	printf("[%d]\n", ac);
	if (ac < (i = 3))
		return (-1);
	while (i < ac)
	{
		fd = open(av[i], O_RDWR);
		err = ft_error(basename(av[0]), ac, av[i]);
		if (ac == 3)
			return (live_stdin(av));
		if (fd >= 0)
			display_file(i, fd, ac, av);
		printed_previously(err);
		close(fd);
		i++;
	}
	return (0);
}
