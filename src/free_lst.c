/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:08:54 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 19:00:58 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_lst_room(t_room **begin)
{
	t_room	*current;
	t_room	*before;

	current = 0;
	before = 0;
	if (begin && *begin)
	{
		before = *begin;
		current = before->next;
		*begin = 0;
		before->next = 0;
		ft_strdel(&(before->name));
		free(before);
		while (current)
		{
			before = current;
			current = current->next;
			before->next = 0;
			ft_strdel(&(before->name));
			free(before);
			before = 0;
		}
	}
}

void	free_lst_link(t_link **begin)
{
	t_link	*current;
	t_link	*before;

	current = 0;
	before = 0;
	if (begin && *begin)
	{
		before = *begin;
		current = before->next;
		*begin = 0;
		before->next = 0;
		ft_strdel(&(before->name1));
		ft_strdel(&(before->name2));
		free(before);
		while (current)
		{
			before = current;
			current = current->next;
			before->next = 0;
			ft_strdel(&(before->name1));
			ft_strdel(&(before->name2));
			free(before);
			before = 0;
		}
	}
}
