/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/05/17 11:06:32 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
//		printf("for node best = %d %s.taken = %d pour le way %d\n", best, tab[best].name, tab[best].taken,  way);
	return (best);
}

int		way_is_possible(int **matrix, t_room *tab, t_path *new, int way)
{
	int	pos;
	int lim;
	int	best;
	int	i;

	pos = 0;
	while (new->path[way][pos + 1] != 0 && new->path[way][pos + 1])//peut etre a raccourcir
		pos++;
	lim = matrix[new->path[way][pos]][new->path[way][pos]];
	best = 0;
	i = 0;
//	printf("new->path[%d][%d](%s) = %d\n", way, pos, tab[new->path[way][pos]].name, new->path[way][pos]);
	while (lim > 0)
	{
		if (matrix[new->path[way][pos]][i] == -1)
		{
			lim--;
			//printf("lim = %d, i = %d\n", lim, i);
//			if (way == 1)
//				printf("i = %d %s.taken = %d et wth = %d used = %d, degre = %d pour le path[%d][%d]\n", i, tab[i].name, tab[i].taken, tab[i].wth, tab[i].used, matrix[i][i], way, pos + 1);
			if (i != 0 && (i == 1 ||
						(tab[i].taken == 0 && tab[i].used != way + 1
						 && (!(best) || tab[best].wth > tab[i].wth) && tab[i].wth > 0)))
				best = i;
		}
		if (best == 1)
			break ;
		i++;
	}
//	printf("best = %d %s pour le path[%d][%d], used = %d, wth = %d\n", best, tab[best].name, way, pos + 1, tab[best].used, tab[best].wth);
	return (best);
}

void	close_path(t_path *new, t_room *tab, int size, int f_case)
{
	int	i;

	i = 0;
//	printf("CLOSEPATH\n");
	if (f_case > 0)
		tab[f_case].used = new->path_n;
	while (new->path[new->path_n - 1][i] != 0)
	{
//		printf("coucou close_path\n");
		if (i == 0)
		{
			tab[new->path[new->path_n - 1][i]].used = new->path_n;
//			printf("TABBBB[new->path[%d][%d]].used = %d\n", new->path_n - 1, i, tab[new->path[new->path_n - 1][i]].used);
		}
		tab[new->path[new->path_n - 1][i]].taken = 0;
		new->path[new->path_n - 1][i++] = 0;
	}
	i = 0;
	while (i < size)
	{
		if (tab[i].used != 0 && tab[i].used != new->path_n)
			tab[i].used = 0;
		i++;
	}
}

void	make_a_turn(int ** matrix, t_room *tab, t_path *new, int node)
{
	int	i;

	i = 1;
//	printf("node = %d degre = %d\n", node, matrix[node][node]);
	while (new->path[new->path_n - 2][i - 1] != node)
		i++;
	new->path[new->path_n - 2][i]
		= way_is_possible(matrix, tab, new, new->path_n - 2);
	tab[new->path[new->path_n - 2][i]].taken = new->path_n - 2 + 1;
}

void	check_first_node(t_path *new, t_room *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (tab[i++].used == new->path_n - 1)
			return ;
	i = 1;
//	printf("FIRST!!!!! ==  %d\n", new->path_n);
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

int		no_node(t_path *new, t_path *best, int **matrix)
{
	int	i;

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

int		check_nodes(t_room *tab, t_path **new, t_path *best, int **matrix)
{
	int	i;
	static int	size;

	if (!(tab) || !(new) || !(best) || !(matrix))
		return (0);
	if (!(size))
		size = calc_size(tab);
	if (no_node(*new, best, matrix))
	{
		close_path(*new, tab, size, 0);
		return (0);
	}
	i = 0;
	while ((*new)->path[(*new)->path_n - 1][i] != 0)
	{
		tab[(*new)->path[(*new)->path_n - 1][i]].taken = 0;
		(*new)->node[(*new)->path_n - 1][i] = 0;
		(*new)->path[(*new)->path_n - 1][i++] = 0;
	}
	i = size - 1;
	check_first_node(*new, tab, size);
	while ((*new)->node[(*new)->path_n - 2][i] == 0
			|| (*new)->node[(*new)->path_n - 2][i] != best->node[(*new)->path_n - 2][i])
	{
//		if (i > -2)
//			printf("\nwhile ((*new)->node[new->path_n -2(%1$d)][i(%2$d)] == 0(%3$d) || (*new)->path->node[(*new)->path_n - 2 (%1$d)][i(%2$d)](%3$d) != best->node[best->(*new)->path_n - 2(%1$d)][i(%2$d)] (%4$d)\n\n", (*new)->path_n - 2, i, (*new)->node[(*new)->path_n-2][i], best->node[(*new)->path_n-2][i]);
		if ((*new)->path[(*new)->path_n - 2][i] != 0)
			tab[(*new)->path[(*new)->path_n - 2][i]].taken = 0;
		if ((*new)->node[(*new)->path_n - 2][i - 1] == best->node[(*new)->path_n - 2][i - 1])
			tab[(*new)->path[(*new)->path_n - 2][i]].used = (*new)->path_n - 1;
		(*new)->node[(*new)->path_n - 2][i] = 0;
		(*new)->path[(*new)->path_n - 2][i--] = 0;
	}
	while (i < best->len[(*new)->path_n - 2] - 1)
	{
		if (best->path[(*new)->path_n - 2][i] != (*new)->path[(*new)->path_n - 2][i])
		{
		//	printf("\n\n-----------------USELESS AS FUCK!------------------------\n\n");
			(*new)->path[(*new)->path_n - 2][i] = best->path[(*new)->path_n - 2][i];
			(*new)->node[(*new)->path_n - 2][i] = best->node[(*new)->path_n - 2][i];
		}
		if (matrix[best->path[(*new)->path_n - 2][i]][best->path[(*new)->path_n - 2][i]] > 2
				&& way_is_possible(matrix, tab, *new, (*new)->path_n - 2) > 1)
			return (best->path[(*new)->path_n - 2][i]);
		i++;
	}
//		close_path(*new, tab, size
//				, way_is_possible(matrix, tab, *new, (*new)->path_n - 1));
	return (0);
}

void	try_path(int **matrix, t_room *tab, t_path *new, t_path *best)
{
	int i;
	int	size;

	(void)matrix;
//	printf("coucou trypath\n");
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
			//printf("i = %d et path_n = %d\n", i, (*new)->path_n);
			if ((i == (*new)->path_n - 1 || i == (*new)->path_n - 2)
					&& ((node = check_nodes(tab, new, best, matrix)) > 0))
			{
			//	printf("node = %d %s.taken = %d degre = %d\n", node, tab[node].name, tab[node].taken, matrix[node][node]);
				make_a_turn(matrix, tab, *new, node);
			}
			else if (way_is_possible(matrix, tab, *new, (*new)->path_n - 1) > 0)
			{
//				printf("lol\n");
				try_path(matrix, tab, *new, best);
			}
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
