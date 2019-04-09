/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:26:07 by maginist          #+#    #+#             */
/*   Updated: 2019/04/04 11:38:13 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

int	analyse(char *s, int *i, int j, va_list ap)
{
	t_data	data;

	init_struct(&data, s, j);
	i[0]++;
	add_pre_flgs(&data, s, &i[0], j);
	data.tdc = stock_digit(s, &i[0], j, ap);
	if (data.tdc < 0)
	{
		data.tdc *= -1;
		data.moins = 1;
	}
	if (s[i[0]] == '.')
	{
		i[0]++;
		data.pt = 1;
		data.preci = stock_digit(s, &i[0], j, ap);
	}
	stock_flgs(&data, s, &i[0], j);
	redirection(&data, ap);
	if (data.tdc < 0)
		data.tdc = 0;
	i[1] = data.size_aff + data.tdc;
	return (*i);
}
