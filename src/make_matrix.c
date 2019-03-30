/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:16:42 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/30 18:23:10 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	order_tabroom(t_room **tab)
{
	t_room	tmp;
	int		i;

	i = 0;
	while ((*tab)[i].startend != 1)
		i++;
	tmp = (*tab)[0];
	(*tab)[0] = (*tab)[i];
	(*tab)[i] = tmp;
	(*tab)[i].next = (*tab)[0].next;
	(*tab)[0].next = tmp.next;
	i = 0;
	while ((*tab)[i].startend != 2)
		i++;
	tmp = (*tab)[1];
	(*tab)[1] = (*tab)[i];
	(*tab)[i] = tmp;
	tmp.next = (*tab)[i].next;
	(*tab)[i].next = (*tab)[1].next;
	(*tab)[1].next = tmp.next;
}

void	rooms_in_tab(t_room **tab, t_room **begin)
{
	t_room	*current;
	int		i;
	int		size;

	size = ft_lstlen(begin);
	if (!(*tab = (t_room*)malloc(sizeof(t_room) * (size))))
		exit(0);
	if (!(begin && *begin))
		return ;
	current = *begin;
	i = 0;
	while (current)
	{
		(*tab)[i].name = ft_strdup(current->name);
		(*tab)[i].x = current->x;
		(*tab)[i].y = current->y;
		(*tab)[i].startend = current->startend;
		(*tab)[i].taken = 0;
		(*tab)[i].wth = 0;
		(*tab)[i].next = current->next;
		current = current->next;
		i++;
	}
	free_lst_room(begin);
	order_tabroom(tab);
}

void	assign_value(int **matrix, int i, int j)
{
	(matrix[i][i])++;
	(matrix[j][j])++;
	matrix[j][i] = -1;
	matrix[i][j] = -1;
}

void	fill_matrix(t_room *tab, t_link **begin, int **matrix, int size)
{
	int		i;
	int		j;
	t_link	*c;

	i = 0;
	while (i < size)
	{
		c = *begin;
		while (c)
		{
			j = i;
			while (j < size)
			{
				if ((ft_strcmp(tab[i].name, c->name1) == 0 
							&& ft_strcmp(tab[j].name, c->name2) == 0) 
						|| (ft_strcmp(tab[i].name, c->name2) == 0 
							&& ft_strcmp(tab[j].name, c->name1) == 0))
					assign_value(matrix, i, j);
				j++;
			}
			c = c->next;
		}
		i++;
	}
}

int		**set_matrix(t_room *tab, t_link **begin, int size)
{
	int		**matrix;
	int		i;
	int		j;

	i = 0;
	if (!(matrix = (int**)malloc(sizeof(int*) * size)))
		exit(0);
	while (i < size)
	{
		if (!(matrix[i] = (int*)malloc(sizeof(int) * size)))
			exit(0);
		j = 0;
		while (j < size)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	fill_matrix(tab, begin, matrix, size);
	free_lst_link(begin);
	return (matrix);
}
