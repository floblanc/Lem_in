/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:17:23 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:52:09 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dest_size;
	unsigned int	j;

	dest_size = ft_strlen(dst);
	j = 0;
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[j] && dest_size + j < size - 1)
	{
		dst[dest_size + j] = src[j];
		j++;
	}
	dst[dest_size + j] = '\0';
	return (ft_strlen(src) + dest_size);
}
