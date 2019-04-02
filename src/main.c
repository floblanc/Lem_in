/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/02 15:15:24 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int		ant_n;
	t_room	*roombeg;
	t_link	*linkbeg;
	t_write	*str;
	int		**matrix;
	t_room	*tab;
	int		size;

	tab = 0;
	matrix = 0;
	str = 0;
	ant_n = 0;
	roombeg = 0;
	linkbeg = 0;
	read_n_stock(&ant_n, &roombeg, &linkbeg, &str);
	size = ft_lstlen(&roombeg);
	rooms_in_tab(&tab, &roombeg);
	matrix = set_matrix(tab, &linkbeg, size);
	bfs(matrix, 1, 0, tab);
	int		i = 0;
	int		j;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d\t", matrix[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	i = 0;
	while (i < size)
	{
		printf("name = %s, x = %d, y = %d, startend = %d, wth = %d, taken = %d, p= %p\n", tab[i].name, tab[i].x, tab[i].y, tab[i].startend, tab[i].wth, tab[i].taken, tab[i].next);
		i++;
	}
	printf("size = %d\n",size);
	return (0);
}
