/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:19:27 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:44:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char*)dst)[len - i - 1] = ((unsigned char*)src)[len - i
				- 1];
			i++;
		}
	}
	return (dst);
}
