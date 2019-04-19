/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:08:54 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/19 12:08:24 by floblanc         ###   ########.fr       */
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

void	free_lst_write(t_write **begin)
{
	t_write	*current;
	t_write	*before;

	current = 0;
	before = 0;
	if (begin && *begin)
	{
		before = *begin;
		current = before->next;
		*begin = 0;
		before->next = 0;
		ft_strdel(&(before->str));
		free(before);
		while (current)
		{
			before = current;
			current = current->next;
			before->next = 0;
			ft_strdel(&(before->str));
			free(before);
			before = 0;
		}
	}
}

void	free_room_tab(t_room **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&((*tab)[i].name));
		i++;
	}
	free(*tab);
	*tab = 0;
}

void	free_matrix(int ***matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free((*matrix)[i++]);
	free(*matrix);
	*matrix = 0;
}

void	free_paths(t_path **begin)
{
	int		i;
	int		j;
	t_path	*before;

	if (!(begin && *begin))
		return ;
	i = 1;
	while (*begin)
	{
		before = *begin;
		j = 0;
		while (j < i)
			free((*begin)->path[j++]);
		free((*begin)->len);
		i++;
		*begin = (*begin)->next;
		free(before);
		before = 0;
	}
}
