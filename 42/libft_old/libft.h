/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 09:04:01 by lgavalda          #+#    #+#             */
/*   Updated: 2018/06/12 15:22:06 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_power(int n, unsigned int power);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);

#endif
