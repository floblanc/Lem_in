/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:56:00 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static int	ft_size(double n, int *save)
{
	int		i;
	double	nb;

	i = 0;
	if (n < 0)
		i = 1;
	if (n < 0)
		n = -n;
	nb = n - (unsigned long long int)n;
	if (n < 1)
		i++;
	while ((unsigned long long int)n > 0)
	{
		n /= 10;
		i++;
	}
	*save = i;
	if (nb != 0)
		i++;
	while (nb > 0)
	{
		nb = (nb * 10) - (int)(nb * 10);
		i++;
	}
	return (i);
}

static char	*put_in_str(char *str, double n, int i, int pos_pt)
{
	double	nb;

	if ((nb = n - (unsigned long long int)n))
		i = 0;
	while (pos_pt + i >= 0 && str[pos_pt + i] == 0)
	{
		if (i < 0)
		{
			str[pos_pt + i--] = ((unsigned long long int)n % 10) + '0';
			n /= 10;
		}
		else
		{
			if (i == 0)
				str[pos_pt + i++] = '.';
			else
			{
				str[pos_pt + i++] = (int)(nb * 10) + '0';
				nb = (nb * 10) - (int)(nb * 10);
				if (nb == 0)
					i = -1;
			}
		}
	}
	return (str);
}

char		*ftoa(double n)
{
	int		i;
	int		pos_pt;
	char	*str;
	int		run;

	run = -1;
	pos_pt = 0;
	i = ft_size(n, &pos_pt);
	if (!(str = ft_strnew(i)))
		return (0);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[i] = '\0';
	return (put_in_str(str, n, run, pos_pt));
}
