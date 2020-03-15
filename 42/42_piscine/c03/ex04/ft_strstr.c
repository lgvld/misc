/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:45:15 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/10 19:08:08 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULL
# define NULL (void *)0
#endif

char	*ft_strstr(char *str, char *to_find)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (to_find[b] == '\0')
		return (str);
	while (str[a])
	{
		b = 0;
		while ((str[a] == to_find[b]) && to_find[b] != '\0')
		{
			a++;
			b++;
		}
		if (to_find[b] == '\0')
			return (str + (a - b));
		a -= b;
		a++;
	}
	return (NULL);
}
