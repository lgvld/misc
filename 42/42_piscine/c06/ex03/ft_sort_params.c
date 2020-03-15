/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 01:07:17 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 01:25:33 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	main(int ac, char **av)
{
	int		i;
	char	*av_temp;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			av_temp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = av_temp;
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		while (*av[i])
			write(1, av[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
