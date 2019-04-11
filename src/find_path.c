/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/11 17:44:38 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
 *HYPOTHESES : (usefull or useless that is the question)
 *
 * tab[].taken == i => i - 1 == index path
 * ex: taken = 1 => pris par le chemin path[0]
 * 	   taken = 2 => pris par le chemin path[1]
 * 	   etc...
 * 	   et poids negatif du numero utilisé si c'est juste une case sur laquelle 
 * 	   il doit pas retourner : ex : tab[].taken = -1 => index path[0] doit pas y aller
 * 	   								tab[].taken = -2 => index path[1} doit pas y aller
 * 	   etc...
 *
 *	PS: sinon on commence a coder l'algo et on voit ensuite
 *	(histoire de pas perdre de temps sur des outils inutiles)
 */
void	roll_back_way(t_room *tab, t_path *new, int *i, int size)
{
	while (--size > 1)
	{
		if (tab[size].taken == (i + 1) * -1)
			tab[size].taken = 0;
	}
	*i = *i - 1;
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
			if (tab[i].taken <= 0 && tab[i].taken <= (way + 1) * -1
					&& (best == 0 || tab[i].wth < tab[best].wth))
				best = i;
		}
		i++;
	}
	return (best);
}

int		find_path(int **matrix, t_room *tab, t_path *new, int size)
{
	int	i;
	int	j;

	i = new->path_n - 1;
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
			roll_back_way(tab, new, &i, size);
		else if (j == -1)
			return (0);
		i++;
	}
	other_way(matrix, tab, new, size);
}
