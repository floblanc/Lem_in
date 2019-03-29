/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:16:42 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/29 12:35:49 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	rooms_in_tab(t_room **tab, t_room **begin)
{
	t_room	*current;
	int		i;
	int		size;

	size = ft_lstlen(begin);
	if (!(*tab = (t_room*)malloc(sizeof(t_room) * size)))
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
		(*tab)[i].next = current->next;
		current = current->next;
		i++;
	}
	free_lst_room(begin);
	order_tabroom(tab);
}

void	order_tabroom(t_room **tab)
{
	t_room	tmp;
	int	i;

	i = 0;
	while ((*tab)[i].startend != 1)
		i++;
	tmp = (*tab)[0];
	(*tab)[0] = (*tab)[i];
	(*tab)[0].next = (*tab)[i].next;
	(*tab)[i] = tmp;
	(*tab)[i].next = tmp.next;
	i = 0;
	while ((*tab)[i].startend != 2)
		i++;
	tmp = (*tab)[1];
	(*tab)[1] = (*tab)[i];
	(*tab)[1].next = (*tab)[i].next;
	(*tab)[i] = tmp;
	(*tab)[i].next = tmp.next;
}

int		**set_matrix(t_room *tab, int size)
{
	int 	**matrix;
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
	return (matrix);
}

void	assign_value(int **matrix, int i, int j)
{	
	matrix[i][i] += 1;
	matrix[j][j] += 1;
	matrix[j][i] = -1;
	matrix[j][i] = -1;
}

int		**fill_matrix(t_room *tab, t_link **begin, int **matrix, int size)
{
	int		i;
	int		j;
	t_link	*c;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j + i + 1 < size)
		{
			c = *begin;
			while (c)
			{
				if ((!(ft_strcmp(tab[i].name, c->name1))
							&& !ft_strcmp(tab[j].name, c->name2))
						|| (!(ft_strcmp(tab[i].name, c->name2))
							&& !(ft_strcmp(tab[j].name, c->name1))))
					assign_value(matrix, i, j);
				c = c->next;
			}
			j++;
		}
		i++;
	}
	return (matrix);
}
