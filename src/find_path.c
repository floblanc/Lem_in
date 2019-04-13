/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/13 17:52:37 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	roll_back_way(t_room *tab, t_path *new, int *i, int size)
{
	int j;

//	printf("roll_back_way\n");
	j = 0;
	while (--size > 1)
	{
		if (tab[size].taken == ((*i) + 1) * -1)
			tab[size].taken = 0;
	}
	new->len[*i] = 0;
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
	//printf("avant path[%d][%d] = %s.taken = %d\n", i, *j, tab[new->path[i][*j]].name, tab[new->path[i][*j]].taken);
	*j = *j - 1;
	if (*j < 0)
		return ;
	tab[new->path[i][(*j)]].taken = (i + 1) * -1;
//	printf("path[%d][%d] = %s.taken = %d\n", i, *j, tab[new->path[i][*j]].name, tab[new->path[i][*j]].taken);
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
	printf("depuis la salle %s best : %d (%s).taken = %d pour le way %d\n", tab[new->path[way][pos]].name, best, tab[best].name, tab[best].taken, way);
	if (best != 0 && best != 1)
		tab[best].taken = way + 1;
	return (best);
}

void	other_way(int **matrix, t_room *tab, t_path *new, int size)
{
	int		i;
	int		j;
	t_path	*another_new;

	printf("on cherche\n");
	j = -1;
	another_new = 0;
	init_t_path(&another_new, size, new->path_n);
	while (++j < new->path_n)
	{
		i = -1;
		while (new->path[j][++i] != 1)
			another_new->path[j][i] = new->path[j][i];
	}
	while (--j >= 0)
	{
		i = 0;
		while (another_new->path[j][i + 1] != 0)
			i++;
		tab[another_new->path[j][i]].taken = (j + 1) * -1;
		printf("tab[%d](%s).taken = %d\n", another_new->path[j][i], tab[another_new->path[j][i]].name, tab[another_new->path[j][i]].taken);
		another_new->path[j][i] = 0;
	}
/*	printf("new->path[0][%d] = %d(%s)\n", i - 1, another_new->path[0][i -1], tab[another_new->path[0][i -1]].name);
	tab[another_new->path[0][--i]].taken = -1;
	another_new->path[0][i--] = 0;
	printf("new->path[0][%d] = %d(%s)\n", i, another_new->path[0][i], tab[another_new->path[0][i]].name);*/
	printf("tab[%d] = %s.taken = %d\n", 5, tab[5].name, tab[5].taken);
	/*while (matrix[new->path[0][i]][new->path[0][i]] < 3
					&& !(way_is_possible(matrix, tab, another_new, 0)))
	{
		tab[another_new->path[0][i]].taken = 0;
		another_new->path[0][i--] = 0;
	}*/
	printf("i = %d\n",i);
	if (i >= 0)
	{
		printf("ca tente un truc\n");
		//tab[way_is_possible(matrix, tab, another_new, 0)].taken = -1;
		//clean_some_taken(tab, size);
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

	if (!(new))
		return (0);
	i = -1;
	while (++i < new->path_n && i >= 0)
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
//	printf("len[%d] = %d\n", i, new->len[i]);
//	printf("path[%d][%d] = %s.taken = %d\n", i, j, tab[new->path[i][j]].name, tab[new->path[i][j]].taken);
		if (j == -1 && i > 0)
			roll_back_way(tab, new, &i, size);
		else if (j == -1)
			return (0);
	}
//	printf("other way loop\n");
	if (new->path_n > 1)
		other_way(matrix, tab, new, size);
	//printf("not a loop\n");
	return (1);
}
