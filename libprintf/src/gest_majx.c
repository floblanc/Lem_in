/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_majx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:02:03 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:56:55 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static void	add_diez(char *num, t_data *data)
{
	if (data->diez == 1 && !(num[data->size_aff - 1] == '0'
				&& data->size_aff == 1))
	{
		num[0] = '0';
		num[1] = 'X';
	}
}

void		gest_majx2(t_data *data, char *num)
{
	num = newstart_cleanbegin(num, data->size_aff, data);
	num = fillbegin(num, data);
	add_diez(num, data);
	if ((data->s)[data->symbol_pos - 1] == '.'
			|| ((data->s)[data->symbol_pos - 1] == '0'
				&& (data->s)[data->symbol_pos - 2] == '.'))
	{
		if (ft_atoi(num) == 0 && data->size_aff == 1)
		{
			num[0] = 0;
			data->size_aff--;
			data->tdc++;
		}
	}
	gest_allnum(num, data);
}

void		gest_majx(t_data *data, va_list ap)
{
	char	*num;

	if (data->nb_flgs == 0)
		num = butoa(va_arg(ap, int), "0123456789ABCDEF");
	else if ((data->nb_flgs == 2 && data->flgs == 'l') || data->flgs == 'j')
		num = bulltoa(va_arg(ap, long long), "0123456789ABCDEF");
	else if ((data->nb_flgs == 1 && data->flgs == 'l') || data->flgs == 'z')
		num = bultoa(va_arg(ap, long), "0123456789ABCDEF");
	else if (data->nb_flgs == 1 && data->flgs == 'h')
		num = bustoa((short)va_arg(ap, int), "0123456789ABCDEF");
	else
		num = buctoa((char)va_arg(ap, int), "0123456789ABCDEF");
	if (data->preci > 0 || data->moins == 1)
		data->zero = 0;
	data->size_aff = (int)ft_strlen(num);
	data->preci -= data->size_aff;
	if (data->diez == 1 && (!(num[0] == '0' && data->size_aff == 1)))
		data->size_aff += 2;
	if (data->preci >= 0)
		data->size_aff += data->preci;
	data->tdc -= data->size_aff;
	data->plus = 0;
	data->space = 0;
	gest_majx2(data, num);
}
