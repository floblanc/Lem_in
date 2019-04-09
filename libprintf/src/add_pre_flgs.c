/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pre_flgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:00:04 by maginist          #+#    #+#             */
/*   Updated: 2019/04/04 11:35:43 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	add_pre_flgs(t_data *data, char *s, int *i, int j)
{
	while (ft_strsearch("#+- 0)", s[*i]) && *i < j)
	{
		if (s[*i] == '#')
			data->diez = 1;
		else if (s[*i] == '+')
			data->plus = 1;
		else if (s[*i] == '-')
			data->moins = 1;
		else if (s[*i] == ' ')
			data->space = 1;
		else if (s[*i] == '0')
			data->zero = 1;
		*i = *i + 1;
	}
}
