/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/20 10:42:30 by maginist         ###   ########.fr       */
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
	if (i < 1 || str[i] != ' ')
		return (0);
	i--;
	while (i >= 0 && (ft_isalnum(str[i]) || str[i] == '_'))
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
	while (i >= 0 && (ft_isalnum(str[i]) || str[i] == '_'))
		i--;
	if (i < 1 || str[i] != '-' || (str[i + 1] && str[i + 1] == 'L'))
		return (0);
	i--;
	while (i >= 0 && (ft_isalnum(str[i]) || str[i] == '_'))
		i--;
	if (i != -1)
		return (0);
	return (1);
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
	if (!(line[i]))
		return (0);
	while (line[i])
	{
		if (!(ft_isdigit(line[i])) && !(i == 0 && line[i] == '-'))
			return (0);
		i++;
	}
	if (ft_atol(line) > 2147483647 || ft_atol(line) < 1 || ft_strlen(line) > 11)
	{
		write(2, "Unvalid number of ants\nUsage : <int > 0>\n", 41);
		return (0);
	}
	return (1);
}
