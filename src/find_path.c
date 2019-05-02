/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/05/02 17:43:19 by floblanc         ###   ########.fr       */
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

int		node_is_possible(int **matrix, t_room *tab, int	room, int way)
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
//	printf("for node best = %d %s.taken = %d pour le way %d\n", best, tab[best].name, tab[best].taken,  way);
	return (best);
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

	//	printf("i = %d %s.taken = %d et wth = %d pour le path[%d][%d]\n", i, tab[i].name, tab[i].taken, tab[i].wth,  way, pos + 1);
			if (i != 0 && (i == 1 ||
						(tab[i].taken == 0 && tab[i].used != way + 1
					&& (!(best) || tab[best].wth > tab[i].wth) && tab[i].wth != 0)))
				best = i;
		}
		if (best == 1)
			break ;
		i++;
	}
//	printf("best = %d %s.taken = %d pour le path[%d][%d]\n", best, tab[best].name, tab[best].taken,  way, pos + 1);
	return (best);
}

void	make_a_turn(int ** matrix, t_room *tab, t_path *new, int node)
{
	int	i;

//	printf("node = %d %s.taken = %d\n", node, tab[node].name, tab[node].taken);
	i = new->len[new->path_n - 2] - 1;
//	printf("new->len[%d] = %d\n", new->path_n - 2, new->len[new->path_n - 2]);
	while (new->node[new->path_n - 2][i] != node)
	{
	//	if (i > -5)
	//	printf("i = %d\n",i);
		if (new->path[new->path_n - 2][i - 1] == node)
			tab[new->path[new->path_n - 2][i]].used = new->path_n - 2 + 1;
		if (new->path[new->path_n - 2][i] != 0)
			tab[new->path[new->path_n - 2][i]].taken = 0;
		new->path[new->path_n - 2][i--] = 0;
	}
	new->path[new->path_n - 2][i + 1]
		= way_is_possible(matrix, tab, new, new->path_n - 2);
	tab[new->path[new->path_n - 2][i + 1]].taken
		= new->path[new->path_n - 2][i + 1] + 1;
}

int		check_nodes(t_room *tab, t_path **new, t_path *best, int **matrix)
{
	static int	node;
	int	i;
	int	count;

	if (!(node) || (!(tab) && !(new) && !(best) && !(matrix)))
		node = 0;
	if (tab == 0 || new == 0 || best == 0 || matrix == 0)
		return (0);
	i = 0;
	count = node;
	while ((*new)->path[(*new)->path_n - 1][i] > 0)
	{
		if ((*new)->path[(*new)->path_n - 1][i] != 0)
			tab[(*new)->path[(*new)->path_n - 1][i]].taken = 0;
		(*new)->path[(*new)->path_n - 1][i++] = 0;
	}
	i = 0;
	while (i < best->len[best->path_n - 1])
	{
		//printf("COPY : [%d][%d] = %d\n",best->path_n - 1, i, best->path[best->path_n - 1][i]);
		if ((*new)->path[(*new)->path_n - 2][i] != best->path[best->path_n - 1][i])
			tab[(*new)->path[(*new)->path_n - 2][i]].taken = 0;
		(*new)->node[(*new)->path_n - 2][i] = best->node[best->path_n - 1][i];
		(*new)->path[(*new)->path_n - 2][i] = best->path[best->path_n - 1][i];
		tab[(*new)->path[(*new)->path_n - 2][i]].taken = (*new)->path_n - 1;
		if (best->node[best->path_n - 1][i] > 0)
		{
			if ((count -= matrix[best->node[best->path_n - 1][i]]
						[best->node[best->path_n - 1][i]] - 2) < 0
					&& node_is_possible(matrix, tab,
						best->node[best->path_n - 1][i], best->path_n - 1))
			{
				node++;
			//	printf("best->node[%d][%d] = %d\n", best->path_n -1, i, best->node[best->path_n - 1][i]);
				return (best->node[best->path_n - 1][i]);
			}
		}
		i++;
	}
	node++;
	return (0);
}

void	try_path(int **matrix, t_room *tab, t_path *new, t_path *best)
{
	int i;
	int	size;

	size = calc_size(tab);
	i = check_nodes(0, 0, 0, 0) - 1;
	copy_best(best, new, size, tab);
	while (++i < size)
		if (tab[i].used == new->path_n - 2)
			tab[i].used = 0;
	tab[way_is_possible(matrix, tab, new, new->path_n - 1)].used = new->path_n;
	new->path[new->path_n - 2][new->len[new->path_n - 2] - 1] = 0;
}

int		find_path(int **matrix, t_room *tab, t_path **new, t_path *best)
{
	int	i;
	int	j;
	int	node;
	i = (*new)->path_n - 1;
	while (i < (*new)->path_n)
	{
		j = 0;
		while ((*new)->path[i][j] != 0)
			j++;
	//	printf("j = %d\n", j);
		while (((*new)->path[i][j] = way_is_possible(matrix, tab, *new, i)) > 1)
		{
			if (matrix[(*new)->path[i][j]][(*new)->path[i][j]] > 2
					&& (*new)->path[i][j] != 1)
				(*new)->node[i][j] = (*new)->path[i][j];
			tab[(*new)->path[i][j++]].taken = i + 1;
		}
		if ((*new)->path[i][j] == 0)
		{
			if ((i == (*new)->path_n - 1 || i == (*new)->path_n - 2)
					&& ((node = check_nodes(tab, new, best, matrix)) > 0))
			{
		//	printf("node = %d %s.taken = %d degre = %d\n", node, tab[node].name, tab[node].taken, matrix[node][node]);
				make_a_turn(matrix, tab, *new, node);
			}
			else if (way_is_possible(matrix, tab, *new, (*new)->path_n - 1) > 0)
				try_path(matrix, tab, *new, best);
			else
				return (0);
			i = (*new)->path_n - 3;
		}
		else
			(*new)->len[i] = j + 1;
		i++;
	}
	node = check_nodes(0, 0, 0, 0);
	return (1);
}
