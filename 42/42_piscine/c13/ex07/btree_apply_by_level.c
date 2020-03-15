/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:20:58 by mede-mas          #+#    #+#             */
/*   Updated: 2019/07/25 18:50:26 by lgavalda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_level_count_rec(t_btree *root, int *max, int level)
{
	if (!root)
		return ;
	if (level > *max)
		*max = level;
	btree_level_count_rec(root->left, max, level + 1);
	btree_level_count_rec(root->right, max, level + 1);
}

int		btree_level_count(t_btree *root)
{
	int	max;

	if (!root)
		return (0);
	max = 0;
	btree_level_count_rec(root->left, &max, 2);
	btree_level_count_rec(root->right, &max, 2);
	return (max);
}

void	btree_apply_to(t_btree *root, int i, int *level,
						void (*applyf)(void *item, int current_level,
						int is_first_elem))
{
	if (!root)
		return ;
	if (i == (*level % 1000))
	{
		(*applyf)(root->item, *level % 1000, *level > 1000);
		*level = (*level > 1000) ? *level - 1000 : *level;
	}
	else
	{
		btree_apply_to(root->left, i + 1, level, applyf);
		btree_apply_to(root->right, i + 1, level, applyf);
	}
}

void	btree_apply_by_level(t_btree *root,
								void (*applyf)(void *item,
								int current_level,
								int is_first_elem))
{
	int	i;
	int	level;

	if (root)
		(*applyf)(root->item, 0, 1);
	i = 0;
	while (i < btree_level_count(root))
	{
		level = 1000 + i + 1;
		btree_apply_to(root, 0, &level, applyf);
		i++;
	}
}
