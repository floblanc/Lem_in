/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:26:20 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:56:27 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	gest_c(t_data *data, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	data->size_aff = 1;
	data->tdc--;
	if (data->zero && data->moins == 0 && data->tdc > 0)
		printpreci(data->tdc);
	else if (data->moins == 0 && data->tdc > 0)
		printdc(data->tdc);
	write(1, &c, 1);
	if (data->moins == 1 && data->tdc > 0)
		printdc(data->tdc);
}
