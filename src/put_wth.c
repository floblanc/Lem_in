/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:24:49 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/25 00:43:32 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_queue(int **queue, int room, int add_or_push)
{
	int	i;

	i = 0;
	if (add_or_push == 1)
	{
		while ((*queue)[i] != -1)
		{
			if ((*queue)[i] == room)
				return ;
			i++;
		}
		(*queue)[i] = room;
	}
	else
		while ((*queue)[i] != -1)
		{
			(*queue)[i] = (*queue)[i + 1];
			i++;
		}
}

void	full_put_wth2(int *visited, int *queue, int **matrix, t_room *tab)
{
	int			i;
	int			j;
	int			lim;
	static int	size;

	if (!(size))
		size = calc_size(tab);
	i = -1;
	while (queue[0] != -1 && ++i < size)
	{
		visited[i] = queue[0];
		add_to_queue(&queue, 0, 0);
		lim = matrix[visited[i]][visited[i]];
		j = -1;
		while (lim > 0 && j < size)
		{
			if (matrix[visited[i]][++j] == -1 && lim-- > 0 && matrix[j][j] > 1
					&& visited[i] != 0 && tab[j].wth == 0 && j != 1)
			{
				tab[j].wth = tab[visited[i]].wth + 1;
				add_to_queue(&queue, j, 1);
			}
		}
	}
}

void	put_wth2(int *visited, int *queue, int **matrix, t_room *tab)
{
	int			i;
	int			j;
	int			lim;
	static int	size;

	if (!(size))
		size = calc_size(tab);
	i = -1;
	while (queue[0] != -1 && ++i < size)
	{
		visited[i] = queue[0];
		add_to_queue(&queue, 0, 0);
		lim = matrix[visited[i]][visited[i]];
		j = 0;
		while (lim > 0 && j < size)
		{
			lets_search_match(matrix, visited[i], &j);
			if (matrix[visited[i]][j] == -1 && lim-- > 0 && matrix[j][j] > 1
					&& visited[i] != 0 && tab[j].wth == 0 && j != 1)
			{
				tab[j].wth = tab[visited[i]].wth + 1;
				if (j == 0)
					return ;
				add_to_queue(&queue, j, 1);
			}
			j++;
		}
	}
}

void	put_wth(int **matrix, t_room *tab, int size, int full)
{
	int			*visited;
	int			*queue;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(queue = (int*)malloc(sizeof(int) * size)))
		return ;
	if (!(visited = (int*)malloc(sizeof(int) * size)))
		return ;
	while (i < size)
	{
		visited[i] = -1;
		queue[i++] = -1;
	}
	queue[0] = 1;
	if (full == 0)
		put_wth2(visited, queue, matrix, tab);
	else
		full_put_wth2(visited, queue, matrix, tab);
	free(queue);
	free(visited);
}

int		fill_matrix(t_room *tab, int **matrix, char *str, int size)
{
	int			i;
	int			run;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	str[i] = '\0';
	run = 0;
	while (run < size && ft_strcmp(tab[run].name, str) != 0)
		run++;
	str[i] = '-';
	if (run < size && fill_matrix2(tab, str + i + 1, matrix, run))
		return (1);
	return (0);
}
