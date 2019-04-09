/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:20:15 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:48:03 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}
