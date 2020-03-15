/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:03:58 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/24 12:07:42 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*buffer;

	i = 0;
	while (tab[i + 1])
	{
		while (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			buffer = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buffer;
			i = 0;
		}
		i++;
	}
}
