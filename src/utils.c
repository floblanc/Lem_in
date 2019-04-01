/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/01 15:58:19 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_already_use(int room_to_test, int **path_tab, int path_n, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < path_n)
	{
		j = 0;
		while (path_tab[i][j] != 0)
		{
			if (path_tab[i][j] == room_to_test && room_to_test != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		how_many_steps(t_room *tab, int ant_n, int **path_tab, int path_n)
{
	int	step_min;

	step_min = size;
	while ( > 0)
	{
		if  ((tab[0].wth + ((ant_n - 1) / available)) <= step_min)
		{
			step_min = tab[0].wth + ((ant_n - 1) / available);
			path_n = available;
		}
		available--;
	}
	return (path_n);
}

int		**set_paths(t_room *tab, int **matrix, int size, int path_n)
{
	int **path_tab;
	int	i;
	int j;

	i = 0;
	if (!(path_tab = (int**)malloc(sizeof(int*) * path_n)))
		exit(0);
	while (i < path_n)
	{
		if (!(path_tab[i++] = (int*)malloc(sizeof(int) * size)))
			exit(0);
		j = 0;
		while (j < size)
			path_tab[i][j++] = 0;
		i++;
	}
	return (path_tab);
}

void	recurtest(t_room *tab, int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (max == tab[i].wth)
		{
			j = 0;
			while (j < size)
			{
				if (matrix[i][j] == -1 && i != 0 && j != 1 && tab[j].wth == 0
						&& (matrix[j][j] > 1 || j == 0))
					tab[j].wth = max + 1;
				else if (matrix[i][j] == -1 && j != 1 && tab[j].wth == 0
						&& matrix[j][j] <= 1)
					tab[j].wth = -1;
				j++;
			}
		}
		i++;
	}
	if (!(all_wth_done(tab, matrix, size)))
		recurtest(tab, matrix, size, max + 1);
}
