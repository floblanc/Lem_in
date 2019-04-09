/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newstart_cleanbegin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 23:32:09 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:02:52 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*newstart_cleanbegin(char *num, int size, t_data *data)
{
	char	*tmp;
	int		numax;
	int		i;

	if (data->tdc > 0 && data->zero == 1 && data->preci <= 0
		&& data->moins == 0)
		size += data->tdc;
	if (!(tmp = ft_strnew(size)))
		return (0);
	numax = ft_strlen(num);
	i = 1;
	while (numax - i >= 0 && num[numax - i] != '-')
	{
		tmp[size - i] = num[numax - i];
		i++;
	}
	if (num[0] == '-')
		tmp[0] = '-';
	free(num);
	return (tmp);
}
