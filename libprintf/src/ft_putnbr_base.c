/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:02:58 by maginist          #+#    #+#             */
/*   Updated: 2019/04/04 11:47:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

int		base_isvalide(char *base, int size)
{
	int				i;
	int				j;

	i = 0;
	if (size < 2)
		return (0);
	while (i < size)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int n, char *base)
{
	unsigned int	nb;
	unsigned int	base_size;

	base_size = (unsigned int)ft_strlen(base);
	nb = n;
	if (!(base_isvalide(base, base_size)))
		return ;
	if (nb < base_size)
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr_base((nb / base_size), base);
		ft_putchar(base[nb % base_size]);
	}
}
