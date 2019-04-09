/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:03:36 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static short int	ft_size(short int n)
{
	short int	i;

	i = 0;
	if (n == 0 || n < 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*stoa(short int n)
{
	short int	i;
	short int	neg;
	char		*str;

	i = ft_size(n);
	if (n < 0)
		neg = -1;
	else
		neg = 1;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (i == 0 && neg == -1)
			str[i] = '-';
		else
			str[i] = ((n % 10) * neg) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
