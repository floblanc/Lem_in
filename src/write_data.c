/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:34 by maginist          #+#    #+#             */
/*   Updated: 2019/03/30 14:37:58 by floblanc         ###   ########.fr       */
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
		ft_putstr(current->str);
		ft_putchar('\n');
		current= current->next;
	}
	free_lst_write(begin);
}	
