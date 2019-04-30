/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:14:33 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/30 17:18:33 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_tab(t_room **tab, int i, t_room *current)
{
	(*tab)[i].name = ft_strdup(current->name);
	(*tab)[i].x = current->x;
	(*tab)[i].y = current->y;
	(*tab)[i].startend = current->startend;
	(*tab)[i].wth = 0;
	(*tab)[i].taken = 0;
	(*tab)[i].used = 0;
	(*tab)[i].next = current->next;
}
