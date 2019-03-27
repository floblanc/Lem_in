/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:21:10 by floblanc          #+#    #+#             */
/*   Updated: 2018/11/14 13:34:55 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	unsigned int	i;

	i = 0;
	if (!(mem = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (0);
	while (i < size)
		mem[i++] = 0;
	return (mem);
}
