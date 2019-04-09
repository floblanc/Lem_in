/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:04:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static unsigned long int	ft_size(unsigned long int n)
{
	unsigned long int	i;

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

char						*ultoa(unsigned long int n)
{
	unsigned long int	i;
	char				*str;

	i = ft_size(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[i] = (n % 10) + '0';
	return (str);
}
