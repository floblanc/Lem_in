/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:41:45 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:43:46 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == ((unsigned char)c))
			return ((void*)(s + i));
		i++;
	}
	return (0);
}
