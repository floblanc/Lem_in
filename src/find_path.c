/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/22 16:27:43 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int		analyse_block(t_room *tab, t_path *new, int *way, int pos)
{
	int	block;
	int	i;

	i = 0;
//	printf(" %d\n",new->path[*way][pos]);
	new->path[*way][pos] *= -1;
	block = tab[new->path[*way][pos]].taken - 1;
	tab[new->path[*way][pos]].taken = *way + 1;
	while (new->path[block][i] != 0 && new->path[block][i] != -1)
		i++;
	if (new->path[block][i] == -1)
		new->path[block][i--] = 0;
//	printf("new->path[%d][%d] = %d != new->path[%d][%d] = %d\n", block, i, new->path[block][i], *way, pos, new->path[*way][pos]);
	while (new->path[block][i] != new->path[*way][pos])
	{
	//	if (i >= 0)
	//		printf("new->path[%d][%d] = %d != new->path[%d][%d] = %d\n", block, i, new->path[block][i], *way, pos, new->path[*way][pos]);
		tab[new->path[block][i]].taken = 0;
		new->path[block][i] = 0;
		i--;
	}
		new->path[block][i] = 0;
		new->len[block] = 0;
		*way = block - 1;
	return (i - 1);
}

int		way_is_possible(int **matrix, t_room *tab, t_path *new, int way)
{
	int	pos;
	int lim;
	int	best;
	int	block;
	int	i;

	pos = 0;
	while (new->path[way][pos + 1] != 0)
		pos++;
	//printf(" %d\n",new->path[way][pos]);
	lim = matrix[new->path[way][pos]][new->path[way][pos]];
	best = 0;
	block = 0;
	i = 0;
	while (lim > 0)
	{
		if (matrix[new->path[way][pos]][i] == -1)
		{
			lim--;
			//	if (way != 0)
			//		printf("check : (((tab[%d].taken (%d) <= 0 && ((tab[%d].taken (%d) > (way (%d) + 1) * -1 (%d) && !(tab[%d].taken(%d) == -1 && pos(%d) == 0))) || tab[%d].taken (%d) == 0)) || i (%d)== 1) && (best(%d) == 0 || tab[%d].wth(%d) < tab[%d].wth (%d)))\n\n", i, tab[i].taken, i, tab[i].taken, way, (way + 1) * -1, i, tab[i].taken, pos, i, tab[i].taken, i, best, i, tab[i].wth, best, tab[best].wth);
			if ((!(tab[i].taken) && (best == 0 || tab[i].wth < tab[best].wth)))
				best = i;
			else if (pos > 0 && tab[i].taken > 0 && (tab[i].taken >/*si on l'inverse on a d'autres chemins ca peut etre interessant de lancer les 2 et garder le meilleur*/ way + 1
							&& (best == 0 || tab[block].wth > tab[i].wth)))
				block = i;
		}
			if (best == 1)
				break ;
		i++;
	}
//	printf("best = %d %s.taken = %d pour le way %d\n", best, tab[best].name, tab[best].taken,  way);
	if (best != 0 && best != 1)
		tab[best].taken = way + 1;
	else if (!(best) && block > 0)
		best = -block;
	return (best);
}

int		find_path(int **matrix, t_room *tab, t_path **new, int size)
{
	int	i;
	int	j;

	(void)size;
	if (!(*new))
		return (0);
	j = 0;
	while (!(all_len_complete(*new)))
	{
		i = 0;
		while (i < (*new)->path_n)
		{
			if ((*new)->len[i] == 0 && (*new)->path[i][j] == 0)
			{
				(*new)->path[i][j] = way_is_possible(matrix, tab, *new, i);
				if ((*new)->path[i][j] == 1)
					(*new)->len[i] = j + 1;
				else if ((*new)->path[i][j] < 0)
					j = analyse_block(tab, *new, &i, j);
				else if ((*new)->path[i][j] == 0)
				{
					(*new)->len[i] = -1;
					(*new)->path[i][j] = -1;
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}
