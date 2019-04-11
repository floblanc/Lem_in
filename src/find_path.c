/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/11 20:22:11 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	roll_back_way(t_room *tab, t_path *new, int *i, int size)
{
	while (--size > 1)
	{
		if (tab[size].taken == (i + 1) * -1)
			tab[size].taken = 0;
	}
	new->len[*i] = 0;
	*i = *i - 2;
}

void	roll_back(t_path *new, int i, int *j, t_room *tab)
{
	*j = *j - 1;
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
	lim = matrix[pos][pos];
	best = 0;
	i = 0;
	while (lim > 0)
	{
		if (matrix[pos][i] == -1)
		{
			lim--;
			if (((tab[i].taken <= 0 && tab[i].taken <= (way + 1) * -1)
						|| i == 1) && (best == 0 || tab[i].wth < tab[best].wth))
				best = i;
		}
		i++;
	}
	return (best);
}

void	other_way(int **matrix, t_room *tab, t_path *new, int size)
{
	int	i;
	t_path *another_new;

	i = -1;
	init_t_path(another_new, size, new->path_n);
	while (new->path[0][++i] != 1)
		another_new->[0][i] = new->[0][i];
	i--;
	while (i >= 0 && (matrix[1][new->path[0][i]] == -1
				|| (matrix[new->path[0][i]][new->path[0][i]] < 3
					&& !(way_is_possible(matrix, tab, another_new, 0)))))
	{
		tab[another_new->path[i]].taken = 0;
		another_new->path[0][i] == 0;
		i--;
	}
	if (i < 0)
	{
		tab[way_is_possible(matrix, tab, another_new, 0)].taken = -1;
		clean_some_taken(tab, size);
		if (find_path(matrix, tab, another_new, size))
			try_swap_t_path(&another_new, &new);
	}
	free_paths(&another_new);// si on free dans le vide ca viens de la je pense
	return ;
}

int		find_path(int **matrix, t_room *tab, t_path *new, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < new->path_n)
	{
		j = 0;
		while (j >= 0 && new->len[i] == 0)
		{
			while (new->path[i][j] != 0)
				j++;
			if (!(new->path[i][j] = way_is_possible(matrix, tab, new, i)))
				roll_back(new, i, &j, tab);
			else if (new->path[i][j] == 1)
				new->len[i] = j + 1;
		}
		if (j == -1 && i > 0)
			roll_back_way(tab, new, &i, size);//pertinence de l'effacage des .taken : inconnue
		else if (j == -1)
			return (0);
		i++;
	}
	other_way(matrix, tab, new, size);
	return (1);
}
