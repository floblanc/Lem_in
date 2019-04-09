/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:24:49 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/09 11:30:21 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	put_wth(int **matrix, int i, int j, t_room *tab)
{
	static int	size;

	if (!(size))
		size = calc_size(tab);
	if (i >= size || j >= size || i == 0)
		return ;
	while (j < size && (j == 1 || matrix[i][j] != -1 || (tab[j].wth != 0
					&& tab[j].wth <= tab[i].wth + 1)))
		j++;
	if (j == size)
		return ;
	tab[j].wth = tab[i].wth + 1;
	put_wth(matrix, i, j + 1, tab);
	put_wth(matrix, j, 0, tab);
}
