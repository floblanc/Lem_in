/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:19:34 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/27 11:52:30 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*extract_room_name(char *str)
{
	char	*name;
	int		i;

	name = 0;
	i = 0;
	if (!(str))
		return (0);
	while (ft_isalnum(str[i]))
		i++;
	if (!(name = ft_strndup(str, (size_t)i)))
		exit(0);
	return (name);
}

int		extract_room_x(char *str)
{
	int		x;
	char	*x_str;
	size_t	i;
	size_t	len;

	x = 0;
	i = 0;
	len = 0;
	while (ft_isalnum(str[i]))
		i++;
	i++;
	while (ft_isdigit(str[i + len]) || str[i + len] == '+'
			|| str[i + len] == '-')
		len++;
	if (!(x_str = ft_strndup(str + i, (size_t)len)))
		exit(0);
	x = ft_atoi(x_str);
	free(x_str);
	return (x);
}

int		extract_room_y(char *str)
{
	int		y;
	char	*y_str;
	size_t	i;
	size_t	len;

	y = 0;
	i = 0;
	len = 0;
	while (ft_isalnum(str[i]))
		i++;
	i++;
	while (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
		i++;
	i++;
	while (ft_isdigit(str[i + len]) || str[i + len] == '+'
			|| str[i + len] == '-')
		len++;
	if (!(y_str = ft_strndup(str + i, (size_t)len)))
		exit(0);
	y = ft_atoi(y_str);
	free(y_str);
	return (y);
}
