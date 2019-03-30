/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weigth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:12:20 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/30 20:54:13 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		all_wth_done(t_room *tab, int **matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (tab[i].wth == 0 && matrix[i][i] != 0 && i != 1)
		{
			j = 0;
			while (j < size)
			{
				if (matrix[i][j] == -1 && (tab[j].wth > 0 || j == 1))
					return (0);
				j++;
			}
		}
		i++;
	}
	i = -1;
	while (++i < size)
		if (tab[i].wth == 0 && i != 1)
			tab[i].wth = -1;
	return (1);
}

void	recurtest(t_room *tab, int **matrix, int size, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (max == tab[i].wth)
		{
			j = 0;
			while (j < size)
			{
				if (matrix[i][j] == -1 && i != 0 && j != 1 && tab[j].wth == 0
						&& (matrix[j][j] > 1 || j == 0))
					tab[j].wth = max + 1;
				else if (matrix[i][j] == -1 && j != 1 && tab[j].wth == 0
						&& matrix[j][j] <= 1)
					tab[j].wth = -1;
				j++;
			}
		}
		i++;
	}
	if (!(all_wth_done(tab, matrix, size)))
		recurtest(tab, matrix, size, max + 1);
}

/* 
   Si les poids sont useless a l'algo, alors soit on garde quand meme mais
   on stop quand start est trouve, sinon on vire tout car l'algo peut
   aussi check ca (il y a un chemin entre start et end)
   */
void	put_weigth(t_room *tab, t_write **begin, int **matrix, int size)
{
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
	if (!(all_wth_done(tab, matrix, size)))
		recurtest(tab, matrix, size, 1);
	if (tab[0].wth > 0)
	{
		write_data(begin);
		//ON LANCE L'ALGO ICI OU DANS WRITE_DATA;
	}
	else
		write(1, "ERROR\n", 6);
	//printf("start : degre = %d poids = %d\n", matrix[0][0], tab[0].wth);
	free_room_tab(&tab, size);
	free_matrix(&matrix, size);
	free_lst_write(begin);
}
