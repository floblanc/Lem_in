/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/17 11:55:08 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	main4(t_path **best, t_path **new, int size, t_room *tab)
{
	//	printf("new step = %d\n",(*new)->step);
	if (!(new && *new))
		return ;
	if (!(*best))
	{
	//	printf("%d steps\n",(*new)->step);
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size, tab);
		calc_step(*best, tab[0].taken, (*best)->path_n);
	}
	else if (*best && (*new)->step > 0 && (*new)->step < (*best)->step)
	{
	//	printf("from %d steps to %d steps\n",(*best)->step, (*new)->step);
		free_paths(best);
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size, tab);
		calc_step(*best, tab[0].taken, (*best)->path_n);
	}
	//printf("new->step %d, new_path_n : %d,  best->step %d, best-Path_n : %d\n",(*new)->step, (*new)->path_n, (*best)->step, (*best)->path_n);
}

t_path	*main_3bis(int **matrix, t_room *tab, int size, int first_room)
{
	int		i;
	int		path_max;
	t_path	*best;
	t_path	*new;

	i = 0;
	best = 0;
	new = 0;
	clean_some_taken(tab, size);
	path_max = ((matrix[1][1] > matrix[0][0]) ? matrix[0][0] : matrix[1][1]);
	path_max = ((path_max > tab[0].taken) ? tab[0].taken : path_max);
	while (++i <= path_max)
	{
		init_t_path(&new, size, i);
		new->path[0][0] = first_room;
		tab[new->path[0][0]].taken = 1;
		copy_best(best, new, size, tab);
		if (!(find_path(matrix, tab, &new, best)))
			break ;
		sort_paths(&new, size, tab, matrix);
		calc_step(new, tab[0].taken, i);
		if (best && new->step >= best->step && new->path_n > best->path_n)
			break ;
		main4(&best, &new, size, tab);
		free_paths(&new);
	}
	free_paths(&new);
	return (best);
}

void	main3(int **matrix, t_room *tab, int size)
{
	t_path	*better;
	t_path	*best_tmp;
	int		i;
	int		j;

	better = 0;
	i = matrix[0][0];
	j = 2;
	printf("tab[matrix[1][1]].wth = %d\n", tab[matrix[1][1]].wth);
	while (i > 0)
	{
		while (matrix[0][j] != -1)
			j++;
		//printf("ON START A LA SALLE: %d(%s)\n", j, tab[j].name);
		i--;
		if (tab[j].wth > 0)
		{
			best_tmp = main_3bis(matrix, tab, size, j);
			main4(&better, &best_tmp, size, tab);
			printf("%d stepsiBETTER\n",better->step);
			free_paths(&best_tmp);
		}
		j++;
		/*
		int k;
		int l;
		l = 0;
		printf("better->step %d, better_path_n : %d,  new->step %d, better-Path_n : %d\n", (better)->step, (better)->path_n, (better)->step, (better)->path_n);
		while (l < better->path_n)
		{
			k = 0;
			while (better->path[l][k] != 1 && better->path[l][k] != -1 && better->len[l] > 0)
			{
				printf("\npath[%d][%d] = %d -> room : %s.wth = %d taken = %d", l, k, better->path[l][k], tab[better->path[l][k]].name, tab[better->path[l][k]].wth, tab[better->path[l][k]].taken);
				k++;
			}
			printf("\npath[%d][%d] = %d -> room: %s.wth = %d taken = %d", l, k, better->path[l][k], tab[better->path[l][k]].name, tab[better->path[l][k]].wth, tab[better->path[l][k]].taken);
			printf("\nlen = %d\n", better->len[l]);
			l++;
		}
	*/}
	printf("%d steps better", better->step);
	//use_path(best, tab, size);
	free_paths(&better);
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
			put_wth(matrix, tab, size);
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
