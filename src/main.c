/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/19 19:21:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	main4(t_path **best, t_path **new, int size/*, t_room *tab*/)
{
	if (!(*best))
	{
		printf("%d steps\n",(*new)->step);
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size);
	}
	else if (*best && (*new)->step > 0 && (*new)->step < (*best)->step)
	{
		printf("from %d steps to %d steps\n",(*best)->step, (*new)->step);
		free_paths(best);
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size);
	}
}

void	main3(int **matrix, t_room *tab, int size)
{
	t_path	*best;
	t_path	*new;
	int		path_max;
	int		i;

	i = 0;
	best = 0;
	path_max = ((matrix[1][1] > matrix[0][0]) ? matrix[0][0] : matrix[1][1]);
	path_max = ((path_max > tab[0].taken) ? tab[0].taken : path_max);
	while (++i <= path_max && enougth_room_for_more(best, tab))
	{
		new = 0;
		free_paths(&new);
		init_t_path(&new, size, i);
		copy_best(best, new, size);
		clean_some_taken(tab, size, -1);
		while ((find_path(matrix, tab, &new, size) > 0))
		{

			calc_step(new, tab[0].taken, i);
			main4(&best, &new, size/*, tab*/);
			printf("tab[%d](%s).taken = -%d\n", new->path[i - 1][new->len[i - 1] - 2], tab[new->path[i -1 ][new->len[i -1] - 2]].name, tab[new->path[i -1 ][new->len[i -1] - 2]].taken);
			printf("tab[%d](%s).taken = -%d\n", new->path[i - 1][new->len[i - 1] - 2], tab[new->path[i -1 ][new->len[i -1] - 2]].name, i);
			tab[new->path[i - 1][new->len[i - 1] - 2]].taken = i * -1;
			new->path[i - 1][new->len[i - 1] - 2] = 0;
			new->path[i - 1][new->len[i - 1] - 1] = 0;
			new->path[i - 1][new->len[i - 1]] = 0;
			new->len[i - 1] = 0;
		}
	}



	int j;
	i = 0;
	while (i < best->path_n)
	{
		j = 0;
		while (best->path[i][j] != 1)
		{
			printf("\npath[%d][%d] = %d -> room : %s.wth = %d taken = %d", i, j, best->path[i][j], tab[best->path[i][j]].name, tab[best->path[i][j]].wth, tab[best->path[i][j]].taken);
			j++;
		}
		printf("\npath[%d][%d] = %d -> room : %s.wth = %d taken = %d", i, j, best->path[i][j], tab[best->path[i][j]].name, tab[best->path[i][j]].wth, tab[best->path[i][j]].taken);
		printf("\nlen = %d\n", best->len[i]);
		i++;
	}

	calc_step(best, tab[0].taken, i);
	use_path(best, tab, size);
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
		matrix = set_matrix(tab, str, size);
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
