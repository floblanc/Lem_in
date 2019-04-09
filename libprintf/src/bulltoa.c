/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:39:27 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static unsigned long long	ft_size(unsigned long long int n, unsigned int size)
{
	unsigned long long		i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= (unsigned long long)size;
		i++;
	}
	return (i);
}

char						*bulltoa(unsigned long long int n, char *base)
{
	unsigned long long		i;
	char					*str;
	unsigned int			size;

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
