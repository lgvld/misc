/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 23:30:27 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 21:08:10 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <stdlib.h>
# include <libgen.h>

# define BUFFER_SIZE 4096

int		stdin_size(void);
int		live_stdin(char **av);
int		ft_atoi(char *str);
int		ft_error(char *av0, int ac, char *arg);
void	ft_putstr_error(char *str);
int		printed_previously(int error);
int		return_dir_error(char **av);
int		return_permission_error(char *av0, char *arg);
int		return_404_error(char *av0, char *arg);

#endif
