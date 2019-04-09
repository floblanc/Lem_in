/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:16:42 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/03 17:09:44 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	order_tabroom(t_room **tab)
{
	t_room	tmp;
	int		i;

	if (!(tab && *tab))
		return ;
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
		(*tab)[i].wth = 0;
		(*tab)[i].taken = 0;
		(*tab)[i].next = current->next;
		current = current->next;
		i++;
	}
	if (check_startend(begin))
		order_tabroom(tab);
	free_lst_room(begin);
}

void	fill_matrix2(t_room *tab, t_link **c, int **matrix, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (ft_strcmp(tab[j].name, (*c)->name1) == 0
				|| ft_strcmp(tab[j].name, (*c)->name2) == 0)
		{
			matrix[i][i] = matrix[i][i] + 1;
			matrix[j][j] = matrix[j][j] + 1;
			matrix[j][i] = -1;
			matrix[i][j] = -1;
			return ;
		}
		j++;
	}
}

void	fill_matrix(t_room *tab, t_link **begin, int **matrix, int size)
{
	int		i;
	t_link	*c;

	i = 1;
	while (i < size)
	{
		c = *begin;
		while (c)
		{
			if (ft_strcmp(tab[i].name, c->name1) == 0
					|| ft_strcmp(tab[i].name, c->name2) == 0)
				fill_matrix2(tab, &c, matrix, i);
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
