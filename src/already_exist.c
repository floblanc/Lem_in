/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:56:06 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/18 15:25:49 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_already_exist(t_room **begin, t_room *new, t_room **end)
{
	t_room	*current;

	if (!(begin && *begin))
		return (0);
	current = *begin;
	while (current)
	{
		if (current->next == 0)
			*end = current;
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

int		ft_lstlen(t_room **begin)
{
	int		size;
	t_room	*current;

	size = 0;
	if (*begin)
	{
		current = *begin;
		while (current)
		{
			size++;
			current = current->next;
		}
	}
	return (size);
}

int		check_startend(t_room **begin)
{
	int		start;
	int		end;
	t_room	*current;

	start = 0;
	end = 0;
	if (!(begin && *begin && (*begin)->next))
		return (0);
	current = *begin;
	while (current)
	{
		if (current->startend == 1)
			start++;
		else if (current->startend == 2)
			end++;
		current = current->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (0);
}
