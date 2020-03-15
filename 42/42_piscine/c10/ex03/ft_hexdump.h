/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:24:52 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/23 01:46:58 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE !EXIT_SUCCESS

# define BUFFER_SIZE 16384

# define BASE "0123456789abcdef"
# define SPACES "                                                "

void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strncmp_(char *s1, char *s2, unsigned int n);

#endif
