/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/10 22:59:28 by floblanc         ###   ########.fr       */
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
int		way_is_possible(int **matrix, t_room *tab, int *path, int j)
{
	int	pos;
	int lim;
	int	best;
	int	i;

	pos = ((j == 0) ? 0 : path[j - 1]);
	lim = matrix[pos][pos];
	best = 0;
	i = 0;
	while (lim > 0)
	{
		if (matrix[pos][i] == -1)
		{
			lim--;
			if (tab[i].taken == 0 && (best == 0 || tab[i].wth < tab[best].wth))
				best = i;
		}
		i++;
	}
	if (best != 0)
		return (best);
	return (on_precise_la_nature_du_blocage_ici_ou_pas_ou_meme_on_lance_un_autre_truc);
}

int		find_path(int **matrix, t_room *tab, t_path *new, int size)
{
	int	i;
	int	j;

	i = new->path_n - 1;
	while (i < new->path_n)
	{
		j = 0;
		while (new->path[i][j] != 0)
			j++;
		while (j < size)
		{
			if ((new->path[i][j] = way_is_possible(matrix, tab, new->path[i], j)) <= 0)
			{
				onfaitdestrucs;
			}
			else
				tab[new->path[i][j]].taken = i + 1;
			if (new->path[i][j] == 1)
				break;
			j++;
		}
		i++;
	}
}
