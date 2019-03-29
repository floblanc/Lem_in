/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weigth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:12:20 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/29 20:11:20 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		all_wth_done(t_room *tab, int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{/*
		si fourmillere coupe en 2 avec start-end (avec ou sans autres salles)d'un cote 
		et le reste qui est lie le l'autre sans lien en les 2 cote c'est la merde
		mais si on parse en bloquant quand start est atteint, ca nique d'autre cas
		dans lesquels si on a 2 chemins distincts avec un beaucoup plus long que
		l'autre ca stop trop tot et certaines salles du chemin plus long sont mise
		a -1 alors qu'il serait utile avec beaucoup de fourmis

		---conditions d'arrets a regler ou autre astuce a trouver---
	*/
		if (/*(*/matrix[i][i] == 0 /*|| tab[0].wth != 0)*/ && tab[i].wth == 0 && i != 1)
			tab[i].wth = -1;
		if (tab[i].wth == 0 && i != 1 && tab[0].wth == 0)
			return (0);
		i++;
	}
	return (1);
}

void	put_weigth(t_room *tab, int **matrix, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		if (matrix[1][j] == -1 && (matrix[j][j] > 1 || j == 0))
			tab[j].wth = 1;
		else if (matrix[1][j] == -1 && matrix[j][j] <= 1 && j != 0)
			tab[j].wth = -1;
		j++;
	}
	while (!(all_wth_done(tab, matrix, size)))
	{
		i = 0;
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				if (matrix[i][j] == -1 && j != 1 && tab[j].wth == 0 
						&& tab[i].wth > 0 && (matrix[j][j] > 1 || j == 0))
					tab[j].wth = tab[i].wth + 1;
				else if (matrix[i][j] == -1 && j != 0 && j != 1 
						&& tab[j].wth == 0 && matrix[j][j] <= 1)
					tab[j].wth = -1;
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		printf("room[%s] : wth = %d, degre: %d\n", tab[i].name, tab[i].wth, matrix[i][i]);
		i++;
	}
}
