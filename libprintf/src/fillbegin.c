/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillbegin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 23:55:44 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:40:17 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*fillbegin(char *num, t_data *data)
{
	int	i;

	i = 1;
	if (num[0] != '-')
	{
		if (data->plus == 1)
			num[0] = '+';
		else if (data->space == 1)
			num[0] = ' ';
		else
			i--;
	}
	while (num[i] == 0)
	{
		num[i++] = '0';
		if (data->preci <= 0 && data->zero == 1 && data->tdc > 0)
		{
			data->tdc--;
			data->size_aff++;
		}
	}
	return (num);
}
