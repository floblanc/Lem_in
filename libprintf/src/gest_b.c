/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:02:03 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:56:18 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	gest_b2(t_data *data, char *num)
{
	if ((data->s)[data->symbol_pos - 1] == '.')
	{
		if (num[0] == '-' && num[1] == '0')
			num[1] = 0;
		else if (num[0] == '0')
			num[0] = 0;
		data->size_aff--;
		data->tdc++;
	}
}

void	gest_b(t_data *data, va_list ap)
{
	char	*num;

	if (data->nb_flgs == 0)
		num = butoa(va_arg(ap, int), "01");
	else if ((data->nb_flgs == 2 && data->flgs == 'l') || data->flgs == 'j')
		num = bulltoa(va_arg(ap, long long), "01");
	else if ((data->nb_flgs == 1 && data->flgs == 'l') || data->flgs == 'z')
		num = bultoa(va_arg(ap, long), "01");
	else if (data->nb_flgs == 1 && data->flgs == 'h')
		num = bustoa((short)va_arg(ap, int), "01");
	else
		num = buctoa((char)va_arg(ap, int), "01");
	if (data->preci > 0 || data->moins == 1)
		data->zero = 0;
	data->size_aff = (int)ft_strlen(num);
	data->preci -= data->size_aff;
	if (data->preci > 0)
		data->size_aff += data->preci;
	data->tdc = data->tdc - data->size_aff;
	data->plus = 0;
	data->space = 0;
	num = newstart_cleanbegin(num, data->size_aff, data);
	num = fillbegin(num, data);
	gest_b2(data, num);
	gest_allnum(num, data);
}
