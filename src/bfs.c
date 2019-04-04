/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:01:32 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 17:10:38 by floblanc         ###   ########.fr       */
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

void	bfs(int **matrix, int i, int j, t_room *tab)
{
	static int	size;

	if (!(size))
		size = calc_size(tab);
	if (i >= size || j >= size || i == 0)
		return ;
	while (j < size && (j == 1 || matrix[i][j] != -1 || (tab[j].wth != 0
					&& tab[j].wth <= tab[i].wth + 1)))
		j++;
	if (j == size)
		return ;
	tab[j].wth = tab[i].wth + 1;
	bfs(matrix, i, j + 1, tab);
	bfs(matrix, j, 0, tab);
}

void	calc_step(t_path *struc, int ant_n, int path_n)
{
	int	i;

	struc->path[0][struc->len[0]] = ant_n;
	if (path_n == 1)
	{
		struc->step = struc->len[0] + struc->path[0][struc->len[0]] - 1;
		return ;
	}
	i = 1;
	while (i > 0)
	{
		i = 0;
		while ((i < path_n - 1) && (struc->len[i] + struc->path[i][struc->len[i]] - 1 >= struc->len[i + 1] + struc->path[i + 1][struc->len[i + 1]]))
			i++;
		if (i > 0)
		{
			struc->path[0][struc->len[0]]--;
			struc->path[i][struc->len[i]]++;
		}
	}
	struc->step = struc->len[1] + struc->path[1][struc->len[1]] - 1;
}

int	main(int ac, char **av)
{
	int ant_n = atoi(av[1]);
	t_path test;
	int tablen[3]={5,8};
	int	len0[15] = {1,2,3,4,5,0,0,0,0,0,0,0,0,0,0};
	int	len1[15] = {1,2,3,4,5,6,7,8,0,0,0,0,0,0,0};
	//int	len2[15] = {1,2,3,4,5,6,7,8,9,10,11,12,0,0,0};

	if (ac == 2)
	{
		test.path = (int**)malloc(sizeof(int*) * 2);
		test.path[0] = len0;
		test.path[1] = len1;
	//	test.path[2] = len2;
		test.len = tablen;
		calc_step(&test, ant_n, 2);
		printf("step : %d\nlen0 : %d\nlen1 %d\n", test.step,len0[5],len1[8]);
	}
	return (0);
}

/*void	algo(t_room *tab, int **matrix)
{
	t_path	*path;
}*/
