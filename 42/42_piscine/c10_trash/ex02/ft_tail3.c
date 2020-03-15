/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:16:18 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 21:07:53 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	return_dir_error(char **av)
{
	ft_putstr_error(basename(av[0]));
	ft_putstr_error(": stdin: Is a directory\n");
	return (1);
}

int	return_permission_error(char *av0, char *arg)
{
	ft_putstr_error(av0);
	ft_putstr_error(": ");
	ft_putstr_error(arg);
	ft_putstr_error(": Permission denied\n");
	return (1);
}

int	return_404_error(char *av0, char *arg)
{
	ft_putstr_error(av0);
	ft_putstr_error(": ");
	ft_putstr_error(arg);
	ft_putstr_error(": No such file or directory\n");
	return (1);
}
