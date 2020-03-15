/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 00:55:23 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 00:58:22 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	(void)ac;
	while (*av[0])
	{
		write(1, av[0]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}