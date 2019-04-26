/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/26 17:17:50 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	main4(t_path **best, t_path **new, int size, t_room *tab)
{
	if (!(*best))
	{
		printf("%d steps\n",(*new)->step);
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size, tab);
		calc_step(*best, tab[0].taken, (*best)->path_n);
	}
	else if (*best && (*new)->step > 0 && (*new)->step < (*best)->step)
	{
		printf("from %d steps to %d steps\n",(*best)->step, (*new)->step);
		free_paths(best);
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size, tab);
		calc_step(*best, tab[0].taken, (*best)->path_n);
	}
	//printf("new->step %d, new_path_n : %d,  best->step %d, best-Path_n : %d\n",(*new)->step, (*new)->path_n, (*best)->step, (*best)->path_n);
}

void	main3(int **matrix, t_room *tab, int size)
{
	t_path	*best;
	t_path	*new;
	int		path_max;
	int		i;

	i = 0;
	best = 0;
	new = 0;
	path_max = ((matrix[1][1] > matrix[0][0]) ? matrix[0][0] : matrix[1][1]);
	path_max = ((path_max > tab[0].taken) ? tab[0].taken : path_max);
	init_t_path(&new, size, path_max);
	find_path(matrix, tab, &new, size);

	int j;
	i = 0;
//	printf("new->step %d, new_path_n : %d,  new->step %d, new-Path_n : %d\n",(new)->step, (new)->path_n, (new)->step, (new)->path_n);
	while (i < new->path_n)
	{
		j = 0;
		while (new->path[i][j] != 1 && new->path[i][j] != -1 && new->len[i] > 0)
		{
			printf("\npath[%d][%d] = %d -> room : %s.wth = %d taken = %d", i, j, new->path[i][j], tab[new->path[i][j]].name, tab[new->path[i][j]].wth, tab[new->path[i][j]].taken);
			j++;
		}
	printf("\npath[%d][%d] = %d -> room : %s.wth = %d taken = %d", i, j, new->path[i][j], tab[new->path[i][j]].name, tab[new->path[i][j]].wth, tab[new->path[i][j]].taken);
		printf("\nlen = %d\n", new->len[i]);
		i++;
	}
//	printf("oo %d\n",tab[0].taken);
	calc_step(new, tab[0].taken, new->path_n);
	main4(&best, &new, size, tab);
	//printf("%d steps\n",best->step);
//	use_path(best, tab, size);
	free_paths(&best);
	free_paths(&new);
}

void	main2(t_room **roombeg, int ant_n, t_write **str)
{
	int		**matrix;
	t_room	*tab;
	int		size;

	tab = 0;
	matrix = 0;
	size = ft_lstlen(roombeg);
	if (ant_n > 0)
	{
		rooms_in_tab(&tab, roombeg);
		set_matrix(tab, str, size, &matrix);
		if (matrix[0][1] == -1)
		{
			write_data(str);
			onelink_startend(ant_n);
			free_lst_write(str);
			free_room_tab(&tab, size);
			free_matrix(&matrix, size);
			return ;
		}
		put_wth(matrix, 1, 0, tab);
	}
	if (ant_n <= 0 || tab[0].wth <= 0)
		write(2, "ERROR\n", 6);
	else
	{
		tab[0].taken = ant_n;
		write_data(str);
		main3(matrix, tab, size);
	}
	free_room_tab(&tab, size);
	free_matrix(&matrix, size);
	free_lst_write(str);
	return ;
}

int		main(void)
{
	int		ant_n;
	t_room	*roombeg;
	t_write	*str;

	ant_n = 0;
	roombeg = 0;
	str = 0;
	read_n_stock(&ant_n, &roombeg, &str);
	main2(&roombeg, ant_n, &str);
	free_lst_room(&roombeg);
	return (0);
}
