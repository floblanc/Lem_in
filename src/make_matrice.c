/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:16:42 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/28 19:01:26 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	rooms_in_tab(t_room **tab, t_room **begin)
{
	t_room	*current;
	int		i;

	if (!(begin && *begin))
		return ;
	current = *begin;
	i = 0;
	while (current)
	{
		(*tab)[i] = *current;
		current = current->next;
		i++;
	}
	order_tabroom(tab);
}
void	order_tabroom(t_room **tab)
{
	t_room	tmp;
	int	i;

	i = 0;
	while ((*tab)[i]->startend != 1)
		i++;
	tmp = (*tab)[0];
	(*tab)[0] = (*tab)[i];
	(*tab)[0]->next = (*tab)[i]->next;
	(*tab)[i] = tmp;
	(*tab)[i]->next = tmp->next;
	i = 0;
	while ((*tab)[i]->startend != 2)
		i++;
	tmp = (*tab)[1];
	(*tab)[1] = (*tab)[i];
	(*tab)[1]->next = (*tab)[i]->next;
	(*tab)[i] = tmp;
	(*tab)[i]->next = tmp->next;
}
