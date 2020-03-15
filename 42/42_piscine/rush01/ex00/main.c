/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:12:47 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/16 22:25:21 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	g_clues[4 * N];
int	g_grid[N * N * N];

int	main(int argc, char **argv)
{
	if (argc != 2 || init_clues(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid();
	print_clues();
	apply_clues();
	// assign(1,` 4);
	pre_solve();
	print_grid();
	return (0);
}
