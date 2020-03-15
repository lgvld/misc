/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:41:15 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 23:33:09 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FALSE 0
# define TRUE (!FALSE)

# define SOMETHING_IS_WRONG 0
# define EVERYTHING_IS_FINE !(SOMETHING_IS_WRONG)

# define G_SIZE_ROWS 0
# define G_SIZE_COLS 1

# define MAX_SIZE 1024

extern char	g_line_above[MAX_SIZE + 1];
extern char	g_line_current[MAX_SIZE + 1];
extern int	g_size[2];
extern char	g_characters[3];
extern int	g_max_pos[3];

int			init_parser(int fd);
int			parser(int fd);

int			check_first_line(char *str);
int			check_characters(void);
int			parse_line(int init);
void		print_state(int *state);

int			ft_atoi(char *str);
void		*ft_memcpy(void *dest, const void *src, unsigned int n);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		print_solved(char *filepath);

#endif
