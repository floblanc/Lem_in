/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:36:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/29 13:28:40 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	stock_room(char *line, t_room **begin, int *startend, int *error)
{
	t_room	*new;
	t_room	*current;

	if (!(new = (t_room*)malloc(sizeof(t_room) * 1)))
		exit(0);
	new->name = extract_room_name(line);
	new->x = extract_room_x(line, error);
	new->y = extract_room_y(line, error);
	new->startend = *startend;
	*startend = 0;
	new->next = 0;
	if (room_already_exist(begin, new) || *error == 1)
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

void	new_link_maker(t_link *new, char *line, int i)
{
	new->name1 = ft_strndup(line, (size_t)i);
	new->name2 = ft_strdup(line + i + 1);
	new->next = 0;
}

void	stock_link(char *line, t_link **begin, t_room **roombeg, int *error)
{
	t_link	*new;
	t_link	*current;
	int		i;

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

void	set_startend(char *line, int *startend, int *error)
{
	if (!(ft_strcmp("##start", line)) && *startend == 0)
		*startend = 1;
	else if (!(ft_strcmp("##end", line)) && *startend == 0)
		*startend = 2;
	else
		*error = 1;
}

void	read_n_stock(int *ant_n, t_room **room, t_link **link, t_write **str)
{
	char	*line;
	int		startend;
	int		error;

	line = 0;
	startend = 0;
	error = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (valid_digit(line) && (*ant_n <= 0) && !(*room) && !(*link))
			*ant_n = ft_atoi(line);
		else if (room_form_is_valid(line) && !(*link) && (*ant_n > 0))
			stock_room(line, room, &startend, &error);
		else if (link_form_is_valid(line) && (*ant_n > 0) && startend == 0)
			stock_link(line, link, room, &error);
		else if (command_is_valid(line) && !(*link) && (*ant_n > 0))
			set_startend(line, &startend, &error);
		else if (line[0] != '#')
			error = 1;
		if (error)
			break ;
		stock_to_right(line, str);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
