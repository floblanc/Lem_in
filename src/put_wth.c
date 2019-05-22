/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:24:49 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/21 15:40:08 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_to_queue(int **queue, int room, int add_or_push, int *first)
{
	int			i;
	static int	last;

	if ((*first) == 1)
	{
		last = 1;
		*first = 0;
	}
	i = 0;
	if (add_or_push == 1)
		(*queue)[last++] = room;
	else
	{
		while ((*queue)[i] != -1)
		{
			(*queue)[i] = (*queue)[i + 1];
			i++;
		}
		last--;
	}
}

void	put_wth2(int *visited, int *queue, int **matrix, t_room *tab)
{
	int			i;
	int			j;
	int			lim;
	static int	size;
	int			first;

	first = 1;
	i = -1;
	if (!(size))
		size = calc_size(tab);
	while (queue[0] != -1 && ++i < size)
	{
		visited[i] = queue[0];
		add_to_queue(&queue, 0, 0, &first);
		lim = matrix[visited[i]][visited[i]];
		j = -1;
		while (lim > 0)
			if (matrix[visited[i]][++j] == -1 && lim-- > 0 && matrix[j][j] > 1
					&& visited[i] != 0 && tab[j].wth == 0)
			{
				tab[j].wth = tab[visited[i]].wth + 1;
				add_to_queue(&queue, j, 1, &first);
			}
	}
}

void	put_wth(int **matrix, t_room *tab, int size)
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
	put_wth2(visited, queue, matrix, tab);
	free(queue);
	free(visited);
}

void	onelink_startend(int ant_n)
{
	int			i;

	i = 1;
	ft_printf("\n");
	while (i != ant_n)
	{
		ft_printf("L%d-end ", i);
		i++;
	}
	ft_printf("L%d-end", i);
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
