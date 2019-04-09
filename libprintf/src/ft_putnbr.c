/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:54:29 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:47:10 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -n;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr((nb / 10));
		ft_putchar((nb % 10) + '0');
	}
}
