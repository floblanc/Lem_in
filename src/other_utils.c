/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 09:48:06 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/28 17:42:54 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	try_one_more(t_room *tab, t_path *new)
{
	int	i;
	int	j;

	i = 0;
	while (i < new->path_n)
	{
		j = 0;
		if (new->len[i] > 0 && new->path[i][new->len[i]] == 0)
		{
			//printf("path[%d][%d] = %d deleted\n", i, new->len[i], new->path[i][new->len[i]]);
			while (j < new->len[i])
			{
				if (new->path[i][j] > 0)
					tab[new->path[i][j]].taken = 0;
				new->path[i][j] = 0;
				j++;
			}
			new->path[i][j] = 0;
			new->len[i] = 0;
		}
		else if (new->len[i] == -1)
		{
			//printf("path[%d] reset\n", i);
			tab[new->path[i][j]].taken = 0;
			new->path[i][0] = 0;
			new->path[i][1] = 0;
			new->len[i] = 0;
		}
		else
			new->path[i][new->len[i]] = 0;
		i++;
	}
}

int		other_turn(int **matrix, t_room *tab, int *way, int room_n)
{
	int	i;
	int	lim;
	int	j;

	i = 0;
	j = 0;
	//printf("si y a pas pouet c'est que ca plante du premier coup (room_n %d)\n", room_n);
	while (way[i] != room_n)//si ca segfault c'est peut etre la mais ca devrait pas
		i++;
	if (!(way[i] && i))
		return (0);
	i--;
	lim = matrix[way[i]][way[i]];
	while (lim > 0)
	{
		if (matrix[way[i]][j] == -1)
		{
			lim--;
			if (tab[j].taken == 0 && tab[j].wth <= tab[room_n].wth + 1)
			{
				//			printf("pouet1\n");
				return (1);
			}
		}
		j++;
	}
	//	printf("pouet0\n");
	return (0);
}
