/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_weigth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:12:20 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/29 17:18:30 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		all_wth_done(t_room *tab)
{
	int	i;

	i = 0;
	while (tab[i].next)
	{
		if (tab[i].wth == 0 && i != 1)
			return (0);
		i++;
	}
/*	if (tab[i].wth == 0 && i != 1)
		return (0);*/
	return (1);
}

void	put_weigth(t_room *tab, int **matrix)
{
	int	i;
	int	j;

	j = 0;
	while (matrix[1][j])
	{
		if (matrix[1][j] == -1 && (matrix[j][j] > 1 || j == 0))
			tab[j].wth = 1;
		else if (matrix[1][j] == -1 && !(matrix[j][j] > 1 || j == 0))
			tab[j].wth = -1;
		j++;
	}
	while (!(all_wth_done(tab)))
	{
		i = 0;
		while (matrix[i])
		{
			j = 0;
			while (matrix[i][j])
			{
				if (matrix[i][j] == -1 && j != 1 
						&& (matrix[j][j] > 1 || j == 0))
					tab[j].wth = tab[i].wth + 1;
				else if (matrix[1][j] == -1 && j != 1 
						&& !(matrix[j][j] > 1 || j == 0))
					tab[j].wth = -1;
				j++;
			}
			i++;
		}
	}
	i = 0;
	printf("j = %d\n", j);
	while (tab[i].next)
	{
		printf("room[%d] : wth = %d\n", i, tab[i].wth);
		i++;
	}
//	printf("room[%d] : wth = %d\n", i, tab[i].wth);
}
