/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:02:03 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:56:35 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	gest_di2(t_data *data, char *num)
{
	num = newstart_cleanbegin(num, data->size_aff, data);
	num = fillbegin(num, data);
	if ((data->s)[data->symbol_pos - 1] == '.'
			|| ((data->s)[data->symbol_pos - 1] == '0'
				&& (data->s)[data->symbol_pos - 2] == '.'))
	{
		if (ft_strsearch("-+ ", num[0]) && num[1] == '0')
			num[1] = 0;
		else if (num[0] == '0')
		{
			num[0] = 0;
			data->size_aff--;
		}
		data->tdc++;
	}
	gest_allnum(num, data);
}

void	gest_di(t_data *data, va_list ap)
{
	char	*num;

	if (data->nb_flgs == 0)
		num = ft_itoa(va_arg(ap, int));
	else if ((data->nb_flgs == 2 && data->flgs == 'l') || data->flgs == 'j')
		num = lltoa(va_arg(ap, long long));
	else if ((data->nb_flgs == 1 && data->flgs == 'l') || data->flgs == 'z')
		num = ltoa(va_arg(ap, long));
	else if (data->nb_flgs == 1 && data->flgs == 'h')
		num = stoa((short)va_arg(ap, int));
	else
		num = ctoa((char)va_arg(ap, int));
	if (data->preci > 0 || data->moins == 1)
		data->zero = 0;
	data->size_aff = (int)ft_strlen(num);
	if (num[0] == '-')
		data->preci -= (data->size_aff - 1);
	else
		data->preci -= data->size_aff;
	if (data->preci > 0)
		data->size_aff += data->preci;
	if ((data->plus == 1 || data->space == 1) && num[0] != '-')
		data->size_aff += 1;
	data->tdc -= data->size_aff;
	gest_di2(data, num);
}
