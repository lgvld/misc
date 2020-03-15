/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:21:14 by lgavalda          #+#    #+#             */
/*   Updated: 2018/06/12 15:31:55 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int n, unsigned int power)
{
	int	n_copy;

	if (power == 0)
		return (1);
	n_copy = n;
	while (power-- > 1)
		n *= n_copy;
	return (n);
}
