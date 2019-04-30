/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/30 17:39:58 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	swap_path(t_path **new, int size, int i, t_room *tab)
{
	int	tmp[size];
	int	save_len;
	int	j;

	j = -1;
	while (++j < size)
		tmp[j] = (*new)->path[i][j];
	save_len = (*new)->len[i];
	j = -1;
	while (++j < size)
	{
		(*new)->path[i][j] = (*new)->path[i + 1][j];
		if ((*new)->path[i][j] > 0)
			tab[(*new)->path[i][j]].taken = i + 1;
	}
	(*new)->len[i] = (*new)->len[i + 1];
	j = -1;
	while (++j < size)
	{
		(*new)->path[i + 1][j] = tmp[j];
		if (tmp[j] > 0)
			tab[tmp[j]].taken = i + 2;
	}
	(*new)->len[i + 1] = save_len;
}

void	sort_paths(t_path **new, int size, t_room *tab)
{
	int	i;
	
	i = 0;
	while (i < (*new)->path_n - 1)
	{
		if (((*new)->len[i] <= 0 || (*new)->len[i] > (*new)->len[i + 1])
				&& (*new)->len[i + 1] > 0)
		{
			swap_path(new, size, i, tab);
			i = -1;
		}
		i++;
	}
}

int		all_len_complete(t_path *new)
{
	int	i;

	i = 0;
	while (i < new->path_n)
	{
		if (new->len[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_nodes(t_room *tab, t_path **new, t_path *best, int **matrix)
{
	static int	node;
	int	i;
	int	j;
	int	lim;

	if (!(node) || (!(tab) && !(new) && !(best) && !(matrix)))
		node = 0;
	if (tab == 0 || new == 0 || best == 0 || matrix == 0)
		return (0);
	i = 0;
	node++;
	return (0);
}

int		way_is_possible(int **matrix, t_room *tab, t_path *new, int way)
{
	int	pos;
	int lim;
	int	best;
	int	i;

	pos = 0;
	while (new->path[way][pos + 1] != 0)
		pos++;
	lim = matrix[new->path[way][pos]][new->path[way][pos]];
	best = 0;
	i = 0;
	while (lim > 0)
	{
		if (matrix[new->path[way][pos]][i] == -1)
		{
			lim--;
			if (tab[i].taken <= 0 && tab[i].taken != (way + 1) * -1
					&& (!(best) || tab[best.wth] > tab[i].wth))
				best = i;
		}
		if (best == 1)
			break ;
		i++;
	}
	return (best);
}

int		find_path(int **matrix, t_room *tab, t_path **new, t_path *best)
{
	int	i;
	int	j;
	int	node;

	i = path_n - 1;
	while (i < (*new)->path_n)
	{
		j = 0;
		while (((*new)->path[i][j] = way_is_possible(matrix, tab, *new, i)) > 1)
		{
			if (matrix[(*new)->path[i][j]][(*new)->path[i][j]] > 2)
				(*new)->node[i][j] = (*new)->path[i][j];
			tab[(*new)->path[i][j++]].taken = i + 1;
		}
		if ((*new)->path[i][j] == 0)
		{
			if ((node = check_nodes(tab, new, best, matrix) > 0)
				efface path[i];
		}
		else
			len[i] = j;
	}
	i = check_nodes(0, 0, 0, 0);
	return (1);
}
