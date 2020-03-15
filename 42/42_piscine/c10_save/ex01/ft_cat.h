/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 01:35:21 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/22 02:02:39 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

# define BUFFER_SIZE 4096

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_display_file(char *av0, char *arg);
void	ft_cat(void);
int		ft_error(char *av0, char *arg);

#endif
