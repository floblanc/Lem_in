/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/27 12:07:25 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	main4(t_path **best, t_path **new, int size, t_room *tab)
{
	if (!(new && *new))
		return ;
	if (!(*best))
	{
		init_t_path(best, size, (*new)->path_n);
		copy_best(*new, *best, size, tab);
		calc_step(*best, tab[0].taken, (*best)->path_n);
	}
	else if (*best && (*new)->step > 0 && (*new)->step < (*best)->step)
	{
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
	clean_used(tab, size);
	clean_some_taken(tab, size);
	path_max = ((matrix[1][1] > matrix[0][0]) ? matrix[0][0] : matrix[1][1]);
	path_max = ((path_max > tab[0].taken) ? tab[0].taken : path_max);
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

void	main3(int **matrix, t_room *tab, int *wth_cpy, int size)
{
	t_path	*better;
	t_path	*best_tmp;
	int		i;
	int		j;

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
			best_tmp = main_3bis(matrix, tab, size, j);
			main4(&better, &best_tmp, size, tab);
			free_paths(&best_tmp);
		}
		j++;
	}
	stock_and_print_step(0, better->step);
	use_path(&better, tab, size);
}

void	main2(t_room **roombeg, int ant_n, t_write **str, int arg)
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
		if (arg = 1)
			return (print_matrix(matrix, size, str, tab));
		if (!(main2_onelink(matrix, tab, ant_n, str)))
			return ;
		put_wth(matrix, tab, size, 1);
	}
	if (ant_n <= 0 || tab[0].wth <= 0)
		write(2, "ERROR\n", 6);
	else
		lets_algo(matrix, str, tab, ant_n);
	free_room_tab(&tab, size);
	free_matrix(&matrix, size);
	free_lst_write(str);
	return ;
}

int		main(int ac, int av)
{
	int		ant_n;
	t_room	*roombeg;
	t_write	*str;
	int		arg_used;
// idee de bonus : -h/-help qui explique comment se servir du programme (tres simple a faire et a implementer)
//				   -m/-matrix qui afficherai la matrice (faut envoyer autre chose que size a main 2 mais c'est jouable) et a definir si l'affichage se fait avec ou sans le reste des resultats ou on laisse le choix etc.. (et voir si on met des couleurs dans la matrice etc...)
//				   -s/step(s) qui afficherait le nombre de step (si on met use_path et free_path du main3 dans une seule fonction (ou plus simplement mettre free_path dans use_path y’a la place) on peut lancer une autre fonction qui stockera les step dans une statique qu’on récupèrera par la suite en relançant cette fonction depuis le main de base)
	ant_n = 0;
	roombeg = 0;
	str = 0;
	arg_used = 0;
	if (ac > 2 || !(check_args(ac, av, &arg_used)))
		return (0)
	read_n_stock(&ant_n, &roombeg, &str);
	main2(&roombeg, ant_n, &str, arg_used);
	if (arg_used == 2)
		stock_and_print_step(1, 0);
	free_lst_room(&roombeg);
	return (0);
}
