/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:34 by maginist          #+#    #+#             */
/*   Updated: 2019/04/08 18:29:44 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	stock_to_write(char *line, t_write **begin)
{
	t_write	*new;
	t_write	*current;

	if (!(new = (t_write*)malloc(sizeof(t_write) * 1)))
		exit(0);
	new->str = ft_strdup(line);
	new->next = 0;
	if (!(*begin))
		*begin = new;
	else if (new)
	{
		current = *begin;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	write_data(t_write **begin)
{
	t_write	*current;

	if (!(begin && *begin))
		return ;
	current = *begin;
	while (current)
	{
		ft_putendl(current->str);
		current = current->next;
	}
	free_lst_write(begin);
}

void	use_path(t_path *struc, t_room *tab, int path_n, int ant)
{
	int	i;

	i = ant % path_n;
	ant++;
	while (i < path_n && struc->path[i][struc->len[i]] == 0)
		i++;
	while ()
	{
		if (i % path_n != path_n - 1)
			ft_printf("L%d-%s ", ant, tab[struc->path[i]].name);
		else
			ft_printf("L%d-%s\n", ant, tab[struc->path[i]].name);
	}
}
