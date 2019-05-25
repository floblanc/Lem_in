/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 00:29:39 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/25 17:14:46 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	lets_search_match(int **matrix, int i, int *j)
{
	if ((*j) == i)
		(*j)++;
	if (matrix[i][(*j)] == -1)
		return ;
	(*j) += matrix[i][(*j)] - 1;
}

void	shortcut_between_link(int **matrix, int i, int *j, int save)
{
	if (i == (*j))
		(*j)--;
	while (matrix[i][(*j)] == 0 && (*j) >= 0)
		(*j)--;
	if ((*j) < 0 || matrix[i][(*j)] == -1 || matrix[i][(*j) - 1] == -1)
	{
		if (matrix[i][(*j) + 1] == 0)
			matrix[i][(*j) + 1] = save - ((*j) + 1);
	}
	else
	{
		(*j) -= 2;
		shortcut_between_link(matrix, i, j, save);
	}
}

void	make_j_run(int **matrix, int i, int *j)
{
	while (matrix[i][(*j)] != -1)
		(*j)--;
}

void	set_matrix_shortcut(int **matrix, int size)
{
	int i;
	int	j;
	int	save;
	int	lim;

	i = 0;
	while (++i < size)
	{
		j = size - 1;
		save = 0;
		lim = matrix[i][i];
		while (lim > 0)
		{
			make_j_run(matrix, i, &j);
			if ((j > 0 && matrix[i][j - 1] == 0)
				|| (j - 1 == i && matrix[i][j - 2] == 0))
			{
				save = j--;
				shortcut_between_link(matrix, i, &j, save);
			}
			else
				j--;
			lim--;
		}
	}
}
