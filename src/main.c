/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/03 18:17:28 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	bfs(matrix, 1, 0, tab);
	if (tab[0].wth <= 0)
		write(2, "ERROR\n", 6);
	else
	{
		write_data(&str);
		free_lst_write(&str);
		algosamere(tab, matrix);
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
