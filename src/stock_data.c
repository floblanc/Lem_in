/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:36:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 12:49:39 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		stock_room(char *line, t_room **begin, int *startend, int *error)
{
	t_stock	*new;
	t_stock	*current;

	if (!(new = (t_room*)malloc(sizeof(t_room) * 1)))
		exit(0);
	new->name = extract_room_name(line);
	new->x = extract_room_x(line);
	new->y = extract_room_y(line);
	new->start = *start;
	new->end = *end;
	new->next = 0;
	//verif not already exist
	if (!(*begin))
		*begin = new;
	else
	{
		current = *begin;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void		read_n_stock(t_room **roombeg, t_link **linkbeg)
{
	char	*line;
	int		startend;
	int		error;

	line = 0;
	startend = 0;
	error = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (room_form_is_valid(line, linkbeg))
			stock_room(line, roombeg, &startend, &error);
		else if (link_form_is_valid(line))
			stock_link(line, linkbeg, &startend, &error);
		else if (command_is_valid(line, linkbeg))
			check_command(line, &startend, &error);
		else if (line[0] != '#')
			error = 1;
		ft_strdel(&line);
		if (error)
			break ;
	}
}
