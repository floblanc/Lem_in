/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:01:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/03 02:07:05 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


/*
IDEE CONDITION D'ARRET BFS :
tant que tous les chemins lies a start (tab[0]) n'ont pas un poids (wth)
*/
void		bfs(int **matrix, int i, int j, t_room *tab)
{
	int	d;

	d = 0;
	while (d < matrix[i][i])
	{
		while (j == 1 || (matrix[i][j] != -1 && (tab[j].wth != 0 || tab[i].wth + 1 >= tab[j].wth)))
			j++;
		d++;
		tab[j].wth = 
	}
}
