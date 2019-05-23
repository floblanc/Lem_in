/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/23 22:42:43 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_dead_end(int **matrix, t_room *tab, int j)
{
	int lim;
	int exit;
	int	i;

	lim = matrix[j][j];
	exit = 0;
	i = 0;
	while (lim > 0)
	{
		if (matrix[j][i] == -1)
		{
			lim--;
			if (tab[i].wth > 0)
				if (++exit > 1)
					return (0);
		}
		i++;
	}
	return (1);
}

void	close_wth2(int *visited, int *queue, int **matrix, t_room *tab)
{
	int			i;
	int			j;
	int			lim;
	int			size;

	i = -1;
	size = calc_size(tab);
	while (queue[0] != -1 && ++i < size)
	{
		visited[i] = queue[0];
		add_to_queue(&queue, 0, 0);
		lim = matrix[visited[i]][visited[i]];
		j = -1;
		while (lim > 0)
			if (matrix[visited[i]][++j] == -1 && lim-- > 0
					&& visited[i] != 0 && tab[j].wth >= 0 && j != 1
					&& (matrix[j][j] <= 2 || is_dead_end(matrix, tab, j)))
			{
				tab[j].wth = -1;
				add_to_queue(&queue, j, 1);
			}
	}
}

void	close_wth(int **matrix, t_room *tab, int size, int start)
{
	int			*visited;
	int			*queue;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(queue = (int*)malloc(sizeof(int) * size)))
		return ;
	if (!(visited = (int*)malloc(sizeof(int) * size)))
		return ;
	while (i < size)
	{
		visited[i] = -1;
		queue[i++] = -1;
	}
	queue[0] = start;
	close_wth2(visited, queue, matrix, tab);
	free(queue);
	free(visited);
}

void	close_wrong_wth(int **matrix, t_room *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (matrix[i][i] == 1 && tab[i].wth >= 0)
		{
			tab[i].wth = -1;
			close_wth(matrix, tab, size, i);
		}
		i++;
	}
}

void	copy_wth(int **cpy, t_room *tab, int size)
{
	int	i;

	i = -1;
	if (!(*cpy = (int*)malloc(sizeof(int) * size)))
		exit (0);
	while (++i < size)
		(*cpy)[i] = tab[i].wth;
}

void	reset_wth(int *cpy, t_room *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		tab[i].wth = cpy[i];
}

void	main4(t_path **best, t_path **new, int size, t_room *tab)
{
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
	//printf("degre start %d, degre end %d, ants %d, tab[%d{first room}].wth = %d\n", matrix[0][0], matrix[1][1], tab[0].taken, first_room, tab[first_room].wth);;
	while (++i <= path_max)
	{
		init_t_path(&new, size, i);
		new->path[0][0] = first_room;
		if (!(main_findpath(matrix, tab, &new, best)))
			break ;
		calc_step(new, tab[0].taken, i);
		if (best && new->step >= best->step && new->path_n > best->path_n)
			break ;
		main3_ter(matrix, tab, &new, &best);
	}
	free_paths(&new);
	return (best);
}

void	main3(int **matrix, t_room *tab, int size)
{
	t_path	*better;
	t_path	*best_tmp;
	int 	*wth_cpy;
	int		i;
	int		j;

	wth_cpy = 0;
	copy_wth(&wth_cpy, tab, size);
	better = 0;
	i = matrix[0][0];
	j = 2;
	while (i > 0)
	{
		while (matrix[0][j] != -1)
			j++;
		i--;
		if (matrix[0][0] - 1 != i)
			reset_wth(wth_cpy, tab, size);
		if (tab[j].wth > 0)
		{
			clean_used(tab, size);
			best_tmp = main_3bis(matrix, tab, size, j);
			main4(&better, &best_tmp, size, tab);
			free_paths(&best_tmp);
		}
		j++;
	}
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
	   printf("\nlen = %d Path_n = %d\n", better->len[l], better->path_n);
	   l++;
	   }
	   */
	i = better->step;
	use_path(better, tab, size);
	free_paths(&better);
	printf("step == %d\n", i);
}

void	main2(t_room **roombeg, int ant_n, t_write **str, int size)
{
	int		**matrix;
	t_room	*tab;

	tab = 0;
	matrix = 0;
	if (ant_n > 0)
	{
		rooms_in_tab(&tab, roombeg);
		set_matrix(tab, str, size, &matrix);
		if (!(main2_onelink(matrix, tab, ant_n, str)))
			return ;
		put_wth(matrix, tab, size);
		//close_wrong_wth(matrix, tab, size);
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
	int		size;

	ant_n = 0;
	roombeg = 0;
	str = 0;
	read_n_stock(&ant_n, &roombeg, &str);
	size = ft_lstlen(&roombeg);
	main2(&roombeg, ant_n, &str, size);
	free_lst_room(&roombeg);
	return (0);
}
