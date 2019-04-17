/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/17 15:48:01 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	roll_back_way(t_room *tab, t_path *new, int *i, int size)
{
	int j;

	j = 0;
	while (--size > 1)
		if (tab[size].taken == ((*i) + 1) * -1)
			tab[size].taken = 0;
	new->len[*i] = -1;
	*i = *i - 1;
	while (new->path[*i][j] != 1)
		j++;
	new->path[*i][j] = 0;
	j = j - 1;
	tab[new->path[*i][j]].taken = (*i + 1) * -1;
	new->path[*i][j] = 0;
	new->len[*i] = 0;
	*i = *i - 1;
}

void	roll_back(t_path *new, int i, int *j, t_room *tab)
{
	*j = *j - 1;
	if (*j < 0)
		return ;
	tab[new->path[i][(*j)]].taken = (i + 1) * -1;
	new->path[i][(*j)] = 0;
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
			if (((tab[i].taken <= 0 && tab[i].taken > (way + 1) * -1)
						|| i == 1) && (best == 0 || tab[i].wth < tab[best].wth))
				best = i;
		}
		i++;
	}
	if (best != 0 && best != 1)
		tab[best].taken = way + 1;
	return (best);
}

void	other_way(int **matrix, t_room *tab, t_path **new, int size)
{
	int			i;
	int			j;
	static int	only_one;
	t_path	*another_new;

	if (!(only_one) || only_one != (*new)->path_n)
		only_one = (*new)->path_n;
	else
		return ;
	i = 0;
	another_new = 0;
	init_t_path(&another_new, size, (*new)->path_n);
	while (i < (*new)->path_n)
	{
		j = 0;
		while ((*new)->path[i][j] != 1)
		{
			another_new->path[i][j] = (*new)->path[i][j];
			j++;
		}
		j--;
		tab[another_new->path[i][j]].taken = (i + 1) * -1;
		another_new->path[i][j] = 0;
		i++;
	}
	if (find_path(matrix, tab, &another_new, size))
		try_swap_t_path(&another_new, new);
	free_paths(&another_new);// si on free dans le vide ca viens de la je pense
	return ;
}

int		find_path(int **matrix, t_room *tab, t_path **new, int size)
{
	int	i;
	int	j;

	if (!(*new))
		return (0);
	i = -1;
	while (++i < (*new)->path_n && i >= 0)
	{
		j = 0;
		while (j >= 0 && (*new)->len[i] <= 0)
		{
			while ((*new)->path[i][j] != 0)
				j++;
			if (!((*new)->path[i][j] = way_is_possible(matrix, tab, *new, i)))
				roll_back(*new, i, &j, tab);
			else if ((*new)->path[i][j] == 1)
				(*new)->len[i] = j + 1;
		}
		if (j < 0 && i > 0 && (*new)->len[i] == 0)
			roll_back_way(tab, *new, &i, size);
		else if (j < 0)
			return (0);
	}
	if ((*new)->path_n > 1)
		other_way(matrix, tab, new, size);//test d'en faire qu'un
	return (1);
}
