/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/09 14:10:02 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		calc_size(t_room *tab)
{
	int		size;

	size = 0;
	while (tab[size].next)
		size++;
	size++;
	return (size);
}

/*int		room_already_use(int room_to_test, int **path_tab, int path_n, int size)
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

int		how_many_steps(int ant_n, int **path_tab, int path_n)
{
	int	step_min;

	step_min = size;
	while (step_min > 0)
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

int		**set_paths(int **matrix, int size, int path_n)
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
}*/
