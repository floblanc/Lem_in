/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/22 13:49:16 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	clean_wth(t_room *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i].taken == 0)
			tab[i].wth = 0;
		i++;
	}
}

void	clean_some_taken(t_room *tab, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (tab[i].taken != 0)
			tab[i].taken = 0;
		i++;
	}
}

int		calc_size(t_room *tab)
{
	int		size;

	size = 0;
	while (tab[size].next)
		size++;
	size++;
	return (size);
}

void	copy_best(t_path *best, t_path *new, int size, t_room *tab)
{
	int	i;
	int	j;

	i = 0;
	(void)size;
	if (!(best))
		return ;
	while (i < best->path_n)
	{
		new->len[i] = best->len[i];
		j = 0;
		while (j < best->len[i])
		{
			new->path[i][j] = best->path[i][j];
			new->node[i][j] = best->node[i][j];
			tab[new->path[i][j]].taken = i + 1;
			j++;
		}
		new->path[i][best->len[i]] = 0;
		i++;
	}
}
