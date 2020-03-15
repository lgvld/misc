/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:05:34 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 12:11:54 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	if (length < 2)
		return (1);
	i = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
		i++;
	asc = 0;
	desc = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			asc = 1;
		}
		if (f(tab[i], tab[i + 1]) > 0)
		{
			desc = 1;
		}
		i++;
	}
	return (asc == 1 && desc == 1 ? 0 : 1);
}
