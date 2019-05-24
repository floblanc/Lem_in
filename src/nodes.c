/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:44:27 by maginist          #+#    #+#             */
/*   Updated: 2019/05/24 13:50:14 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		node_is_possible(int **matrix, t_room *tab, int room, int way)
{
	int		i;
	int		lim;
	int		best;

	i = 0;
	best = 0;
	lim = matrix[room][room];
	while (lim > 0)
	{
		if (matrix[room][i] == -1)
		{
			lim--;
			if (i != 0 && tab[i].taken == 0 && tab[i].used != way + 1
					&& (!(best) || tab[best].wth > tab[i].wth))
				best = i;
		}
		if (best == 1)
			break ;
		i++;
	}
	return (best);
}

int		no_node(t_path *new, t_path *best, int **matrix)
{
	int				i;

	i = 0;
	while (best->path[new->path_n - 2][i] != 1
			&& best->path[new->path_n - 2][i] != 0)
	{
		if (matrix[best->path[new->path_n - 2][i]]
				[best->path[new->path_n - 2][i]] > 2)
			return (0);
		i++;
	}
	return (1);
}

void	check_first_node(t_path *new, t_room *tab, int size)
{
	int				i;

	i = 0;
	while (i < size)
		if (tab[i++].used == new->path_n - 1)
			return ;
	i = 1;
	while (new->node[new->path_n - 2][i - 1] == 0)
		i++;
	tab[new->path[new->path_n - 2][i]].used = new->path_n - 1;
	while (new->path[new->path_n - 2][i] != 0)
	{
		tab[new->path[new->path_n - 2][i]].taken = 0;
		new->node[new->path_n - 2][i] = 0;
		new->path[new->path_n - 2][i++] = 0;
	}
}

void	check_nodes2(t_room *tab, t_path **n, t_path *best, int *i)
{
	static int	size;

	size = (!(size)) ? calc_size(tab) : size;
	while ((*n)->path[(*n)->path_n - 1][(*i)] != 0)
	{
		tab[(*n)->path[(*n)->path_n - 1][(*i)]].taken = 0;
		(*n)->node[(*n)->path_n - 1][(*i)] = 0;
		(*n)->path[(*n)->path_n - 1][(*i)++] = 0;
	}
	(*i) = size - 1;
	check_first_node(*n, tab, size);
	while ((*n)->node[(*n)->path_n - 2][(*i)] == 0
			|| (*n)->node[(*n)->path_n - 2][(*i)]
			!= best->node[(*n)->path_n - 2][(*i)])
	{
		if ((*n)->path[(*n)->path_n - 2][(*i)] != 0)
			tab[(*n)->path[(*n)->path_n - 2][(*i)]].taken = 0;
		if (best->node[(*n)->path_n - 2][(*i) - 1] != 0
				&& (*n)->node[(*n)->path_n - 2][(*i) - 1]
				== best->node[(*n)->path_n - 2][(*i) - 1])
			tab[(*n)->path[(*n)->path_n - 2][(*i)]].used = (*n)->path_n - 1;
		(*n)->node[(*n)->path_n - 2][(*i)] = 0;
		(*n)->path[(*n)->path_n - 2][(*i)--] = 0;
	}
	(*i)--;
}

int		check_nodes(t_room *tab, t_path **n, t_path *b, int **mtrx)
{
	int			i;
	static int	size;

	if (!(size))
		size = calc_size(tab);
	if (!(tab) || !(n) || !(b) || !(mtrx))
		return (0);
	if (no_node(*n, b, mtrx))
		return (close_path(*n, tab, size, 0));
	i = 0;
	check_nodes2(tab, n, b, &i);
	while (++i < b->len[(*n)->path_n - 2] - 1)
	{
		if (b->path[(*n)->path_n - 2][i]
				!= (*n)->path[(*n)->path_n - 2][i])
		{
			(*n)->path[(*n)->path_n - 2][i] = b->path[(*n)->path_n - 2][i];
			(*n)->node[(*n)->path_n - 2][i] = b->node[(*n)->path_n - 2][i];
			tab[b->path[(*n)->path_n - 2][i]].taken = (*n)->path_n - 1;
		}
		if (mtrx[b->path[(*n)->path_n - 2][i]][b->path[(*n)->path_n - 2][i]] > 2
				&& way_is_possible(mtrx, tab, *n, (*n)->path_n - 2) > 1)
			return (1);
	}
	return (0);
}
