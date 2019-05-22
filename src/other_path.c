/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:37:38 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/21 10:55:41 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	swap_path(t_path **new, int size, int i, t_room *tab)
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
	{
		(*new)->path[i][j] = (*new)->path[i + 1][j];
		if ((*new)->path[i][j] > 0)
			tab[(*new)->path[i][j]].taken = i + 1;
		(*new)->len[i] = (*new)->len[i + 1];
	}
	j = -1;
	while (++j < size)
	{
		(*new)->path[i + 1][j] = tmp[j];
		if (tmp[j] > 0)
			tab[tmp[j]].taken = i + 2;
	}
	(*new)->len[i + 1] = save_len;
}

void	sort_paths(t_path **new, int size, t_room *tab, int **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*new)->path_n - 1)
	{
		if (((*new)->len[i] <= 0 || (*new)->len[i] > (*new)->len[i + 1]))
		{
			swap_path(new, size, i, tab);
			i = -1;
		}
		i++;
	}
	i = -1;
	while (++i < (*new)->path_n)
	{
		j = 0;
		while ((*new)->path[i][j] != 1 && (*new)->path[i][j] != 0)
		{
			(*new)->node[i][j] = (matrix[(*new)->path[i][j]][(*new)->path[i]
					[j]] > 2) ? (*new)->path[i][j] : 0;
			j++;
		}
	}
}
