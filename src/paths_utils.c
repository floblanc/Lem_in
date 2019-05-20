/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:58:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/21 00:16:34 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ant_walk(t_path *best, t_room *tab, int j)
{
	int i;

	i = best->len[j] - 1;
	while (i > 0)
	{
		tab[best->path[j][i]].taken = tab[best->path[j][i - 1]].taken;
		i--;
	}
}

void	use_path2(t_path *best, t_room *tab, int j, int *i)
{
	ant_walk(best, tab, j);
	if (best->path[j][best->len[j]] > 0)
	{
		tab[best->path[j][0]].taken = (*i)++;
		(tab[0].taken)--;
	}
	else
		tab[best->path[j][0]].taken = 0;
	(best->path[j][best->len[j]]) -= 1;
}

void	use_path(t_path *best, t_room *tab, int size)
{
	int	i;
	int	j;
	int	first;

	i = 1;
	j = 1;
	if (!(best))
		return ;
	while (j < size)
		tab[j++].taken = 0;
	while ((best->step)-- > 0)
	{
		j = -1;
		first = 1;
		write(1, "\n", 1);
		while (++j < best->path_n)
		{
			use_path2(best, tab, j, &i);
			write_path(best, tab, j, &first);
		}
	}
	write(1, "\n", 1);
}

int		calc_step(t_path *struc, int ant_n, int path_n)
{
	int	i;
	int	best;
	while (ant_n > 0)
	{
		i = 1 ;
		best = 0;
		while (i < path_n)
		{
			if (struc->len[i] + struc->path[i][struc->len[i]]
					< struc->len[best] + struc->path[best][struc->len[best]])
			{
				best = i;
				break ;
			}
			i++;
		}
		ant_n--;
		struc->path[best][struc->len[best]]++;
	}
	struc->step = struc->len[0] + (struc->path[0][struc->len[0]] - 1);
	return (struc->step);
}
