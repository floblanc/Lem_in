/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/12 19:04:04 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	main4(t_path **best, t_path **new)
{
	if (!(*best))
	{
		*best = *new;
		*new = 0;
	}
	else if (*best && (*new)->step > 0 && (*new)->step < (*best)->step)
	{
		free_paths(best);
		*best = *new;
	}
	else
		free_paths(new);
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
	while (++i < path_max && enougth_room_for_more(best, tab))
	{
		new = 0;
		init_t_path(&new, size, i);
		copy_best(best, new, size);
		if (!(find_path(matrix, tab, new, size)))
			break ;
		calc_step(new, tab[0].taken, 1);
		main4(&best, &new);
	}
	use_path(best, tab);
/*	
	int j;
	i = 0;
	while (i < best->path_n)
	{
		j = 0;
		while (best->path[i][j] != 0)
		{
			printf("path[%d][%d] = %d -> room : %s \n", i, j, best->path[i][j], tab[best->path[i][j]].name);
			j++;
		}
		i++;
	}


*/
	free_paths(&best);
	free_paths(&new);
}

void	main2(t_room *roombeg, t_link *linkbeg, int ant_n, t_write *str)
{
	int		**matrix;
	t_room	*tab;
	int		size;

	tab = 0;
	matrix = 0;
	size = ft_lstlen(&roombeg);
	rooms_in_tab(&tab, &roombeg);
	matrix = set_matrix(tab, &linkbeg, size);
	put_wth(matrix, 1, 0, tab);
	if (tab[0].wth <= 0)
		write(2, "ERROR\n", 6);
	else
	{
		tab[0].taken = ant_n;
		write_data(&str);
		main3(matrix, tab, size);
	}
	free_room_tab(&tab, size);
	free_matrix(&matrix, size);
	free_lst_write(&str);
	return ;
}

int		main(void)
{
	int		ant_n;
	t_room	*roombeg;
	t_link	*linkbeg;
	t_write	*str;

	ant_n = 0;
	roombeg = 0;
	linkbeg = 0;
	str = 0;
	read_n_stock(&ant_n, &roombeg, &linkbeg, &str);
	main2(roombeg, linkbeg, ant_n, str);
	return (0);
}
