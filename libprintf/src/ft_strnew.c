/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:06:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:53:39 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strnew(size_t size)
{
	char			*mem;
	unsigned int	i;

	i = 0;
	if (!(mem = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size + 1)
		mem[i++] = 0;
	return (mem);
}
