/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:43:52 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:53:20 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	while (s[i] && i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
