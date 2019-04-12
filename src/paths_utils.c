/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:58:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/12 23:54:45 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ant_walk(t_path *best, t_room *tab, int j)
{
	int i;

	i = best->len[j] - 1;
	while (i > 0)
	{
		tab[best->path[j][i]].taken = tab[best->path[j][i - 1]].taken;
		i--;
	}
}

void	use_path(t_path *best, t_room *tab, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (!(best))// c'est pas sense arriver
		return ;
	while (j < size)
		tab[j++].taken = 0;
	while ((best->step)-- > 0)
	{
		j = -1;
		write(1, "\n", 1);
		while (++j < best->path_n)
		{
			ant_walk(best, tab, j);
			if (best->path[best->path[j][best->len[j]]] > 0)
				tab[best->path[j][0]].taken = i++;
			else
				tab[best->path[j][0]].taken = 0;
			(best->path[j][best->len[j]])--;
			write_path(best, tab, j);
		}
	}
}

void	init_t_path(t_path **struc, int size, int path_n)
{
	int	i;
	int	j;

	i = 0;
	if (!((*struc) = (t_path*)malloc(sizeof(t_path) * 1)))
		exit(0);
	if (!((*struc)->path = (int**)malloc(sizeof(int*) * path_n)))
		exit(0);
	if (!((*struc)->len = (int*)malloc(sizeof(int) * path_n)))
		exit(0);
	while (i < path_n)
	{
		(*struc)->len[i] = 0;
		if (!((*struc)->path[i] = (int*)malloc(sizeof(int) * size)))
			exit(0);
		j = 0;
		while (j < size)
		{
			(*struc)->path[i][j] = 0;
			j++;
		}
		i++;
	}
	(*struc)->path_n = path_n;
	(*struc)->next = 0;
}

int		calc_step(t_path *struc, int ant_n, int path_n)
{
	int	i;

	if (!(struc->len[path_n - 1]))
		return (0);
	struc->path[0][struc->len[0]] = ant_n;
	if (path_n == 1)
	{
		struc->step = struc->len[0] + struc->path[0][struc->len[0]] - 1;
		return (struc->step);
	}
	i = 1;
	while (i > 0)
	{
		i = 0;
		while ((i < path_n - 1) && (struc->len[i]
					+ struc->path[i][struc->len[i]] - 1 >= struc->len[i + 1]
					+ struc->path[i + 1][struc->len[i + 1]]))
			i++;
		if (i > 0)
			struc->path[0][struc->len[0]]--;
		if (i > 0)
			struc->path[i][struc->len[i]]++;
	}
	struc->step = struc->len[1] + struc->path[1][struc->len[1]] - 1;
	return (struc->step);
}
