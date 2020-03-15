/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:25:59 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/08 22:06:21 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*str_save;

	str_save = str;
	if (*str && *str >= 'a' && *str <= 'z')
	{
		*str -= 'a' - 'A';
		str++;
	}
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 'a' - 'A';
		}
		if (*str >= 'a' && *str <= 'z' &&
			!(*(str - 1) >= 'a' && *(str - 1) <= 'z') &&
			!(*(str - 1) >= 'A' && *(str - 1) <= 'Z') &&
			!(*(str - 1) >= '0' && *(str - 1) <= '9'))
		{
			*str -= 'a' - 'A';
		}
		str++;
	}
	return (str_save);
}
