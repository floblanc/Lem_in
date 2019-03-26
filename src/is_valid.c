/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:11 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 12:00:26 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_form_is_valid(char *str, t_link **begin)
{
	int	i;

	if (!(str && str[0]) || str[0] == 'L' || str[0] == '#' || *begin)
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

int		link_form_is_valid(char *str)
{
	int	i;

	if (!(str && str[0]) || str[0] == 'L' || str[0] == '#')
		return (0);
	i = (int)(ft_strlen(str)) - 1;
	while (i >= 0  && ft_isalnum(str[i]))
		i--;
	if (i < 1 || str[i] != '-' || (str[i + 1] && str[i + 1] == 'L'))
		return (0);
	i--;
	while (i >= 0  && ft_isalnum(str[i]))
		i--;
	if (i != -1)
		return (0);
	return (1);
}

int		command_is_valid(char *str, t_link **begin)
{
	if (!(str) || !(str[0] == '#' && str[1] == '#') || *begin)
		return (0);
	if (!(ft_strcmp("start", str + 2)) || !(ft_strcmp("end", str + 2)))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_link *begin;
	t_link	test;

	begin = 0;
	if (av[4])
		begin = &test;
	(void)ac;
	printf("%d\n", room_form_is_valid(av[1], &begin));
	printf("%d\n", link_form_is_valid(av[2]));
	printf("%d\n", command_is_valid(av[3], &begin));
	return (0);
}
