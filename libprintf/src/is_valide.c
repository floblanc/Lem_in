/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:04:33 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:02:29 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

int		is_valide2(char *s, int i)
{
	if (s[i] == 'l')
	{
		i++;
		if (s[i] == 'l')
			i++;
	}
	else if (s[i] == 'L' || s[i] == 'j' || s[i] == 'z')
		i++;
	else if (s[i] == 'h')
	{
		i++;
		if (s[i] == 'h')
			i++;
	}
	return (i);
}

int		is_valide(char *s, int i)
{
	while (ft_strsearch("#+- 0", s[i]))
		i++;
	while (ft_isdigit(s[i]) || s[i] == '*')
		i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]) || s[i] == '*')
		i++;
	if (ft_strsearch("cs", s[i]))
		return (i);
	i = is_valide2(s, i);
	if (ft_strsearch("pdiouxXbrDOU%", s[i]) && s[i - 1] != 'L')
		return (i);
	else if (s[i] == 'f' || s[i] == 'F')
		if (!(ft_strsearch("hjz", s[i - 1])))
			return (i);
	return ((s[i] == '%') ? i : 0);
}
