/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 22:16:44 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:57:15 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	gest_p2(t_data *data, int preci)
{
	if (preci > 0)
		data->size_aff += preci;
	data->size_aff += 2;
}

void	gest_p(t_data *data, va_list ap)
{
	unsigned long int	ptr;
	char				*str;
	int					preci;

	ptr = va_arg(ap, unsigned long int);
	str = bultoa(ptr, "0123456789abcdef");
	data->size_aff = ft_strlen(str);
	preci = data->preci - data->size_aff;
	data->tdc -= data->size_aff + 2;
	if (data->zero == 0 && data->moins == 0 && data->tdc > 0)
		printdc(data->tdc);
	write(1, "0x", 2);
	if (preci > 0)
		printpreci(preci);
	if (!(data->preci == 0 && data->size_aff == 1 && str[0] == '0'))
		write(1, str, data->size_aff);
	else if (data->size_aff == 1 && str[0] == '0')
		data->size_aff--;
	free(str);
	if (data->zero && data->tdc > 0 && data->moins == 0)
		printpreci(data->tdc);
	else if (data->moins == 1 && data->tdc > 0)
		printdc(data->tdc);
	gest_p2(data, preci);
}
