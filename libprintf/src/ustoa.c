/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ustoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:04:39 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static int	ft_size(unsigned short int n)
{
	unsigned short int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ustoa(unsigned short int n)
{
	int		i;
	char	*str;

	i = ft_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
