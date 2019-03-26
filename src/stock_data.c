/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:36:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 19:57:46 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		stock_room(char *line, t_room **begin, int *startend, int *error)
{
	t_room	*new;
	t_room	*current;

	if (!(new = (t_room*)malloc(sizeof(t_room) * 1)))
		exit(0);
	new->name = extract_room_name(line);
	new->x = extract_room_x(line);
	new->y = extract_room_y(line);
	new->startend = *startend;
	*startend = 0;
	new->next = 0;
	if (room_already_exist(begin, new))
	{
		free_lst_room(&new);
		*error = 1;
	}
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

void		new_link_maker(t_link *new, char *line, int i)
{
	new->name1 = ft_strndup(line, (size_t)i);
	new->name2 = ft_strdup(line + i + 1);
	new->next = 0;
}

void		stock_link(char *line, t_link **begin, t_room **roombeg, int *error)
{
	t_link	*new;
	t_link	*current;
	int	i;

	i = 0;
	while (ft_isalnum(line[i]))
		i++;
	if (!(new = (t_link*)malloc(sizeof(t_link) * 1)))
		exit(0);
	new_link_maker(new, line, i);
	if (!(link_is_valid(new, roombeg)) || link_already_exist(begin, new))
	{
		free_lst_link(&new);
		*error = 1;
	}
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

void		read_n_stock(int *ant_n, t_room **roombeg, t_link **linkbeg)
{
	char	*line;
	int		startend;
	int		error;

	line = 0;
	startend = 0;
	error = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (only_digit(line) && (*ant_n < 0) && !(*roombeg) && !(*linkbeg))
			*ant_n = ft_atoi(line);
		else if (room_form_is_valid(line) && !(*linkbeg) && (*ant_n > -1))
			stock_room(line, roombeg, &startend, &error);
		else if (link_form_is_valid(line) && (*ant_n > - 1))
			stock_link(line, linkbeg, &error, 0);
		else if (command_is_valid(line) && !(*linkbeg) && (*ant_n > -1))
			check_command(line, &startend, &error);
		else if (line[0] != '#' || line[1] == '#')
			error = 1;
		ft_strdel(&line);
		if (error)
			break ;
	}
}
