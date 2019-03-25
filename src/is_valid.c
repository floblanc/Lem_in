/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/25 18:48:05 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_is_valid(char *str)
{
	int	i;

	if (!(str) || str[0] == 'L' || str[0] == '#')
		return (0);
	i = (int)(ft_strlen(str)) - 1;
	while (i >= 0 && ft_isdigit(str[i]))
		i--;
	if (i >= 0 && (str[i] == '+' || str[i] == '-'))
		i--;
	if (i < 3 || str[i] != ' ' || !(ft_isdigit(str[i - 1])))
		return (0);
	i--;
	while(i >= 0 && ft_isdigit(str[i]))
		i--;
	if (i >= 0 && (str[i] == '+' || str[i] == '-'))
		i--;
	if (i < 1 || str[i] != ' ' || !(ft_isprint(str[i - 1])))
		return (0);
	while (i >= 0 && ft_isprint(str[i]))
		i--;
	if (i != -1)
		return (0);
	return (1);
}
