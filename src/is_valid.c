/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/27 14:10:53 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_form_is_valid(char *str)
{
	int	i;

	if (!(str && str[0]) || str[0] == 'L' || str[0] == '#')
		return (0);
	i = (int)(ft_strlen(str)) - 1;
	while (i >= 0 && ft_isdigit(str[i]))
		i--;
	if (i >= 0 && (str[i] == '+' || str[i] == '-'))
		i--;
	if (i < 3 || str[i] != ' ' || !(ft_isdigit(str[i - 1])))
		return (0);
	i--;
	while (i >= 0 && ft_isdigit(str[i]))
		i--;
	if (i >= 0 && (str[i] == '+' || str[i] == '-'))
		i--;
	if (i < 1 || str[i] != ' ' || !(ft_isalnum(str[i - 1])))
		return (0);
	i--;
	while (i >= 0 && ft_isalnum(str[i]))
		i--;
	if (i != -1)
		return (0);
	return (1);
}

int		link_form_is_valid(char *str)
{
	int	i;

	if (!(str && str[0]) || str[0] == 'L' || str[0] == '#')
		return (0);
	i = (int)(ft_strlen(str)) - 1;
	while (i >= 0 && ft_isalnum(str[i]))
		i--;
	if (i < 1 || str[i] != '-' || (str[i + 1] && str[i + 1] == 'L'))
		return (0);
	i--;
	while (i >= 0 && ft_isalnum(str[i]))
		i--;
	if (i != -1)
		return (0);
	return (1);
}

int		link_is_valid(t_link *new, t_room **begin)
{
	t_room	*current;
	int		name1;
	int		name2;

	name1 = 0;
	name2 = 0;
	if (!(begin && *begin && (*begin)->next))
		return (0);
	current = *begin;
	while (current && (name1 == 0 || name2 == 0))
	{
		if (!(ft_strcmp(new->name1, current->name)))
			name1 = 1;
		else if (!(ft_strcmp(new->name2, current->name)))
			name2 = 1;
		current = current->next;
	}
	if (name1 == 1 && name2 == 1)
		return (1);
	return (0);
}

int		command_is_valid(char *str)
{
	if (!(ft_strcmp("##start", str)) || !(ft_strcmp("##end", str)))
		return (1);
	return (0);
}

int		valid_digit(char *line)
{
	int	i;

	i = 0;
	if (ft_atol(line) > 2147483647 || ft_atol(line) < 0 || ft_strlen(line) > 11)
	{
		write(2, "Unvalid number of ants\nUsage : <positive int>\n", 46);
		return (0);
	}
	while (line[i])
	{
		if (!(ft_isdigit(line[i])))
			return (0);
		i++;
	}
	return (1);
}
