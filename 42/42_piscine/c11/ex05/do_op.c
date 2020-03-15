/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:19:45 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 12:02:33 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

t_operation	g_optab[] = {
	{"+", &ft_add},
	{"-", &ft_sub},
	{"*", &ft_multiply},
	{"/", &ft_div},
	{"%", &ft_mod}
};

int		check_op(char *str)
{
	if (!(*str == '+' || *str == '-' || *str == '/' ||
			*str == '*' || *str == '%') ||
			(*str && *(str + 1) != '\0'))
	{
		return (0);
	}
	return (1);
}

void	do_op(int a, int b, char *op)
{
	unsigned	i;

	i = 0;
	while (i < sizeof(g_optab) / sizeof(g_optab[0]))
	{
		if (ft_strcmp(op, g_optab[i].operation) == 0)
		{
			g_optab[i].f(a, b);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	ft_putnbr(0);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 4)
	{
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	do_op(a, b, argv[2]);
	return (0);
}
