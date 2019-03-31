/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/31 17:56:08 by floblanc         ###   ########.fr       */
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
		while (j < size)
		{
			if (path_tab[i][j] == room_to_test && room_to_test != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		how_many_paths(t_room *tab, int **matrix, int ant_n, int size)
{
	int available;
	int	step_min;
	int path_n;

	step_min = size;
	available = (matrix[0][0] > matrix[1][1] ? matrix[1][1] : matrix[0][0]);
	path_n = 0;
	while (available > 0)
	{
		if  ((tab[0].wth + ((ant_n - 1) / available)) <= min)
		{
			step_min = tab[0].wth + ((ant_n - 1) / available);
			path_n = available;
		}
		availables--;
	}
	return (path_n);
}

int		**set_paths(int path_n, t_room *tab, int **matrix, int size)
{
	int **path_tab;
	int	i;
	int j;

	i = 0;
	if (!(path_tab = (int**)malloc(sizeof(int*) * path_n)))
		exit(0);
	while (i < path_n)
	{
		if (!(path_tab[i++] = (int*)malloc(sizeof(int) * tab[0].wth)))
			exit(0);
		j = 0;
		while (j < size)
			path[i][j++] = 0;
		i++;
	}
}
