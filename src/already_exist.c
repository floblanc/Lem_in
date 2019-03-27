/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:56:06 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/27 14:29:46 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	room_already_exist(t_room **begin, t_room *new)
{
	t_room *current;

	if (!(begin && *begin))
		return (0);
	current = *begin;
	while (current)
	{
		if (!(ft_strcmp(current->name, new->name)))
			return (1);
		else if (current->x == new->x && current->y == new->y)
			return (1);
		else if (new->startend != 0 && new->startend == current->startend)
			return (1);
		current = current->next;
	}
	return (0);
}

int	link_already_exist(t_link **begin, t_link *new)
{
	t_link *current;

	if (!(begin && *begin))
		return (0);
	current = *begin;
	while (current)
	{
		if (!(ft_strcmp(current->name1, new->name1))
				&& !(ft_strcmp(current->name2, new->name2)))
			return (1);
		if (!(ft_strcmp(current->name2, new->name1))
				&& !(ft_strcmp(current->name1, new->name2)))
			return (1);
		current = current->next;
	}
	return (0);
}
