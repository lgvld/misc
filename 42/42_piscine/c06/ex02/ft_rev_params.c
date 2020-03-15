/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 00:58:49 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 01:04:48 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		while (*av[i])
		{
			write(1, av[i]++, 1);
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}