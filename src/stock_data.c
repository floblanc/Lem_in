/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:36:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/14 12:12:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	stock_room(char *line, t_room **begin, int *startend, int *error)
{
	t_room	*new;
	t_room	*end;

	if (!(new = (t_room*)malloc(sizeof(t_room) * 1)))
		exit(0);
	new->name = extract_room_name(line);
	new->x = extract_room_x(line, error);
	new->y = extract_room_y(line, error);
	new->startend = *startend;
	*startend = 0;
	new->next = 0;
	if (room_already_exist(begin, new, &end) || *error == 1)
	{
		free_lst_room(&new);
		*error = 1;
	}
	else if (!(*begin))
		*begin = new;
	else
		end->next = new;
}

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

void	save_line(char *line, int *error, t_write **str)
{
	stock_to_write(line, str);
	*error = 1;
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

void	read_n_stock(int *ant_n, t_room **room, t_write **str)
{
	char	*line;
	int		startend;
	int		error;

	line = 0;
	startend = 0;
	error = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (valid_digit(line) && (*ant_n <= 0) && !(*room))
			*ant_n = ft_atoi(line);
		else if (room_form_is_valid(line) && (*ant_n > 0))
			stock_room(line, room, &startend, &error);
		else if (link_form_is_valid(line) && (*ant_n > 0) && startend == 0)
			save_line(line, &error, str);
		else if (command_is_valid(line) && (*ant_n > 0))
			set_startend(line, &startend, &error);
		else if (line[0] != '#')
			error = 1;
		if (error)
			break ;
		stock_to_write(line, str);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
