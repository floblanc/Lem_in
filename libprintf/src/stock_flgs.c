/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_flgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:46:48 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:03:55 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	stock_flgs(t_data *data, char *s, int *i, int j)
{
	while (ft_strsearch("hlLjz", s[*i]) && *i < j)
	{
		data->nb_flgs += 1;
		data->flgs = s[*i];
		*i += 1;
	}
}
