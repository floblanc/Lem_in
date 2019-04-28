/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/28 14:43:46 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	swap_path(t_path **new, int size, int i)
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
		(*new)->path[i][j] = (*new)->path[i + 1][j];
	(*new)->len[i] = (*new)->len[i + 1];
	j = -1;
	while (++j < size)
		(*new)->path[i + 1][j] = tmp[j];
	(*new)->len[i + 1] = save_len;
}

void	sort_paths(t_path **new, int size)
{
	int	i;
	
	i = 0;
	while (i < (*new)->path_n - 1)
	{
		if (((*new)->len[i] <= 0 || (*new)->len[i] > (*new)->len[i + 1])
				&& (*new)->len[i + 1] > 0)
		{
			swap_path(new, size, i);
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

int		analyse_block(t_room *tab, t_path *new, int *way, int pos)
{
	int	block;
	int	i;

	i = 0;
	//printf(" %d\n",tab[-1 * new->path[*way][pos]].taken);
	new->path[*way][pos] *= -1;
	block = tab[new->path[*way][pos]].taken - 1;
	tab[new->path[*way][pos]].taken = *way + 1;
	while (new->path[block][i] != 0 && new->path[block][i] != -1)
		i++;
	//	printf("new->path[%d][%d] = %d != new->path[%d][%d] = %d\n", block, 28, new->path[block][28], *way, pos, new->path[*way][pos]);
	if (new->path[block][i] == -1)
		new->path[block][i--] = 0;
	while (new->path[block][i] != new->path[*way][pos])
	{
//			if (i >= 0 && block == 11)
//				printf("new->path[%d][%d] = %d != new->path[%d][%d] = %d\n", block, i, new->path[block][i], *way, pos, new->path[*way][pos]);
		if (new->path[block][i] != 0)
			tab[new->path[block][i]].taken = 0;
		new->path[block][i] = 0;
		//if (i >= 0 && block == 11)
		//		printf("remi a 0 new->path[%d][%d] = %d\n", block, i, new->path[block][i]);
		i--;
	}
//	if (i >= 0 && block == 11)
//			printf("remi a 0 new->path[%d][%d] = %d\n", block, i, new->path[block][i]);
	new->path[block][i] = 0;
	new->len[block] = 0;
	*way = block - 1;
	return (0);
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
			if ((tab[i].taken <= 0 && tab[i].taken > (way + 1) * -1
						&& (best == 0 || tab[i].wth < tab[best].wth)))
				best = i;
			else if (pos > 0 && i && tab[i].taken > 0 && (tab[i].taken != way + 1
						&& (block == 0 || tab[block].wth > tab[i].wth)
						&& other_turn(matrix, tab, new->path[tab[i].taken - 1], i)))
				block = i;
			/*else if (pos > 0 && i && tab[i].taken > 0 && (tab[i].taken > way + 1
						&& (block == 0 || tab[block].wth > tab[i].wth)
						&& other_turn(matrix, tab, new->path[tab[i].taken - 1], i)))
								block = i;
		*/}
		if (best == 1)
			break ;
		i++;
	}
		printf("best = %d %s.taken = %d pour le way %d\n", best, tab[best].name, tab[best].taken,  way + 1);
		printf("Block = %d %s.taken = %d pour le way %d\n", block, tab[block].name, tab[block].taken,  way + 1);
	if (best != 0 && best != 1)
		tab[best].taken = way + 1;
	else if (block > 0 && (!(best) /*|| tab[best].wth > tab[block].wth*/))
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
					if (j > 1)
					{
						tab[(*new)->path[i][j - 1]].taken *= -1;
						(*new)->path[i][j - 1] = 0;
						i = (i == 0 ? -1 : i - 2);
						j = 0;
					}
					else
					{
						(*new)->len[i] = -1;
						(*new)->path[i][j] = -1;
					}
				}
				//	if (i == 11 && j > 0 && (*new)->path[i][j] >= 0)
				//		printf("tab[path[%d][%d] = %d].taken = %d\n", i, j, (*new)->path[i][j], tab[(*new)->path[i][j]].taken);
			}
			i++;
		}
		j++;
	}
	sort_paths(new, size);
	return (0);
}
