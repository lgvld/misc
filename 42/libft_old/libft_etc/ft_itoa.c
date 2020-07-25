/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 22:01:01 by lgavalda          #+#    #+#             */
/*   Updated: 2018/02/06 00:11:30 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		n_length;
	int		n_copy;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_length = 1;
	n_copy = n;
	while ((n_copy /= 10) != 0)
		n_length++;
	if (n < 0)
		n_length++;
	if (!(result = ft_strnew(n_length)))
		return (NULL);
	n_copy = n;
	if (n < 0)
	{
		*result = '-';
		n *= -1;
	}
	result += n_length - 1;
	*result-- = n % 10 + '0';
	while ((n /= 10) != 0)
		*result-- = n % 10 + '0';
	return (n_copy >= 0 ? result + 1 : result);
}
