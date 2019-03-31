/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/31 17:05:50 by floblanc         ###   ########.fr       */
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

int     **set_paths(int path_n, t_room *tab, int **matrix, int size)
{
	int **path_tab;
	int	i;
	int j;

	i = 0;
	//path_n = (matrix[0][0] > matrix[1][1] ? matrix[1][1] : matrix[0][0]);
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
