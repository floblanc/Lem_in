/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/10 14:55:07 by floblanc         ###   ########.fr       */
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
int		find_path(int **matrix, t_room *tab, t_path *new, int size)
{
	int	i;
	int	j;

	i = path_n - 1;
	while (i < path_n)
	{
		j = 0;
		while (new->path[i][j] != 0)
			j++;
		while (j < size)
		{
			
			if (new->path[i][j] == 1)
				break;
		}
		i++;
	}
}
