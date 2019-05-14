/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:14:33 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/14 12:37:13 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_tab(t_room **tab, int i, t_room *current)
{
	(*tab)[i].name = ft_strdup(current->name);
	(*tab)[i].x = current->x;
	(*tab)[i].y = current->y;
	(*tab)[i].startend = current->startend;
	(*tab)[i].wth = 0;
	(*tab)[i].taken = 0;
	(*tab)[i].used = 0;
	(*tab)[i].next = current->next;
}

void	init_t_path2(t_path **struc, int path_n)
{
	if (!((*struc) = (t_path*)malloc(sizeof(t_path) * 1)))
		exit(0);
	if (!((*struc)->path = (int**)malloc(sizeof(int*) * path_n)))
		exit(0);
	if (!((*struc)->node = (int**)malloc(sizeof(int*) * path_n)))
		exit(0);
}

void	init_t_path(t_path **struc, int size, int path_n)
{
	int	i;
	int	j;

	i = -1;
	init_t_path2(struc, path_n);
	if (!((*struc)->len = (int*)malloc(sizeof(int) * path_n)))
		exit(0);
	while (++i < path_n)
	{
		(*struc)->len[i] = 0;
		if (!((*struc)->path[i] = (int*)malloc(sizeof(int) * size)))
			exit(0);
		if (!((*struc)->node[i] = (int*)malloc(sizeof(int) * size)))
			exit(0);
		j = 0;
		while (j < size)
		{
			(*struc)->path[i][j] = 0;
			(*struc)->node[i][j++] = 0;
		}
	}
	(*struc)->path_n = path_n;
	(*struc)->step = 0;
}
