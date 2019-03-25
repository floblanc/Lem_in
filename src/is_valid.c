/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/25 20:09:59 by floblanc         ###   ########.fr       */
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
	while(i >= 0 && ft_isdigit(str[i]))
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

int		tube_form_is_valid(char *str)
{
	int	i;

	if (!(str && str[0]) || str[0] == 'L' || str[0] == '#')
		return (0);
	i = (int)(ft_strlen(str)) - 1;
	while (i >= 0  && ft_isalnum(str[i]))
		i--;
	if (i < 1 || str[i] != '-')
		return (0);
	i--;
	while (i >= 0  && ft_isalnum(str[i]))
		i--;
	if (i != -1)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", room_form_is_valid(av[1]));
	printf("%d\n", tube_form_is_valid(av[2]));
	return (0);
}
