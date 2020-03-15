/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:47:30 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/11 19:28:28 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci_term(int a, int b, int index)
{
	if (index == 0)
	{
		return (a);
	}
	return (ft_fibonacci_term(b, a + b, index - 1));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	return (ft_fibonacci_term(0, 1, index));
}
