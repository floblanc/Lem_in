/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/28 17:00:38 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	try_swap_t_path(t_path **another_new, t_path **new, t_room *tab)
{
	t_path	*tmp;
	int		new_som;
	int		ano_som;
	int		i;

	//printf("OTHER WAY FOUND\n");
	new_som = 0;
	ano_som = 0;
	i = 0;
	while (i < (*new)->path_n)
	{
		//		printf("new-len[%d] = %d et anothernew->len[%d] = %d\n",i,(*new)->len[i],i,(*another_new)->len[i]);
		new_som += (*new)->len[i];
		ano_som += (*another_new)->len[i];
		i++;
	}
	if (ano_som && ano_som < new_som)
	{
		//	printf("le nouveau est mieux\n");
		tmp = *another_new;
		*another_new = *new;
		*new = tmp;
	}
	else
	{
		i = 0;
		new_som = 0;
		while (i < (*new)->path_n)
		{
			new_som = 0;
			while ((*another_new)->path[i][new_som] != 1)
				tab[(*another_new)->path[i][new_som++]].taken = 0;
			new_som = 0;
			while ((*new)->path[i][new_som] != 1)
				tab[(*new)->path[i][new_som++]].taken = i + 1;
			i++;
		}
	}
}

void	clean_some_taken(t_room *tab, int size, int symb)
{
	int	i;

	i = 1;
	if (symb >= 0)
	{
		while (i < size)
		{
			if (tab[i].taken > 0)
				tab[i].taken = 0;
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			if (tab[i].taken < 0)
				tab[i].taken = 0;
			i++;
		}
	}
}

int		calc_size(t_room *tab)
{
	int		size;

	size = 0;
	while (tab[size].next)
		size++;
	size++;
	return (size);
}

int		enougth_room_for_more(t_path *best, t_room *tab)
{
	int	i;
	int	size;
	int	len_som;

	if (!(best))
		return (1);
	i = 0;
	len_som = 0;
	size = calc_size(tab);
	while (i < best->path_n)
		len_som += best->len[i++];
	return (((size - len_som > best->len[best->path_n - 1]) ? 1 : 0));
}

void	copy_best(t_path *best, t_path *new, int size, t_room *tab)
{
	int	i;
	int	j;

	i = 0;
	(void)size;
	if (!(best))
		return ;
	while (i < best->path_n && best->len[i] > 0)
	{
		new->len[i] = best->len[i];
		j = 0;
		while (j < best->len[i])
		{
			new->path[i][j] = best->path[i][j];
			tab[new->path[i][j]].taken = i + 1;
			j++;
		}
		new->path[i][best->len[i]] = 0;
		i++;
	}
}
