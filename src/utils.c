/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:56:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/09 19:12:53 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

	if (!(*best))
		return (1);
	i = 0;
	len_som = 0;
	size = calc_size(tab);
	while (i < best->path_n)
		len_som += best->len[i++];
	return (((size - len_som > best->len[best->path_n - 1]) ? 1 : 0));
}
