/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/25 15:56:44 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_is_valid(char *str)
{
	int	i;

	i = 0;
	if (!(str))
		return (0);
	if (!(str[0] != 'L' && str[0] != '#' && ft_isprint(str[0]) && str[0] != ' ')
		return (0);
	while (ft_isprint(str[i]) && str[i] != ' ')
		i++;
	if (!(str[i]) || str[i] != ' ')
		return (0);
	i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!(str[i]) || str[i] != ' ' || !(ft_isdigit(str[i - 1])))
		return (0);
	i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!(str[i]) && ft_isdigit(str[i - 1]))
		return (1);
	return (0);
}
