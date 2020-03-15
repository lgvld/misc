/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:31:41 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 12:02:55 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

# include "do_op.h"

typedef struct		s_operation
{
	char const	*operation;
	void		(*f)(int, int);
}					t_operation;

extern t_operation	g_optab[5];

void				ft_add(int a, int b);
void				ft_sub(int a, int b);
void				ft_multiply(int a, int b);
void				ft_div(int a, int b);
void				ft_mod(int a, int b);

int					ft_atoi(char *str);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strcmp(char *s1, const char *s2);

#endif
