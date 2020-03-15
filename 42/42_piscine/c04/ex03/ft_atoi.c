/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:07:00 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/11 17:03:18 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int sign;
	int	value;

	sign = 1;
	value = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		sign *= *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		value = value * 10 + *str++ - '0';
	return (sign * value);
}
