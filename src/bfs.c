/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:01:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/03 13:39:39 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


/*
   IDEE CONDITION D'ARRET BFS :
   tant que tous les chemins lies a start (tab[0]) n'ont pas un poids (wth)
   */

int		calc_size(t_room *tab)
{
	int size;

	size = 0;
	while (tab[size].next)
		size++;
	size++;
	return (size);
}

void	bfs(int **matrix, int i, int j, t_room *tab)
{
	static	int	size;

	if (!(size))
		size = calc_size(tab);
	if (i >= size || j >= size || i == 0)
		return ;
	while (j < size && (j == 1 || matrix[i][j] != -1 || (tab[j].wth != 0
					&& tab[j].wth <= tab[i].wth + 1)))
		j++;
	tab[j].wth = tab[i].wth + 1;
	if (j < size)
		bfs(matrix, i, j + 1, tab);
	bfs(matrix, j, 0, tab);
}
