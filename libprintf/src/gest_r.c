/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:19:21 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:57:50 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	gest_r2(char *stock, int *i)
{
	write(1, "\\", 1);
	if (ft_strlen(butoa(stock[*i], "0123456789abcdef")) < 2)
		write(1, "0", 1);
	ft_putstr(butoa(stock[(*i)++], "0123456789abcdef"));
}

void	gest_r(t_data *data, va_list ap)
{
	char	*stock;
	int		i;

	i = 0;
	if (!(stock = va_arg(ap, char*)))
		stock = "(null)";
	if (data->preci < (int)ft_strlen(stock) && data->preci > 0)
		data->size_aff = data->preci;
	else
		data->size_aff = ft_strlen(stock);
	data->tdc = data->tdc - data->size_aff;
	if (data->moins == 0 && data->tdc > 0)
		printdc(data->tdc);
	while (i < data->size_aff)
	{
		if (stock[i] >= ' ' && stock[i] <= 126)
			write(1, &stock[i++], 1);
		else
			gest_r2(stock, &i);
	}
	if (data->moins == 1 && data->tdc > 0)
		printdc(data->tdc);
}
