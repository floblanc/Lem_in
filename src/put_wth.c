/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:24:49 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/17 12:18:17 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	push_queue(int **queue)
{
	int	i;

	i = 0;
	while ((*queue)[i] != -1)
	{
		(*queue)[i] = (*queue)[i + 1];
		i++;
	}
}

void		add_to_queue(int **queue, int room)
{
	int	i;

	i = 0;
	while ((*queue)[i] != -1)
	{
		if ((*queue)[i] == room)
			return ;
		i++;
	}
	(*queue)[i] = room;
}

void	put_wth(int **matrix, t_room *tab, int size)
{
	int	*visited;
	int	*queue;
	int	i;
	int	j;
	int	lim;

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
	i = 0;
	while (queue[0] != -1)
	{
		visited[i] = queue[0];
		push_queue(&queue);
		lim = matrix[visited[i]][visited[i]];
		j = 0;
		while (lim > 0)
		{
			if (matrix[visited[i]][j] == -1)
			{
				lim--;
				if (visited[i] != 0 && (tab[j].wth == 0))
				{
					tab[j].wth = tab[visited[i]].wth + 1;
					add_to_queue(&queue, j);
				}
			}
			j++;
		}
		i++;
	}
	free(queue);
	free(visited);
}

void	onelink_startend(int ant_n)
{
	int i;

	i = 1;
	printf("\n");
	while (i != ant_n)
	{
		printf("L%d-end ", i);
		i++;
	}
	printf("L%d-end", i);
}

int		fill_matrix(t_room *tab, int **matrix, char *str, int size)
{
	int		i;
	int		run;

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
