/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:47:17 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:02:21 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	init_struct(t_data *data, char *s, int pos_sym)
{
	data->diez = 0;
	data->space = 0;
	data->plus = 0;
	data->moins = 0;
	data->zero = 0;
	data->tdc = 0;
	data->pt = 0;
	data->preci = -1;
	data->nb_flgs = 0;
	data->flgs = 0;
	data->size_aff = 0;
	data->symbol_pos = pos_sym;
	data->symbol = s[pos_sym];
	data->s = s;
}
