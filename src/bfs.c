/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:01:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/02 13:54:58 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		bfs(int **matrix, int i, int j, t_room *tab)
{
	static int d;

	if (j == 0)
		d = 0;
	if (d == matrix[i][i])
	{
		d = 0;
		return ;
	}
	while (matrix[i][j] != -1)
		j++;
	d++;
	if (d < matrix[i][i])
		bfs(matrix, i, j + 1, tab);
	if (tab[j].wth == 0 && j != 1 && i != 0)
		tab[j].wth = tab[i].wth + 1;
	bfs(matrix, j, 0, tab);
	return ;
}
