/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bustoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:39:53 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static unsigned short		ft_size(unsigned short n, unsigned short size)
{
	unsigned short		i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= size;
		i++;
	}
	return (i);
}

char						*bustoa(unsigned short n, char *base)
{
	unsigned short		i;
	char				*str;
	unsigned short		size;

	size = ft_strlen(base);
	i = ft_size(n, size);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		str[i] = base[(n % size)];
		n /= size;
		i--;
	}
	str[i] = base[(n % size)];
	return (str);
}
