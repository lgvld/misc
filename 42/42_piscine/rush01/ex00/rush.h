/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:06:31 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/14 23:50:05 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define N 4

# define FALSE 0
# define TRUE !FALSE

extern int	g_clues[4 * N];
extern int	g_grid[N * N * N];

int			init_clues(char *argv);
void		init_grid(void);

void		print_clues(void);
void		print_grid(void);
int			print_case(int i);

int			assign(int	i, int value);
int			eliminate(int i, int value);
void		eliminate_rc(int i, int value, int preserve);
void		iterate(int i, int clue, int step, int j);
void		apply_clues(void);

int			pre_solve_row(void);
int			pre_solve_column(void);
void		pre_solve(void);

int			get_values(int i, int values[N]);
int			grid_is_valid(void);
int			in_case(int i, int value);
int			occurences_in_row(int i, int value);
int			occurences_in_column(int i, int value);

void		test(void);

#endif
