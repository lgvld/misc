/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:46:25 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/08 14:41:53 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*str_save;

	str_save = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 'a' - 'A';
		}
		str++;
	}
	return (str_save);
}
