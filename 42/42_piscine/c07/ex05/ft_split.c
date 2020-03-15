/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:49:14 by lgavalda          #+#    #+#             */
/*   Updated: 2019/07/17 22:34:18 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE

int		in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
		{
			return (TRUE);
		}
		charset++;
	}
	return (FALSE);
}

int		copy_next(char **from, char **to, char *charset)
{
	int		length;

	while (**from && in_charset(**from, charset))
	{
		(*from)++;
	}
	length = 0;
	while (**from && !in_charset(**from, charset))
	{
		if (to != NULL)
		{
			**to = **from;
			(*to)++;
		}
		(*from)++;
		length++;
	}
	return (length);
}

char	**create_array(char *str, char *charset)
{
	int		count;
	char	**array;

	count = 0;
	while ((copy_next(&str, NULL, charset)))
	{
		count++;
	}
	if (!(array = malloc(sizeof(char *) * (count + 1))))
	{
		return (NULL);
	}
	array[count] = NULL;
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	char	**array_save;
	int		length;

	if (!(array = create_array(str, charset)))
	{
		return (NULL);
	}
	array_save = array;
	while (*array != NULL)
	{
		length = copy_next(&str, NULL, charset);
		*array = malloc(sizeof(char) * (length + 1));
		(*array)[length] = '\0';
		str -= length;
		copy_next(&str, array, charset);
		*array -= length;
		array++;
	}
	return (array_save);
}
