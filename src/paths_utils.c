/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:01:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/09 13:30:32 by floblanc         ###   ########.fr       */
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
void	use_path(t_path *best, t_room *tab, int path_n)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (tab[j].next)
		tab[j++].taken = 0;
	tab[j].taken = 0;
	while (best->step-- > 0)
	{
		j = 0;
		while (j < path_n)
		{
			ant_walk(best, tab, j);
			if (best->path[best->len[j]] > 0)
				best->path[j].taken = i++;
			else
				best->path[j].taken = 0;
			best->path[best->len[j]]--;
			write_path(best->path, tab, j, path_n);
			j++;
		}
	}
}

void	stock_len(t_path *new, int path_n)
{
	int i;
	int	j;

	i = 0;
	while (i < path_n)
	{
		j = 0;
		while (new->path[i][j] != 0)
			j++;
		new->len[i] = j;
		i++;
	}
}

void	init_t_path(t_path *struc, int size, int path_n)
{
	int	i;
	int	j;

	i = 0;
	if (!(struc = (t_path*)malloc(sizeof(t_path) * 1)))
		exit(0);
	if (!(struc->path = (int**)malloc(sizeof(int*) * path_n)))
		exit(0);
	while (i < path_n)
	{
		if (!(struc->path[i] = (int*)malloc(sizeof(int) * size)))
			exit(0);
		j = 0;
		while (j < size)
		{
			struc->path[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		calc_step(t_path *struc, int ant_n, int path_n)
{
	int	i;

	if (!(struc->len[path_n - 1]))
		return (0);
	struc->path[0][struc->len[0]] = ant_n;
	if (path_n == 1)
	{
		struc->step = struc->len[0] + struc->path[0][struc->len[0]] - 1;
		return (struc->step);
	}
	i = 1;
	while (i > 0)
	{
		i = 0;
		while ((i < path_n - 1) && (struc->len[i] + struc->path[i][struc->len[i]] - 1 >= struc->len[i + 1] + struc->path[i + 1][struc->len[i + 1]]))
			i++;
		if (i > 0)
		{
			struc->path[0][struc->len[0]]--;
			struc->path[i][struc->len[i]]++;
		}
	}
	struc->step = struc->len[1] + struc->path[1][struc->len[1]] - 1;
	return (struc->step);
}
