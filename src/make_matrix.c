/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:16:42 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/19 14:55:35 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	order_tabroom(t_room **tab, t_room **begin)
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
	free_lst_room(begin);
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
		order_tabroom(tab, begin);
}

int		fill_matrix2(t_room *tab, char *str, int **matrix, int i)
{
	int		j;

	j = 0;
	while (tab[j].next)
	{
		if (ft_strcmp(tab[j].name, str) == 0 && matrix[i][j] == 0)
		{
			matrix[i][i] = matrix[i][i] + 1;
			matrix[j][j] = matrix[j][j] + 1;
			matrix[j][i] = -1;
			matrix[i][j] = -1;
			return (1);
		}
		j++;
	}
	if (ft_strcmp(tab[j].name, str) == 0 && matrix[i][j] == 0)
	{
		matrix[i][i] = matrix[i][i] + 1;
		matrix[j][j] = matrix[j][j] + 1;
		matrix[j][i] = -1;
		matrix[i][j] = -1;
		return (1);
	}
	return (0);
}

void	run_in_links(t_room *tab, int **matrix, int size, t_write **begin)
{
	t_write *current;
	char	*line;
	int		error;

	current = *begin;
	line = 0;
	error = 0;
	while (current->next)
				current = current->next;
	if (!(fill_matrix(tab, matrix, current->str, size)))
		return ;
	while (get_next_line(0, &line) > 0)
	{
		if (link_form_is_valid(line))
		{
			if (!(fill_matrix(tab, matrix, line, size)))
				break ;
		}
		else if (line[0] != '#' || command_is_valid(line))
			error = 1;
		if (error)
			break;
		stock_to_write(line, begin);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		**set_matrix(t_room *tab, t_write **str, int size)
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
	run_in_links(tab, matrix, size, str);
	return (matrix);
}
