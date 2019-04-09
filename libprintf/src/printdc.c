/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:50 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:03:02 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	printdc(int tdc)
{
	int		i;
	char	str[tdc];

	str[tdc] = '\0';
	i = 0;
	while (i < tdc)
	{
		str[i] = ' ';
		i++;
	}
	write(1, str, (size_t)tdc);
}
